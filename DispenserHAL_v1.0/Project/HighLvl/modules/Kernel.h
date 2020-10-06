#ifndef KERNEL_H_
#define KERNEL_H_

#include "stddef.h"



class Kernel
{
public:
    static Kernel * get_instance()
    {
        if (instance == NULL)
            instance = new Kernel();
        return instance;
    }
    ~Kernel() {}
    void init();
    
    
    void debugTaskRun();
private:
    Kernel(){}
    static Kernel * instance;
    
    
    
    
};









#endif