#include "HtmlPage.h"
#include "string.h"
#include "stdio.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"

const char * HttpResponseHtmlPage = 
"\
<!DOCTYPE html>\
<html>\r\n\
  <head>\r\n\
    <title>Дозатор растворов</title>\r\n\
  </head>\r\n\
  <body>\r\n\
    <h1>Описание API для ДОЗАТОРА</h1>\r\n\
    <p>Список принимаемых команд:</p>\r\n\
    <ol>\r\n\
    <li>GET  - возвращает HTML описание проекта</li>\r\n\
    <li>POST - какая-то команда</li>\r\n\
    <li>PUT  - тоже какая-то команда</li>\r\n\
    <li>HEAD - еще какая-то команда</li>\r\n\
    </ol>\r\n\
    <form method=\"POST\">\r\n\
    <button type=\"submit\" value=\"ON\"> <font color=\"blue\">On Pump</font></button>\r\n\
    </form>\r\n\
    <form method=\"POST\">\r\n\
    <p><input type=\"text\" name=\"Pump_state\" size='4' value='33'></p>\r\n\
    <p><input type=\"submit\" value=\"OK\"></p>\r\n\
    </form>\r\n\
  </body>\r\n\
</html>\r\n\
\0";


void createHtmlResponse(char * res_buffer)
{
    int contentLength = strlen(HttpResponseHtmlPage);
    strcat(res_buffer, HTML_HEADER);
    char contLength[10];
    sprintf(contLength, "%d", contentLength);
    strcat(res_buffer, contLength);
    strcat(res_buffer, "\r\n\r\n");
    strcat(res_buffer, HttpResponseHtmlPage);
    strcat(res_buffer, "\r\n\0");
}