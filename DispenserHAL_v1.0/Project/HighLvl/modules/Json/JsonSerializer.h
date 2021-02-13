#ifndef JSON_SERIALIZER
#define JSON_SERIALIZER

#include "stddef.h"
#include "string.h"

class JsonSerializer
{
public:
    static JsonSerializer * GetInstance()
    {
        if (_instance == NULL)
            return new JsonSerializer();
        return _instance;
    }
    
    virtual ~JsonSerializer(){}
    
    void WriteStartObject(char * outString)
    {
        strcpy(outString, START_OBJECT);
    }
    
    void WriteEndObject(char * outString)
    {
        strcpy(outString, END_OBJECT);
    }
    
    void WriteStartArray(char * outString)
    {
        strcpy(outString, START_ARRAY);
    }
    
    void WriteEndArray(char * outString)
    {
        strcpy(outString, END_ARRAY);
    }
    
    void WriteProperty(char * outString, char * propertyName, int propertyValue)
    {
        
    }
    
    void WriteProperty(char * outString, char * propertyName, char * propertyValue)
    {
        
    }
    
    void WriteProperty(char * outString, char * propertyName, int propertyValue[])
    {
        
    }
private:
    static JsonSerializer * _instance;
    JsonSerializer(){}
    
    const char * START_OBJECT = "{"; 
    const char * END_OBJECT = "}";
    const char * START_ARRAY = "[";
    const char * END_ARRAY = "]";
};

#endif