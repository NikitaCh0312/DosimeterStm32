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
    IElementView()
    {
        
    }
    IElementView(LcdPosition_t position)
    {
        _position = position;
    }
    virtual ~IElementView(){}
    
    virtual void Draw() = 0;
    
    virtual void Hide() = 0;
    
    IElementView * GetNext()
    {
        return _next;
    }
    
    IElementView * GetPrevious()
    {
        return _prev;
    }
    
    void SetNext(IElementView * next)
    {
        _next = next;
    }
    
    void SetPrevious(IElementView * prev)
    {
        _prev = prev;
    }
    
protected:
    IElementView * _next;
    IElementView * _prev;
    
    LcdPosition_t _position;
};


#endif