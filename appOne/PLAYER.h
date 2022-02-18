#pragma once
#include"libOne.h"
#include"ANIM.h"
#include "GAME_OBJECT.h"
class PLAYER :
    public GAME_OBJECT
{
public:
    struct DATA {
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        int img;
        VECTOR2 pos;
        VECTOR2 playerHp;
        float angle;
        float limmitW;
        float limmitH;
        float advSpeed;
        //弾の発射

        //発射方向
        VECTOR2 launchVec;
        //発射してからの経過時間
        float triggerErapsedTime;
        //経過時間がインターバルを超えたら発射させるようにする
        float triggerInterval;

        float ofstLaunchDist;

        //衝突用の判定collision
        float bcRadius;
        //無敵時間
        float invincibleTime;
        //残り無敵時間
        float invincibleRestTime;
        int hp;
        VECTOR2 hpGaugeOfst;
        //ダメを受けた時の色の変化
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;
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
    void collision();
    void draw();
    VECTOR2 pos() { return Player.pos; }
    int hp() { return Player.hp; }
};


