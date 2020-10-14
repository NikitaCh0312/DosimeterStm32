#include "EthernetTask.h"
#include "Ethernet/Ethernet/socket.h"

#include "string.h"

#define SOCKET_NUMBER   3
#define TCP_PORT        667


uint8_t receivedBuffer[100];
uint8_t testDisplayBuffer[100];
uint32_t RxMessageSizeBytes = 0;

void EthernetTask::Execute()
{
    //�������� �������� �����
    for (uint32_t i = 0; i < sizeof(receivedBuffer); i++)
        receivedBuffer[i] = '\0';
    
    socket(SOCKET_NUMBER, Sn_MR_TCP, TCP_PORT, SF_TCP_NODELAY);
    
    int socketStatus = getSn_SR(SOCKET_NUMBER);
    while ( socketStatus != SOCK_INIT )
        socketStatus = getSn_SR(SOCKET_NUMBER);
    
    while(1)
    {
        //��������� ��������� ������
        socketStatus = getSn_SR(SOCKET_NUMBER);
        if (socketStatus == SOCK_INIT)
        {
            //������� ���� ������ �������������
            listen(SOCKET_NUMBER);
        }
        //���������� � �������� �����������
        else if (socketStatus == SOCK_ESTABLISHED)
        {
            //������ ���������(����������� ����� �������)
            recv(SOCKET_NUMBER, receivedBuffer, 100);
            //���������� ���-�� �������� ����
            uint32_t rxMsgSze = strlen((char*)receivedBuffer);
            if (rxMsgSze < 100)
            {
                RxMessageSizeBytes = rxMsgSze;
                for (int i = 0; i < rxMsgSze; i++)
                    testDisplayBuffer[i] = receivedBuffer[i];
            }
                
            
            //�������� �������� �����
            for (uint32_t i = 0; i < sizeof(receivedBuffer); i++)
                receivedBuffer[i] = '\0';
            
        }
        //������ ����������
        else if (socketStatus == SOCK_CLOSED)
        {
            //��������� ������������ ������
            socket(SOCKET_NUMBER, Sn_MR_TCP, TCP_PORT, SF_TCP_NODELAY);
        }
    }
}