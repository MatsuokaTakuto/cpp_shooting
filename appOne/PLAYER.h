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
        //�e�̔���

        VECTOR2 launcchVec;
        //���˂��Ă���̌o�ߎ���
        float triggerErapsedTime;
        //�o�ߎ��Ԃ��C���^�[�o���𒴂����甭�˂�����悤�ɂ���
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

