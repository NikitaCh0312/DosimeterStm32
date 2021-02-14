#ifndef IELEMENT_VIEW_H_
#define IELEMENT_VIEW_H_


typedef struct 
{
    uint8_t row;
    uint8_t column;
}LcdPosition_t;

class IElementView
{
public:
    IElementView(LcdPosition_t position)
    {

    }
    virtual ~IElementView(){}
    
    virtual void Draw() = 0;
    
protected:
    IElementView * next;
    IElementView * prev;
    
    LcdPosition_t position;
};


#endif