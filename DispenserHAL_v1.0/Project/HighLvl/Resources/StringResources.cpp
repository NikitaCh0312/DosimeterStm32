#include "StringResources.h"

StringResources * StringResources::_instance = new StringResources();

uint8_t StringResources::DevicePreparing[20] = {'П', 'О', 'Д', 'Г', 'О', 'Т', 'О', 'В', 'К', 'А', '!', '\0'};
uint8_t StringResources::PleaseWait[20] = {'П', 'О', 'Д', 'О', 'Ж', 'Д', 'И', 'Т', 'Е', '.','.','.', '!', '\0'};
uint8_t StringResources::Error[20] = {' ',' ',' ', 'О', 'Ш', 'И', 'Б', 'К', 'К', 'А', '!', '\0'};
uint8_t StringResources::VoltageError[20] = {'Н','А','П', 'Р', 'Я', 'Ж', 'Е', 'Н', 'И', 'Е', '!', '\0'};

uint8_t StringResources::Attach_RFID_Card_1str[20] = {'П', 'Р', 'И', 'Л', 'О', 'Ж', 'И', 'Т', 'Е', '\0'};
uint8_t StringResources::Attach_RFID_Card_2str[20] = {'К', 'А', 'Р', 'Т', 'У', '\0'};

uint8_t StringResources::TaskExecution_1str[20] = {'В', 'Ы', 'П', 'О', 'Л', 'Н', 'Е', 'Н', 'И', 'Е', '\0'};
uint8_t StringResources::TaskExecution_2str[20] = {'З', 'А', 'Д', 'А', 'Н', 'И', 'Я', '\0'};

uint8_t StringResources::TaskExecuted_1str[20] = {'З', 'А', 'Д', 'А', 'Н', 'И', 'Е', '\0'};
uint8_t StringResources::TaskExecuted_2str[20] = {'В', 'Ы', 'П', 'О', 'Л', 'Н', 'Е', 'Н', 'О', '!', '\0'};

uint8_t StringResources::TaskErrorExecuted_1str[20] = {'З', 'А', 'Д', 'А', 'Н', 'И', 'Е', '\0'};
uint8_t StringResources::TaskErrorExecuted_2str[20] = {'О', 'Ш', 'И', 'Б', 'К', 'А', '!', '\0'};

uint8_t StringResources::Attention[20] = {'В', 'Н', 'И', 'М', 'А', 'Н', 'И', 'Е', '!', '\0'};
uint8_t StringResources::CardIsNotBinded[20] = {'C', 'A', 'R', 'D', ' ', 'I', 'S', ' ', 'N', 'O', 'T', '\0'};
uint8_t StringResources::ToThisDevice[20] = {'B', 'I', 'N', 'D', 'E', 'D', '\0',};


uint8_t StringResources::TasksQuantity[20] = {'K','o','л','-', 'в', 'o', ' ', 'з', 'a', 'д', 'a', 'н', 'и', 'й', ':', '\0' };
uint8_t StringResources::CurrentTask[20] = {'В', 'ы', 'б', 'р', 'а', 'н', 'о', ':', '\0'};
uint8_t StringResources::SolutionVolume[20] = {'О', 'б', 'Ъ', 'е', 'м', ',', 'л', '\0' };
uint8_t StringResources::SolutionConcentration[20] = {'К', 'о', 'н', '-', 'ц', 'и', 'я', ',', '%','\0'};