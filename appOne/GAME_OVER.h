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
        //char��4�̔{���ŗp�ӂ���Ƃ���1�̃�������4�o�C�g���Ƃ�����
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

