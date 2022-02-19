#pragma once
#include"libOne.h"
#include "SCENE.h"
class GATYA :
    public SCENE
{
public:
    struct DATA {
        int p2 = 0;
        int img = 0;
        int yosieimg = 0;
        int gatyaimg = 0;
        VECTOR2 pos;
        COLOR color;
        int caunt;
        int gatyacaunt;
    };
private:
    DATA Gatya;
public:
    GATYA(class GAME* game);
    ~GATYA();
    void create();
    void init();
    void update();
    void draw();
    void nextScene();
    void result();
    void gatyaimg();
    int gatyacaunt() { return Gatya.gatyacaunt; }
};

