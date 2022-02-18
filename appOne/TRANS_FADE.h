#pragma once
#include"libOne.h"
#include "TRANS.h"
class TRANS_FADE :
    public TRANS
{
public:
    struct DATA {
        COLOR color;
        float time = 0;
    };
private:
    DATA Trans;
public:
    TRANS_FADE(class GAME* game);
    void create();
    void inTriggerProc();
    bool inProc();
    void outTriggerProc();
    bool outProc();
};