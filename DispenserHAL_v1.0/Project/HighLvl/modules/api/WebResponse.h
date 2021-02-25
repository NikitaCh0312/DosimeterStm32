#define WEB_RESPONSE_H_
#define WEB_RESPONSE_H_

class WebResponse
{
public:
    
    void AddHeader()
    {
      
    }
  
    void AddContent()
    {
      
    }
  
    char * ToString()
    {
       return _response;
    }
private:
    char _response[2000];
};

#endif
