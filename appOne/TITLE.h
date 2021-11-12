#pragma once
#include "SCENE.h"
#include"libOne.h"
class TITLE :
    public SCENE
{
public:
    struct DATA {
        COLOR backColor;
        COLOR textColor;
        float textSize;
        VECTOR2 pos;
        //char��4�̔{���ŗp�ӂ���Ƃ���1�̃�������4�o�C�g���Ƃ�����
        char str[16];
    };
private:
    DATA Title;
public:
    TITLE(class GAME* game); 
    ~TITLE();
    void create();
    void draw();
    void nextScene();
};

