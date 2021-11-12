#pragma once
#include"libOne.h"
#include "GAME_OBJECT.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        VECTOR2 pos;
        float angle;
        float limmitW;
        float limmitH;
        float advSpeed;
        //弾の発射

        VECTOR2 launcchVec;
        //発射してからの経過時間
        float triggerErapsedTime;
        //経過時間がインターバルを超えたら発射させるようにする
        float triggerInterval;
    };
private:
    DATA Player;
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void create();
    void init();
    void update();
        void move();
        void launch();
    void draw();
};

