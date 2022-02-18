#pragma once
#include"libOne.h"
#include"ANIM.h"
#include "GAME_OBJECT.h"
class ORUGA :
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
    DATA Oruga;
public:
    ORUGA(class GAME* game);
    ~ORUGA();
    void create();
    void init();
    void update();
    void move();
    void launch();
    void collision();
    void draw();
    void set();
};

