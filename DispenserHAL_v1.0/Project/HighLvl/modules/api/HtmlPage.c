#include "HtmlPage.h"
#include "string.h"
#include "stdio.h"
#include "Ethernet/Internet/HttpServer/HttpParser.h"

const char * MainPageResponseHtml = 
"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 664\r\n\r\n\
\
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

const char * MainPageHtml = 
"<!DOCTYPE html>\
<html>\r\n\
  <head>\r\n\
    <title>Дозатор растворов</title>\r\n\
  </head>\r\n\
  <body>\r\n\
    <h1>Описание API для ДОЗАТОРА</h1>\r\n\
    <p>Список принимаемых команд:</p>\r\n\
    <ol>\r\n\
    <li>GET  - HUI HTML HUI</li>\r\n\
    <li>POST - HUI HTML HUI HUI HTML HUIli>\r\n\
    <li>PUT  - HUI HTML HUI HUI HTML HUI HUI HTML HUIli>\r\n\
    <li>HEAD - HUI HTML HUI HUI HTML HUI HUI HTML HUIli>\r\n\
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


const char * AboutPageResponseHtml =
"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 188\r\n\r\n\
\
<!DOCTYPE html>\
<html>\r\n\
  <head>\r\n\
    <title>Дозатор растворов</title>\r\n\
  </head>\r\n\
  <body>\r\n\
    <h1>Дозатор растворов</h1>\r\n\
    <p>Штука которая дозирует растворы</p>\r\n\
  </body>\r\n\
</html>\r\n\
\0";

const char * AboutPageHtml =
"<!DOCTYPE html>\
<html>\r\n\
  <head>\r\n\
    <title>Дозатор растворов</title>\r\n\
  </head>\r\n\
  <body>\r\n\
    <h1>Дозатор растворов</h1>\r\n\
    <p>Штука которая дозирует растворы</p>\r\n\
  </body>\r\n\
</html>\r\n\
\0";

const char * ContactsPageResponseHtml = 
"HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 171\r\n\r\n\
\
<!DOCTYPE html>\
<html>\r\n\
  <head>\r\n\
    <title>Дозатор растворов</title>\r\n\
  </head>\r\n\
  <body>\r\n\
    <h1>Контакты</h1>\r\n\
    <p>Тут какие-либо контакты</p>\r\n\
  </body>\r\n\
</html>\r\n\
\0";

const char * ContactsPageHtml = 
"<!DOCTYPE html>\
<html>\r\n\
  <head>\r\n\
    <title>Дозатор растворов</title>\r\n\
  </head>\r\n\
  <body>\r\n\
    <h1>Контакты</h1>\r\n\
    <p>Тут какие-либо контакты</p>\r\n\
  </body>\r\n\
</html>\r\n\
\0";

const char * getMainHtmlResponse()
{
    return MainPageResponseHtml;
}

const char * getAboutHtmlResponse()
{
    return AboutPageResponseHtml;
}

const char * getContactsHtmlResponse()
{
    return ContactsPageResponseHtml;
}

void createHtmlResponse(char * res_buffer)
{
    int contentLength = strlen(MainPageResponseHtml);
    contentLength = strlen(AboutPageResponseHtml);
    contentLength = strlen(ContactsPageResponseHtml);
    strcat(res_buffer, HTML_HEADER);
    char contLength[10];
    sprintf(contLength, "%d", contentLength);
    strcat(res_buffer, contLength);
    strcat(res_buffer, "\r\n\r\n");
    strcat(res_buffer, MainPageResponseHtml);
    strcat(res_buffer, "\r\n\0");
}

void createJsonResponse(char * res_buffer, char * json)
{
    int contentLength = strlen(json);
    //strcat(res_buffer, HTML_HEADER);
    strcat(res_buffer, RES_JSONHEAD_OK);
    char contLength[10];
    sprintf(contLength, "%d", contentLength);
    strcat(res_buffer, contLength);
    strcat(res_buffer, "\r\n\r\n");
    strcat(res_buffer, json);
    strcat(res_buffer, "\r\n\0");
}
