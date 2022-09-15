#ifndef STRING_DICTIONARY_H_
#define STRING_DICTIONARY_H_

#define DICTIONARY_MAX_VALUES 20
#define DICTIONARY_KEY_MAX_LENGTH 20
#define HASH_FUNCTION_KOEFFICIENT 0.435f

template <typename T>
class StringDictionary
{
public:
    StringDictionary()
    {
		for (int i = 0; i < DICTIONARY_MAX_VALUES; i++)
		{
			_values[i].key[0] = '\0';
		}
    }
    virtual ~StringDictionary(){}
    
    typedef struct
    {
        char key[DICTIONARY_KEY_MAX_LENGTH];
        T value;
    }DictionaryValue_t;
    
    bool TryGetValue(char * key, T * outValue)
    {
		int position = GetHashCode_2(key);
		if (!strcmp(key, _values[position].key))
		{
			*outValue = _values[position].value;
			return true;
		}
		return false;
    }
    
    bool TryAddValue(char * key, T value)
    {
        if (strlen(key) >= DICTIONARY_KEY_MAX_LENGTH)
            return false;
		
        int position = GetHashCode_2(key);
		
		if (strlen(_values[position].key) != 0)
			return false;
		
		strcpy(_values[position].key, key);
        _values[position].value = value;
		
		return true;
    }
private:

	//unused
	int GetHashCode_1(char * key)
	{
		int value = ConvertStringToInt(key);
		return value % DICTIONARY_MAX_VALUES;
	}
	
	int GetHashCode_2(char * key)
	{
		int value = ConvertStringToInt(key);
		
		float full_value = (float)value * HASH_FUNCTION_KOEFFICIENT;
		
		int whole = (int)full_value;

		float fractional = full_value - (float)whole;

		return fractional * DICTIONARY_MAX_VALUES;
	}
	
	int ConvertStringToInt(char * str)
	{
		int value = 0;
		for (int i = 0; i < strlen(str); i++)
		{
			value += (int)str[i];
		}
		return value;
	}
	
    DictionaryValue_t _values[DICTIONARY_MAX_VALUES];
};

#endif