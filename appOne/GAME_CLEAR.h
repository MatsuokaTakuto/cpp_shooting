#pragma once
#include "SCENE.h"
#include"libOne.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        int img = 0;
        int backimg = 0;
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        //charは4の倍数で用意するといい1つのメモリが4バイトごとだから
        char str[16];
    };
private:
    DATA GameClear;
public:
    GAME_CLEAR(class GAME* game);
    ~GAME_CLEAR();
    void back();
    void init();
    void draw();
    void nextScene();
};

