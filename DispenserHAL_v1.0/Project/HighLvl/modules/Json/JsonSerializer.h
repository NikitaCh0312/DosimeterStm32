#ifndef JSON_SERIALIZER
#define JSON_SERIALIZER

#include "stddef.h"
#include "string.h"
#include "stdio.h"

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
        strcat(outString, START_OBJECT);
    }
    
    void WriteEndObject(char * outString)
    {
        strcat(outString, END_OBJECT);
    }
    
    void WriteStartArray(char * outString)
    {
        strcat(outString, START_ARRAY);
    }
    
    void WriteEndArray(char * outString)
    {
        strcat(outString, END_ARRAY);
    }
    
    void WriteEndProperty(char * outString)
    {
        strcat(outString, END_PROPERTY);
    }
    
    void WriteProperty(char * outString, char * propertyName, int propertyValue)
    {
        strcat(outString, "\"");
        strcat(outString, propertyName);
        strcat(outString, "\"");
        strcat(outString, ":");
        strcat(outString, "\"");
        sprintf(outString, "%d", propertyValue);
        strcat(outString, "\"");
    }
    
    void WriteProperty(char * outString, char * propertyName, char * propertyValue)
    {
        strcat(outString, "\"");
        strcat(outString, propertyName);
        strcat(outString, "\"");
        strcat(outString, ":");
        strcat(outString, "\"");
        strcat(outString, propertyValue);
        strcat(outString, "\"");
    }
    
private:
    static JsonSerializer * _instance;
    JsonSerializer(){}
    
    const char * START_OBJECT = "{"; 
    const char * END_OBJECT = "}";
    const char * START_ARRAY = "[";
    const char * END_ARRAY = "]";
    const char * END_PROPERTY = ",";
};

#endif