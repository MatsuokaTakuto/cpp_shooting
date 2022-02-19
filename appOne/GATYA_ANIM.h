#pragma once
#include"libOne.h"
#include"ANIM.h"
#include "GAME_OBJECT.h"
class GATYA_ANIM:
    public GAME_OBJECT
{
public:
    struct DATA {
        class ANIM* anim = nullptr;
        ANIM_DATA animData;
        VECTOR2 pos;
        COLOR color;
    };
private:
    DATA GatyaAnim;
public:
    GATYA_ANIM(class GAME* game);
    ~GATYA_ANIM();
    void create();
    void init();
    void update();
    void move();
    void launch();
    void collision();
    void draw();
    void set();
};
