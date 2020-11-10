#ifndef IVIEW_MENU_NODE_H_
#define IVIEW_MENU_NODE_H_


typedef struct
{
    uint32_t value;
    uint32_t max;
    uint32_t min;
}Parameter_t;

class IViewMenuNode
{
public:
    IViewMenuNode(){}
    virtual ~IViewMenuNode(){}
    virtual void Draw() = 0;
    virtual void Cancel() = 0;
    virtual void Enter() = 0;
    virtual void Up() = 0;
    virtual void Down() = 0;
};


#endif