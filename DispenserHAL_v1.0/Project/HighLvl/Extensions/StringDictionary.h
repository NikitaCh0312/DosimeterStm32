#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#define DICTIONARY_MAX_VALUES 20

template <typename K, typename T>
class Dictionary
{
public:
    Dictionary()
    {
        _valuesQuantity = 0;
    }
    
    typedef struct
    {
        K key;
        T value;
    }DictionaryValue_t;
    
    bool TryGetValue(K key)
    {
        
    }
    
    void AddValue(K key, T value)
    {
        if (_valuesQuantity >= DICTIONARY_MAX_VALUES)
            return;
        //Values[_valuesQuantity].key = key;
        Values[_valuesQuantity].value = value;
        _valuesQuantity++;
    }
private:

    
    DictionaryValue_t Values[DICTIONARY_MAX_VALUES];
    
    uint32_t _valuesQuantity;
};

#endif