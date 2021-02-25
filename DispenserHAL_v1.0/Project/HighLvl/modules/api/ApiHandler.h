#ifndef API_HANDLER_H_
#define API_HANDLER_H_



class ApiHandler
{
public:
  ApiHandler()
  {
    
  }
  virtual ~ApiHandler(){}
  
  virtual void Handle() = 0;
  
private:
  
  
};






#endif
