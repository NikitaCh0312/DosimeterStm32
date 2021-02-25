#ifndef HTML_PAGE_H_
#define HTML_PAGE_H_

extern const char * MainPageHtml;
extern const char * AboutPageHtml;
extern const char * ContactsPageHtml;

const char * getMainHtmlResponse();
const char * getAboutHtmlResponse();
const char * getContactsHtmlResponse();
void createHtmlResponse(char * res_buffer);
void createJsonResponse(char * res_buffer, char * json);

#endif