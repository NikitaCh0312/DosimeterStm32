#ifndef IMENU_NODE_H_
#define IMENU_NODE_H_

#include "string.h"


#define MAX_NODE_NAME_SIZE 20

class IMenuNode
{
public:
    IMenuNode(char * nodeName)
    {
        if (strlen(nodeName) > MAX_NODE_NAME_SIZE)
            while(1);
        strcpy(_nodeName, nodeName);
    };
    virtual ~IMenuNode(){};
    IMenuNode * getChild();
    IMenuNode * getNext();
    IMenuNode * getPrevious();
    char * getNodeName()
    {
        return _nodeName;
    }
private:
    char * _nodeName[MAX_NODE_NAME_SIZE];
};


#endif