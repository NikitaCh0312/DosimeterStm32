#ifndef TASK_CARD_SESSION_H_
#define TASK_CARD_SESSION_H_

#include "Card.h"

class TaskCardSession
{
public:
    TaskCardSession()
    {
        isSessionStarted = false;
        executedTasksQuantity = 0;
        InitSession();
    }

    void InitSession()
    {
        isSessionStarted = true;
        executedTasksQuantity = 0;
        ResetSession();
    }

    void EndSession()
    {
        isSessionStarted = false;
        executedTasksQuantity = 0;
        ResetSession();
    }

    void AddExecutedTask(int taskId)
    {
        if (!isSessionStarted)
            return;
        executedTaskIds[executedTasksQuantity++] = taskId;
    }

    bool IsTaskExecuted(int taskId)
    {
        for (int i = 0; i < executedTasksQuantity; i++)
        {
            if (executedTaskIds[i] == taskId)
                return true;
        }
        return false;
    }   

private:
    int executedTaskIds[20];
    bool isSessionStarted;
    int executedTasksQuantity;
    
    void ResetSession()
    {
        for (int i = 0; i < 20; i++)
            executedTaskIds[i] = -1;
        executedTasksQuantity = 0;
    }
};

#endif