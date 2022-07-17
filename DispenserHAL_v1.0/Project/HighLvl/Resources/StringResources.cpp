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


//MENU
uint8_t StringResources::Menu[20] = {'М','Е','Н','Ю','\0'};
//DATE TIME MENU
uint8_t StringResources::DateTime[20] = {'Д','А','Т','А',' ','В','Р','Е','М','Я','\0'};
uint8_t StringResources::Time[20] = {'В','Р','Е','М','Я','\0'};
uint8_t StringResources::Date[20] = {'Д','А','Т','А',' ','\0'};
//NETWORK
uint8_t StringResources::Network[20] = {'С','Е','Т','Е','В','Ы','Е',' ','Н','А','С','Т','Р','О','Й','К','И','\0'};

//ManualDosation
uint8_t StringResources::ManualDosation[20] = {'П','Р','И','Н','У','Д','.',' ','Д','О','З','-','Е','\0'};
uint8_t StringResources::PressEnter[20] = {'Н','А','Ж','М','И','Т','Е',' ','E','N','T','E','R','\0'};
uint8_t StringResources::ToStart[20] = {'Ч','Т','О','Б','Ы',' ','Н','А','Ч','А','Т','Ь','\0'};
uint8_t StringResources::ManualDosationMode[20] = {'Р','Е','Ж','И','М',' ','П','Р','И','Н','.',' ','Д','О','З','А','Ц','И','И','\0'};
uint8_t StringResources::Select[20] = {'В','Ы','Б','Е','Р','И','Т','Е','\0'};
uint8_t StringResources::Volume[20] = {'О','Б','Ъ','Е','М','\0'};
uint8_t StringResources::Concentration[20] = {'К','О','Н','Ц','-','Я','\0'};
uint8_t StringResources::SelectedParams[20] = {'В','Ы','Б','Р','А','Н','Н','Ы','Е',' ','П','А','Р','-','Р','Ы','\0'};

//SubstanceService
uint8_t StringResources::SubstanceService[20] = {'О','Б','С','Л','У','Ж','И','В','А','Н','И','Е',' ','С','Х','П','П','\0'};