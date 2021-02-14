#include "EthernetTask.h"
#include "Ethernet/Ethernet/socket.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"
#include "modules/api/HtmlPage.h"
#include "string.h"
#include "stdio.h"

#include "modules/api/apiObjects/DescriptionApi.h"

#define SOCKET_NUMBER   3
#define TCP_PORT        666




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
                const char * resp;
                if (!strcmp((char*)request.URI, "/about"))
                {
                    resp = getAboutHtmlResponse();
                }
                else if (!strcmp((char*)request.URI, "/contacts"))
                {
                    resp = getContactsHtmlResponse();
                }
                else
                {
                    resp = getMainHtmlResponse();
                    DescriptionApi description(JsonSerializer::GetInstance(), "13245", "1", "0.1");
                    static char desc[100];
                    description.Serialize(desc);
                }
                //createHtmlResponse(response);
                send(SOCKET_NUMBER, (uint8_t*)resp, strlen(resp));
            }
            else if (request.METHOD == METHOD_POST)
            {
                //123
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