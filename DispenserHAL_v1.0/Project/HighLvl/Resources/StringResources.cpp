#include "StringResources.h"

StringResources * StringResources::_instance = new StringResources();

uint8_t StringResources::DevicePreparing_1[20] = {'И', 'д', 'е', 'т', ' ', 'п', 'о', 'д', 'г', 'о', 'т', 'о', 'в', 'к', 'а', '\0'};
uint8_t StringResources::DevicePreparing_2[20] = {'к', ' ', 'з', 'а', 'п', 'у', 'c', 'к', 'у', '.', ' ', 'П', 'о', 'ж', 'а', 'л', 'у', 'й', '-','\0'};
uint8_t StringResources::DevicePreparing_3[20] = {'c', 'т', 'а', ' ', 'п', 'о', 'д', 'о', 'ж', 'д', 'и', 'т', 'е', '.', '.', '!', '\0'};
uint8_t StringResources::PleaseWait[20] = {'П', 'О', 'Д', 'О', 'Ж', 'Д', 'И', 'Т', 'Е', '.','.','.', '!', '\0'};
uint8_t StringResources::Error[20] = { 'О', 'Ш', 'И', 'Б', 'К', 'А', '!', '\0'};
uint8_t StringResources::VoltageError_1[20] = {'А', 'д', 'а', 'п','т','е', 'р', ' ', 'п', 'и', 'т', 'а', 'н', 'и', 'я','\0'};
uint8_t StringResources::VoltageError_2[20] = {'н', 'е', 'и', 'с','п','р', 'а', 'в', 'е', 'н', '!', '\0'};

uint8_t StringResources::DeviceInfo_1[20] = {'С', 'и', 'c', 'т', 'е', 'м', 'а', ' ', 'п', 'р', 'и', 'г', 'о', 'т', 'а', 'в', 'л', 'е', '-','\0'};
uint8_t StringResources::DeviceInfo_2[20] = {'н', 'и', 'я', ' ', 'и', ' ', 'у', 'ч', 'е', 'т', 'а', ' ', 'р', 'а', 'c', 'х', 'о', 'д', 'а','\0'};
uint8_t StringResources::DeviceInfo_3[20] = {'р', 'а', 'c', 'т', 'в', 'о', 'р', 'о', 'в', '.', '\0'};
uint8_t StringResources::DeviceInfo_4[20] = {'У', 'c', 'т', 'р', 'о', 'й', 'c', 'т', 'в', 'о', ' ', ' ', ' ', '1', '.', '1', '.', '1', 'V','\0'};

uint8_t StringResources::Attach_RFID_Card_1str[20] = {'П', 'Р', 'И', 'Л', 'О', 'Ж', 'И', 'Т', 'Е', '\0'};
uint8_t StringResources::Attach_RFID_Card_2str[20] = {'К', 'А', 'Р', 'Т', 'У', '\0'};

uint8_t StringResources::TaskExecution_1str[20] = {'В', 'Ы', 'П', 'О', 'Л', 'Н', 'Е', 'Н', 'И', 'Е', '\0'};
uint8_t StringResources::TaskExecution_2str[20] = {'З', 'А', 'Д', 'А', 'Н', 'И', 'Я', '\0'};

uint8_t StringResources::TaskExecuted_1str[20] = {'З', 'а', 'д', 'а', 'н', 'и', 'е', '\0'};
uint8_t StringResources::TaskExecuted_2str[20] = {'в', 'ы', 'п', 'о', 'л', 'н', 'е', 'н', 'о', ' ', 'у', 'c', 'п', 'е', 'ш', 'н', 'о', '!', '\0'};

uint8_t StringResources::TaskCancelTask_1str[20] = {'З', 'а', 'д', 'а', 'н', 'и', 'е', ' ', 'о', 'т', 'м', 'е', 'н', 'е', 'н', 'о', '!','\0'};

uint8_t StringResources::TaskErrorPreasure_1str[20] = {'Н', 'е', 'д', 'о', 'c', 'т', 'а', 'т', 'о', 'ч', 'н', 'о', 'е', '\0'};
uint8_t StringResources::TaskErrorPreasure_2str[20] = {'д', 'а', 'в', 'л', 'е', 'н', 'и', 'е', ' ', 'в', 'о', 'д', 'ы', '!', '\0'};

uint8_t StringResources::TaskServiceMsgInit_1str[20] = {'П', 'о', 'м', 'е', 'c', 'т', 'и', 'т', 'е', ' ', 'н', 'а', 'л', 'и', 'в', 'н', 'о', 'й','\0'};
uint8_t StringResources::TaskServiceMsgInit_2str[20] = {'ш', 'л', 'а', 'н', 'г', ' ', 'в', ' ', 'р', 'а', 'к', 'о', 'в', 'и', 'н', 'у', '!', '\0'};
uint8_t StringResources::TaskServiceMsgInit_3str[20] = {'Н', 'а', 'ж', 'м', 'и', 'т', 'е', ' ', '"', 'С', 'т', 'а', 'р', 'т', '"', '\0'};
uint8_t StringResources::TaskServiceMsgInit_4str[20] = {'д', 'л', 'я', ' ', 'п', 'р', 'о', 'д', 'о', 'л', 'ж', 'е', 'н', 'и', 'я', '!', '\0'};

uint8_t StringResources::TaskServiceMsgCancel_1str[20] = {'П', 'р', 'о', 'ц', 'е', 'д', 'у', 'р', 'а','\0'};
uint8_t StringResources::TaskServiceMsgCancel_2str[20] = {'о', 'б', 'c', 'л', 'у', 'ж', 'и', 'в', 'а', 'н', 'и', 'я', ' ', 'С', 'Х', 'П', 'П', '\0'};
uint8_t StringResources::TaskServiceMsgCancel_3str[20] = {'о', 'т', 'м', 'е', 'н', 'е', 'н', 'а', '!', '\0'};

uint8_t StringResources::TaskServiceMsgCleaning_1str[20] = {'В', 'ы', 'п', 'о', 'л', 'н', 'я', 'е', 'т', 'c', 'я', ' ', 'о', 'ч', 'и', 'c', 'т', 'к', 'а','\0'};
uint8_t StringResources::TaskServiceMsgCleaning_2str[20] = {'б', 'а', 'к', 'а', '.', ' ', 'О', 'ж', 'и', 'д', 'а', 'й', 'т', 'е', '.', '.', '.', '\0'};

uint8_t StringResources::TaskServiceMsgInfo_1_1str[20] = {'З', 'а', 'л', 'е', 'й', 'т', 'е', ' ', '2', '5', '0', ' ', 'м', 'л', '.', '\0'};
uint8_t StringResources::TaskServiceMsgInfo_1_2str[20] = {'п', 'р', 'о', 'м', 'ы', 'в', '-', 'о', 'й', ' ', 'ж', 'и', 'д', 'к', 'о', 'c', 'т', 'и','\0'};
uint8_t StringResources::TaskServiceMsgInfo_1_3str[20] = {'в', ' ', 'б', 'а', 'к', ' ', 'и', ' ', 'н', 'а', 'ж', 'м', 'и', 'т', 'е', ' ', 0x13, '\0'};
uint8_t StringResources::TaskServiceMsgInfo_1_4str[20] = {'д', 'л', 'я', ' ', 'п', 'р', 'о', 'д', 'о', 'л', 'ж', 'е', 'н', 'и', 'я', '!', '\0'};

uint8_t StringResources::TaskServiceMsgInfo_2_1str[20] = {'В', 'ы', 'п', 'о', 'л', 'н', 'я', 'е', 'т', 'c', 'я', ' ', 'о', 'ч', 'и', 'c', 'т', 'к', 'а','\0'};
uint8_t StringResources::TaskServiceMsgInfo_2_2str[20] = {'С', 'Х', 'П', 'П', '.', ' ', 'О', 'ж', 'и', 'д', 'а', 'й', 'т', 'е', '.', '.', '.', '\0'};

uint8_t StringResources::TaskServiceMsgInfo_3_1str[20] = {'С', 'н', 'и', 'м', 'и', 'т', 'е', ' ', 'и', ' ', 'о', 'б', 'р', 'а', 'б', 'о', '-', ' ','\0'};
uint8_t StringResources::TaskServiceMsgInfo_3_2str[20] = {'т', 'а', 'й', 'т', 'е', ' ', 'б', 'а', 'к', '.', 'З', 'а', 'м', 'е', 'н', 'и', 'т', 'е','\0'};
uint8_t StringResources::TaskServiceMsgInfo_3_3str[20] = {'у', 'п', 'л', 'о', 'т', 'н', 'и', 'т', 'е', 'л', 'ь', '.', 'Н', 'а', 'ж', 'м', 'и', 'т', 'е','\0'};
uint8_t StringResources::TaskServiceMsgInfo_3_4str[20] = {0x13, ' ', 'д', 'л', 'я', ' ', 'п', 'р', 'о', 'д', 'о', 'л', 'ж', 'е', 'н', 'и', 'я', '!', '\0'};

uint8_t StringResources::TaskServiceMsgInfo_4_1str[20] = {'У', 'c', 'т', 'а', 'н', 'о', 'в', 'и', 'т', 'е', ',', ' ', 'б', 'а', 'к', '!', '\0'};
uint8_t StringResources::TaskServiceMsgInfo_4_2str[20] = {'З', 'а', 'л', 'е', 'й', 'т', 'е', ' ', 'c', 'в', 'е', 'ж', 'и', 'й', '\0'};
uint8_t StringResources::TaskServiceMsgInfo_4_3str[20] = {'п', 'р', 'е', 'п', 'а', 'р', 'а', 'т', '.', ' ', 'Н', 'а', 'ж', 'м', 'и', 'т', 'е', '\0'};
uint8_t StringResources::TaskServiceMsgInfo_4_4str[20] = {0x13, ' ', 'д', 'л', 'я', ' ', 'п', 'р', 'о', 'д', 'о', 'л', 'ж', 'е', 'н', 'и', 'я', '!', '\0'};

uint8_t StringResources::TaskServiceMsgInfo_5_1str[20] = {'И', 'д', 'е', 'т', ' ', 'п', 'о', 'д', 'г', 'о', 'т', 'о', 'в', 'к', 'а', '\0'};
uint8_t StringResources::TaskServiceMsgInfo_5_2str[20] = {'у', 'c', 'т', 'р', 'о', 'й', 'c', 'т', 'в', 'а', '!', '\0'};
uint8_t StringResources::TaskServiceMsgInfo_5_3str[20] = {'О', 'ж', 'и', 'д', 'а', 'й', 'т', 'е', '.', '.', '.', '\0'};

uint8_t StringResources::TaskServiceMsgInfo_6_1str[20] = {'З', 'а', 'п', 'р', 'а', 'в', 'к', 'а', ' ', 'п', 'р', 'е', 'п', 'а', 'р', 'а', 'т', 'а','\0'};
uint8_t StringResources::TaskServiceMsgInfo_6_2str[20] = {'з', 'а', 'к', 'о', 'н', 'ч', 'е', 'н', 'а', ' ', 'у', 'c', 'п', 'е', 'ш', 'н', 'о', '!','\0'};

uint8_t StringResources::TaskErrorAvalibilitySubstance_1str[20] = {'В', ' ', 'б', 'а', 'к', 'е', ' ', 'з', 'а', 'к', 'о', 'н', 'ч', 'и', 'л', 'c', 'я', '\0'};
uint8_t StringResources::TaskErrorAvalibilitySubstance_2str[20] = {'п', 'р', 'е', 'п', 'а', 'р', 'а', 'т', '!', '\0'};

uint8_t StringResources::Attention[20] = {'В', 'Н', 'И', 'М', 'А', 'Н', 'И', 'Е', '!', '\0'};
uint8_t StringResources::CardIsNotBinded[20] = {'К', 'A', 'Р', 'Т', 'А', ' ', 'Н', 'Е', ' ','П', 'Р', 'И', 'В', 'Я', 'З', 'А', 'Н', 'А', '\0'};
uint8_t StringResources::ToThisDevice[20] = {'К', ' ', 'У', 'С', 'Т', 'Р', 'О', 'Й', 'С', 'Т', 'В', 'У', '\0',};


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
uint8_t StringResources::ManualDosation[20] = {'П','Р','И','Н','У','Д','.',' ','Д','О','З','-','Н','И','Е','\0'};
uint8_t StringResources::PressEnter[20] = {'Н','А','Ж','М','И','Т','Е',' ','E','N','T','E','R','\0'};
uint8_t StringResources::ToStart[20] = {'Ч','Т','О','Б','Ы',' ','Н','А','Ч','А','Т','Ь','\0'};
uint8_t StringResources::ManualDosationMode[20] = {'Р','Е','Ж','И','М',' ','П','Р','И','Н','.',' ','Д','О','З','А','Ц','И','И','\0'};
uint8_t StringResources::Select[20] = {'В','Ы','Б','Е','Р','И','Т','Е','\0'};
uint8_t StringResources::Volume[20] = {'О','Б','Ъ','Е','М','\0'};
uint8_t StringResources::Concentration[20] = {'К','О','Н','Ц','-','Я','\0'};
uint8_t StringResources::SelectedParams[20] = {'В','Ы','Б','Р','А','Н','Н','Ы','Е',' ','П','А','Р','-','Р','Ы','\0'};

//SubstanceService
uint8_t StringResources::SubstanceService[20] = {'О','Б','С','Л','У','Ж','И','В','А','Н','И','Е',' ','С','Х','П','П','\0'};

uint8_t StringResources::SubstanceSelected[20] = {'П','Р','Е','П','А','Р','А','Т',' ','С','О','Х','Р','А','Н','Е','Н','\0'};
uint8_t StringResources::SubstanceNotSelected[20] = {'П','Р','Е','П','А','Р','А','Т',' ','Н','E',' ','С','О','Х','Р','А','Н','\0'};