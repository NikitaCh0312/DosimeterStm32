#ifndef COMPOSITE_MENU_NODE_H_
#define COMPOSITE_MENU_NODE_H_

#include "Menu/IMenuNode.h"


#define MAX_MENU_NODES 10
class CompositeMenuNode: public IMenuNode
{
public:
    CompositeMenuNode(char * nodeName):IMenuNode(nodeName)
    {
        _nodesQuantity = 0;
    }
    ~CompositeMenuNode(){}
    
    void addMenuNode(IMenuNode * node)
    {
        MenuNodes[_nodesQuantity++] = node; 
    }
    IMenuNode * MenuNodes[MAX_MENU_NODES];
private:
    uint32_t _nodesQuantity; 
}

#endif