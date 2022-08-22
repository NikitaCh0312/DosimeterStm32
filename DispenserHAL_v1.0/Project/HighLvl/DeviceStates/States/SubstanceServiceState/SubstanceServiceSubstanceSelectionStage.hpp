#ifndef SUBSTANCE_SERVICE_SUBSTANCE_SELECTION_STAGE_H_
#define SUBSTANCE_SERVICE_SUBSTANCE_SELECTION_STAGE_H_

#include "LCD/LCD.h"
#include "Resources/StringResources.h"

class SubstanceServiceSubstanceSelectionStage
{
public:
    SubstanceServiceSubstanceSelectionStage(ISubstanceServiceState * substanceServiceState)
    {
        _subStage = SUBSTANCE_SELECTION_SUBSTAGE;
        _selectedSubstance = NULL;
        _isInitedDefaultSubstance = false;
        _substanceServiceState = substanceServiceState;
        _substanceManager = ModulesLocator::GetInstance()->substancesManager;
        _substancesList = _substanceManager->GetSubstancesPtr();
    }
    
    void Handle(UserAction_t action)
    {
        if (_subStage == SUBSTANCE_SELECTION_SUBSTAGE)
        {
            if (_isInitedDefaultSubstance == false)
            {
                SetNextSubstance();
                _isInitedDefaultSubstance = true;
            }
            DrawSelectedSubstance();
            HandleUserAction(action);
        }
        else if (_subStage == SUBSTANCE_SELECTED_SUBSTAGE)
        {
            if (_IsExitViewInited == false)
            {
                clear_display();
                set_cursor_position(1, 0);
                set_text_eng((char*)"Substance selected and saved");
                set_cursor_position(2, 0);
                set_text_eng((char*)"Press Enter To Exit");
                _IsExitViewInited = true;
            }
            HandleExitUserAction(action);
        }
        else if (_subStage == SUBSTANCE_NOT_SELECTED_SUBSTAGE)
        {
            if (_IsExitViewInited == false)
            {
                clear_display();
                set_cursor_position(1, 0);
                set_text_eng((char*)"Substance NOT selected");
                set_cursor_position(2, 0);
                set_text_eng((char*)"Press Enter To Exit");
                _IsExitViewInited = true;
            }
            HandleExitUserAction(action);
        }
    }
    
private:

    typedef enum
    {
        SUBSTANCE_SELECTION_SUBSTAGE,
        SUBSTANCE_SELECTED_SUBSTAGE,
        SUBSTANCE_NOT_SELECTED_SUBSTAGE,
    }SUBSTANCE_SELECTION_SUBSTAGE_t;
    
    SUBSTANCE_SELECTION_SUBSTAGE_t _subStage;
    
    ISubstanceServiceState * _substanceServiceState;
    
    SubstancesManager * _substanceManager;
    Substance_t * _selectedSubstance;
    Substance_t * _substancesList;
    
    bool _isInitedDefaultSubstance = false;
    
    bool _IsInintedsubstanceView = false;
    
    bool _IsExitViewInited = false;
    
    void DrawSelectedSubstance ()
    {
          if (_IsInintedsubstanceView == false)
          {
              clear_display();
              set_cursor_position(0, 0);
              DrawMultipleLinesRu((char*)_selectedSubstance->Name);
              set_cursor_position(2, 0);
              set_text_eng((char*)"Volume:");
              
              set_cursor_position(2, 8);
              char viewValue[6];
              sprintf(viewValue , "%.2f", _selectedSubstance->Volume_L);
              set_text_eng(viewValue);
              
              _IsInintedsubstanceView = true;
          }
          
    }
    void HandleUserAction(UserAction_t action)
    {
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;

        switch(action.buttonsEvent.id)
        {
            case BUT_UP:
            {
                _IsInintedsubstanceView = false;
                SetNextSubstance();
                break;
            }
            case BUT_DOWN:
            {
                _IsInintedsubstanceView = false;
                SetPreviousSubstance();
                break;
            }
            case BUT_ENTER:
            {
                _substanceManager->SetSelectedSubstance(_selectedSubstance->Id);
                _subStage = SUBSTANCE_SELECTED_SUBSTAGE;
                break;
            }
            case BUT_CANCEL:
            {
                _subStage = SUBSTANCE_NOT_SELECTED_SUBSTAGE;
            }
        }
    }
    
    void HandleExitUserAction(UserAction_t action)
    {
        if (action.buttonsEvent.event != BUTTON_SHORT_PRESSED_EVENT)
            return;
        
        switch(action.buttonsEvent.id)
        {
            case BUT_ENTER:
            {
                _IsInintedsubstanceView = false;
                _isInitedDefaultSubstance = false;
                _subStage = SUBSTANCE_SELECTION_SUBSTAGE;
                _substanceServiceState->ExitState();
                break;
            }
        }
    }
    
    void SetNextSubstance()
    {
        if (_selectedSubstance == NULL)
            _selectedSubstance = &(_substancesList[0]);
        
        for ( int i = GetSelectedSubstancePosition() + 1; i < 20; i++)
        {
            if (_substancesList[i].Id != 0)
            {
              _selectedSubstance = &_substancesList[i];
              break;
            }
        }
    }
    
    void SetPreviousSubstance()
    {
        if (_selectedSubstance == NULL)
            _selectedSubstance = &(_substancesList[0]);
        
        for ( int i = GetSelectedSubstancePosition() - 1; i >= 0; i--)
        {
            if (_substancesList[i].Id != 0)
            {
              _selectedSubstance = &_substancesList[i];
              break;
            }
        }
    }
    
    int GetSelectedSubstancePosition()
    {
        for ( int i = 0; i < 20; i++)
        {
            if (_substancesList[i].Id == _selectedSubstance->Id)
                return i;
        }
    }
    
    void DrawMultipleLinesRu(char * str)
    {
        if (strlen(str) > 20)
        {
            char firstLine[20];
            for (int i = 0; i < 20; i++)
              firstLine[i] = str[i];
            char* secondLine = str + 20;
            set_text_rus(firstLine);
            set_text_rus(secondLine);
        }
        else
        {
            set_text_rus(str);
        }
    }
};

#endif