#include "StringResources.h"

StringResources * StringResources::_instance = new StringResources();

uint8_t StringResources::DevicePreparing[20] = {'П', 'О', 'Д', 'Г', 'О', 'Т', 'О', 'В', 'К', 'А', '!', '\0'};
uint8_t StringResources::PleaseWait[20] = {'П', 'О', 'Д', 'О', 'Ж', 'Д', 'И', 'Т', 'Е', '.','.','.', '!', '\0'};
uint8_t StringResources::Error[20] = {' ',' ',' ', 'О', 'Ш', 'И', 'Б', 'К', 'К', 'А', '!', '\0'};
uint8_t StringResources::VoltageError[20] = {'Н','А','П', 'Р', 'Я', 'Ж', 'Е', 'Н', 'И', 'Е', '!', '\0'};

uint8_t StringResources::Attach_RFID_Card_1str[20] = {' ', ' ', ' ', 'A', 'T', 'T', 'A', 'C', 'H', '\0'};
uint8_t StringResources::Attach_RFID_Card_2str[20] = {' ', ' ', ' ', 'C', 'A', 'R', 'D', '\0'};


uint8_t StringResources::Attention[20] = {'В', 'Н', 'И', 'М', 'А', 'Н', 'И', 'Е', '!', '\0'};
uint8_t StringResources::CardIsNotBinded[20] = {'C', 'A', 'R', 'D', ' ', 'I', 'S', ' ', 'N', 'O', 'T', '\0'};
uint8_t StringResources::ToThisDevice[20] = {'B', 'I', 'N', 'D', 'E', 'D', '\0',};


uint8_t StringResources::TasksQuantity[20] = {'T', 'a', 's', 'k', 's', ':', '\0' };
uint8_t StringResources::CurrentTask[20] = {'S', 'e', 'l', 'e', 'c', 't', 'e', 'd', ':', '\0'};
uint8_t StringResources::SolutionVolume[20] = {'V', 'o', 'l', 'u', 'm', 'e', '\0' };
uint8_t StringResources::SolutionConcentration[20] = {'C', 'o', 'n', 'c', 'e', 'n', 't', 'r', 'a', 't', '\0'};