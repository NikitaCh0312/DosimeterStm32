#include "EthernetTask.h"
#include "Ethernet/Ethernet/socket.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"
#include "Ethernet/Internet/HttpServer/HttpServer.h"
#include "Ethernet/HtmlPage.h"
#include "string.h"

#define SOCKET_NUMBER   3
#define TCP_PORT        667


uint8_t receivedBuffer[1000];
uint32_t RxMessageSizeBytes = 0;

void EthernetTask::Execute()
{
    //�������� �������� �����
    for (uint32_t i = 0; i < sizeof(receivedBuffer); i++)
        receivedBuffer[i] = '\0';
    
    socket(SOCKET_NUMBER, Sn_MR_TCP, TCP_PORT, SF_TCP_NODELAY);
    
    int socketStatus = getSn_SR(SOCKET_NUMBER);
    while ( socketStatus != SOCK_INIT )
        socketStatus = getSn_SR(SOCKET_NUMBER);
    
    while(1)
    {
        //��������� ��������� ������
        socketStatus = getSn_SR(SOCKET_NUMBER);
        if (socketStatus == SOCK_INIT)
        {
            //������� ���� ������ �������������
            listen(SOCKET_NUMBER);
        }
        //���������� � �������� �����������
        else if (socketStatus == SOCK_ESTABLISHED)
        {
            //������ ���������(����������� ����� �������)
            recv(SOCKET_NUMBER, receivedBuffer, 1000);
            static st_http_request request;
            parse_http_request(&request, receivedBuffer);
            if (request.METHOD == METHOD_GET)
            {
                char response[500] = {'\0'};
                strcat(response, RES_HTMLHEAD_OK);
                strcat(response, HttpResponsePage);
                send(SOCKET_NUMBER, (uint8_t*)HttpResponsePage, strlen(HttpResponsePage));
            }
            else
                send(SOCKET_NUMBER, (uint8_t*)ERROR_REQUEST_PAGE, strlen(ERROR_REQUEST_PAGE));
            
            //�������� �������� �����
            for (uint32_t i = 0; i < sizeof(receivedBuffer); i++)
                receivedBuffer[i] = '\0';
            
        }
        else if (socketStatus == SOCK_CLOSE_WAIT)
        {
            disconnect(SOCKET_NUMBER);
        }
        //������ ����������
        else if (socketStatus == SOCK_CLOSED)
        {
            //��������� ������������ ������
            socket(SOCKET_NUMBER, Sn_MR_TCP, TCP_PORT, SF_TCP_NODELAY);
        }
    }
}