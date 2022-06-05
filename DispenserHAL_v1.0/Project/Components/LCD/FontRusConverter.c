#include "FontRusConverter.h"
#include "stddef.h"
#include "stdint.h"

char symbols_RUru[] =
{ 
  'А',
  'Б',
  'В',
  'Г',
  'Д', 
  'Е',
  'Ё',
  'Ж',
  'З',
  'И',
  'Й',
  'К',
  'Л',
  'М',
  'Н',
  'О',
  'П',
  'Р',
  'С',
  'Т',
  'У',
  'Ф',
  'Х',
  'Ц',
  'Ч',
  'Ш',
  'Щ',
  'Ь',
  'Ы',
  'Ъ',
  'Э',
  'Ю',
  'Я',
  
  
  'а',
  'б',
  'в',
  'г',
  'д',
  'е',
  'ё',
  'ж',
  'з',
  'и',
  'й',
  'к',
  'л',
  'м',
  'н',
  'о',
  'п',
  'р',
  'с',
  'т',
  'у',
  'ф',
  'х',
  'ц',
  'ч',
  'ш',
  'щ',
  'ь',
  'ы',
  'ъ',
  'э',
  'ю', 
  'я'
};

uint8_t LcdSymbols_RUru[] = 
{
  0x41,//'А'
  0xA0,//'Б',
  0x42,//'В',
  0xA1,//'Г',
  0xE0,//'Д', 
  0x45,//'Е',
  0x45,//'Ё',
  0xA3,//'Ж',
  0xA4,//'З',
  0xA5,//'И',
  0xA5,//'Й',
  0x4B,//'К',
  0xA7,//'Л',
  0x4D,//'М',
  0x48,//'Н',
  0x4F,//'О',
  0xA8,//'П',
  0x50,//'Р',
  0x43,//'С',
  0x54,//'Т',
  0x59,//'У',
  0xAA,//'Ф',
  0x58,//'Х',
  0xE1,//'Ц',
  0xAB,//'Ч',
  0xAC,//'Ш',
  0xE2,//'Щ',
  0x08,//'Ь',
  0xAE,//'Ы',
  0xAD,//'Ъ',
  0xAF,//'Э',
  0xB0,//'Ю',
  0xB1,//'Я'
  
  
  
  
  0x61,//'а',
  0xB2,//'б',
  0xB3,//'в',
  0xB4,//'г',
  0xE3,//'д',
  0x65,//'е',
  0x65,//'ё',
  0xB6,//'ж',
  0xB7,//'з',
  0xB8,//'и',
  0xB8,//'й',
  0xBA,//'к',
  0xBB,//'л',
  0xBC,//'м',
  0xBD,//'н',
  0x6F,//'о',
  0xBE,//'п',
  0x70,//'р',
  0x63,//'с',
  0xBF,//'т',
  0x79,//'у',
  0xE4,//'ф',
  0x78,//'х',
  0xE5,//'ц',
  0xC0,//'ч',
  0xC1,//'ш',
  0xE6,//'щ',
  0xC4,//'ь',
  0xC3,//'ы',
  0xC2,//'ъ',
  0xC5,//'э',
  0xC6,//'ю', 
  0xC7,//'я'
};


static int getPosition(char symbol)
{
    int position = -1;
    for (int i = 0; i < sizeof(symbols_RUru); i++)
    {
        if (symbols_RUru[i] == symbol)
          return i;
    }
    return position;
}

bool TryGetLcdSymbol(char symbol, uint8_t* result)
{
  int position = getPosition(symbol);
  if (position == -1)
  {
    *result = NULL;
    return false;
  }
  *result = LcdSymbols_RUru[position];
  return true;
}