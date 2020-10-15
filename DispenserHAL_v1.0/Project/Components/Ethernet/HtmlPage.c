#include "HtmlPage.h"

const char * HttpResponsePage = 
"\
<!DOCTYPE html>\
<head>\
    <title>Дозатор</title>\
</head>\
<html>\
  <body>\
    <h1>Описание API для ДОЗАТОРА</h1>\
    <p>Список принимаемых команд:</p>\
    <ol>\
        <li>GET  - возвращает HTML описание проекта</li>\
        <li>POST - какая-то команда</li>\
        <li>PUT  - тоже какая-то команда</li>\
        <li>HEAD - еще какая-то команда</li>\
    </ol>\
  </body>\
</HTML>\
\0";