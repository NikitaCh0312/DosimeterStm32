#include "EthernetTask.h"
#include "Ethernet/Ethernet/socket.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"
#include "Ethernet/Internet/HttpServer/HttpServer.h"
#include "Ethernet/HtmlPage.h"
#include "string.h"
#include "stdio.h"

#define SOCKET_NUMBER   3
#define TCP_PORT        667




void EthernetTask::Execute()
{
    //обнуляем принятый буфер
    for (uint32_t i = 0; i < sizeof(receivedBuffer); i++)
        receivedBuffer[i] = '\0';
    
    socket(SOCKET_NUMBER, Sn_MR_TCP, TCP_PORT, SF_TCP_NODELAY);
    
    int socketStatus = getSn_SR(SOCKET_NUMBER);
    while ( socketStatus != SOCK_INIT )
        socketStatus = getSn_SR(SOCKET_NUMBER);
    
    while(1)
    {
        //считываем состояние сокета
        socketStatus = getSn_SR(SOCKET_NUMBER);
        if (socketStatus == SOCK_INIT)
        {
            //слушаем пока клиент приконектится
            listen(SOCKET_NUMBER);
        }
        //соединение с клиентом установлено
        else if (socketStatus == SOCK_ESTABLISHED)
        {
            //читаем сообщения(блокирующая поток фукнция)
            recv(SOCKET_NUMBER, receivedBuffer, 1000);
            static st_http_request request;
            parse_http_request(&request, receivedBuffer);
            if (request.METHOD == METHOD_GET)
            {
                createHtmlResponse(response);
                send(SOCKET_NUMBER, (uint8_t*)response, strlen(response));
            }
            else
                send(SOCKET_NUMBER, (uint8_t*)ERROR_REQUEST_PAGE, strlen(ERROR_REQUEST_PAGE));
            
            response[0] = '\0';
            //обнуляем принятый буфер
            for (uint32_t i = 0; i < sizeof(receivedBuffer); i++)
                receivedBuffer[i] = '\0';
            
        }
        else if (socketStatus == SOCK_CLOSE_WAIT)
        {
            disconnect(SOCKET_NUMBER);
        }
        //клиент отключился
        else if (socketStatus == SOCK_CLOSED)
        {
            //повторная иницилизация сокета
            socket(SOCKET_NUMBER, Sn_MR_TCP, TCP_PORT, SF_TCP_NODELAY);
        }
    }
}