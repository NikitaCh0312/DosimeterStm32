#ifndef STRING_DICTIONARY_H_
#define STRING_DICTIONARY_H_

#define DICTIONARY_MAX_VALUES 20
#define DICTIONARY_KEY_MAX_LENGTH 20

template <typename T>
class StringDictionary
{
public:
    StringDictionary(uint32_t keySize, uint32_t size)
    {
        _valuesQuantity = 0;
    }
    virtual ~StringDictionary(){}
    
    typedef struct
    {
        char key[DICTIONARY_KEY_MAX_LENGTH];
        T value;
    }DictionaryValue_t;
    
    bool TryGetValue(char * key, T * outValue)
    {
        for (uint32_t i = 0; i < _valuesQuantity; i++)
        {
            if (!strcmp(key, _values[i].key))
            {
                *outValue = _values[i].value;
                return true;
            }
        }
        return false;
    }
    
    bool TryAddValue(char * key, T value)
    {
        if (_valuesQuantity >= DICTIONARY_MAX_VALUES || strlen(key) >= DICTIONARY_KEY_MAX_LENGTH)
            return false;
        
        
        
        strcpy(_values[_resourcesQuantity].key, key);
        Values[_valuesQuantity].value = value;
        _valuesQuantity++;
    }
private:

    DictionaryValue_t _values[DICTIONARY_MAX_VALUES];
    
    uint32_t _valuesQuantity;
};

#endif