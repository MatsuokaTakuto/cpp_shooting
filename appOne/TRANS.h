#pragma once
#include "GAME_OBJECT.h"
class TRANS :
    public GAME_OBJECT
{
private:
    enum class STATE {
        IN_TRIGGER, IN_NOW, IN_END,
        OUT_TRIGGER, OUT_NOW, OUT_END
    };
    STATE State;
public:
    TRANS(class GAME* game);
    virtual ~TRANS();
    virtual void create();
    void inTrigger();
    void outTrigger();
    void draw();
    virtual void inTriggerProc();
    virtual bool inProc();
    virtual void outTriggerProc();
    virtual bool outProc();
    bool inEndFlag();
    bool outEndFlag();
};

