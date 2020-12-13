#ifndef STRING_RESOURCES_H_
#define STRING_RESOURCES_H_

#include "stddef.h"
#include "stdint.h"

class StringResources
{
public:
    virtual ~StringResources(){}
    StringResources * GetInstance()
    {
        if (_instance == NULL)
            _instance = new StringResources();
        return _instance;
    }
    
    //��������� � ����������� 
    static uint8_t Attach_RFID_Card_1str[20];
    //����������������� �����
    static uint8_t Attach_RFID_Card_2str[20];
    
    
    //��������! ����� �� ���������� �� ������ �����������
    static uint8_t Attention[20];
    static uint8_t CardIsNotBinded[20];
    static uint8_t ToThisDevice[20];
    
    //����� �������
    static uint8_t TasksQuantity[20];
    //������� �������
    static uint8_t CurrentTask[20];
    //����� ��������
    static uint8_t SolutionVolume[20];
    //������������ ��������
    static uint8_t SolutionConcentration[20];
    
private:
    StringResources(){}
    static StringResources * _instance;
        
};

#endif