#ifndef WEB_RESPONSE_H_
#define WEB_RESPONSE_H_

class WebResponse
{
public:
    
    void AddHeader(char * header)
    {
      
    }
  
    void AddContent(char * content)
    {
      
    }
    
    void SetFullResponse(char * response)
    {
        
    }
  
    char * ToString()
    {
       return _response;
    }
private:
    char _response[1000];
};

#endif
