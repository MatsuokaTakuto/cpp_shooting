#pragma once
#include "SCENE.h"
class GAME_OVER :
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
    DATA GameOver;
public:
    GAME_OVER(class GAME* game);
    ~GAME_OVER();
    void init();
    void update();
    void draw();
    void back();
    void nextScene();
};

