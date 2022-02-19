#pragma once
#include "SCENE.h"
#include"libOne.h"
class GAME_CLEAR :
    public SCENE
{
public:
    struct DATA {
        int clear = 0;
        int img = 0;
        int img2 = 0;
        int img3 = 0;
        int img4 = 0;
        int img5= 0;
        int backimg = 0;
        int caunt = 0;
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        float rX = 0;
        float rY = 0;
        float RX = 0;
        float RY = 0;
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

