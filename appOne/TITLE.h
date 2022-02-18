#pragma once
#include "SCENE.h"
#include"ANIM.h"
#include"libOne.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        int img = 0;
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        //charは4の倍数で用意するといい1つのメモリが4バイトごとだから
        char str[16];
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game);
    ~TITLE();
    void create();
    void back();
    void init();
    void draw();
    void nextScene();
};

