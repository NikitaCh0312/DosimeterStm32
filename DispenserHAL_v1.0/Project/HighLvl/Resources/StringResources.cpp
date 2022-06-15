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

uint8_t StringResources::TaskExecuted_1str[20] = {'З', 'а', 'д', 'а', 'н', 'и', 'е', '\0'};
uint8_t StringResources::TaskExecuted_2str[20] = {'в', 'ы', 'п', 'о', 'л', 'н', 'е', 'н', 'о', ' ', 'у', 'c', 'п', 'е', 'ш', 'н', 'о', '!', '\0'};

uint8_t StringResources::TaskCancelTask_1str[20] = {'З', 'а', 'д', 'а', 'н', 'и', 'е', ' ', 'о', 'т', 'м', 'е', 'н', 'е', 'н', 'о', '!','\0'};

uint8_t StringResources::TaskErrorPreasure_1str[20] = {'Н', 'е', 'д', 'о', 'c', 'т', 'а', 'т', 'о', 'ч', 'н', 'о', 'е', '\0'};
uint8_t StringResources::TaskErrorPreasure_2str[20] = {'д', 'а', 'в', 'л', 'е', 'н', 'и', 'е', ' ', 'в', 'о', 'д', 'ы', '!', '\0'};

uint8_t StringResources::TaskErrorAvalibilitySubstance_1str[20] = {'В', ' ', 'б', 'а', 'к', 'е', ' ', 'з', 'а', 'к', 'о', 'н', 'ч', 'и', 'л', 'c', 'я', '\0'};
uint8_t StringResources::TaskErrorAvalibilitySubstance_2str[20] = {'п', 'р', 'е', 'п', 'а', 'р', 'а', 'т', '!', '\0'};

uint8_t StringResources::Attention[20] = {'В', 'Н', 'И', 'М', 'А', 'Н', 'И', 'Е', '!', '\0'};
uint8_t StringResources::CardIsNotBinded[20] = {'C', 'A', 'R', 'D', ' ', 'I', 'S', ' ', 'N', 'O', 'T', '\0'};
uint8_t StringResources::ToThisDevice[20] = {'B', 'I', 'N', 'D', 'E', 'D', '\0',};


uint8_t StringResources::TasksQuantity[20] = {'K','o','л','-', 'в', 'o', ' ', 'з', 'a', 'д', 'a', 'н', 'и', 'й', ':', '\0' };
uint8_t StringResources::CurrentTask[20] = {'В', 'ы', 'б', 'р', 'а', 'н', 'о', ':', '\0'};
uint8_t StringResources::SolutionVolume[20] = {'О', 'б', 'Ъ', 'е', 'м', ',', 'л', '\0' };
uint8_t StringResources::SolutionConcentration[20] = {'К', 'о', 'н', '-', 'ц', 'и', 'я', ',', '%','\0'};