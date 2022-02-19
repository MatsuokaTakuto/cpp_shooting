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
        int baria;
        int img;
        VECTOR2 pos;
        VECTOR2 playerHp;
        float angle;
        float limmitW;
        float limmitH;
        float advSpeed;
        //�e�̔���

        //���˕���
        VECTOR2 launchVec;
        VECTOR2 launchVec1;
        VECTOR2 launchVec2;
        //���˂��Ă���̌o�ߎ���
        float triggerErapsedTime;
        //�o�ߎ��Ԃ��C���^�[�o���𒴂����甭�˂�����悤�ɂ���
        float triggerInterval;

        float ofstLaunchDist;

        //�Փ˗p�̔���collision
        float bcRadius;
        //���G����
        float invincibleTime;
        //�c�薳�G����
        float invincibleRestTime;
        int hp;
        VECTOR2 hpGaugeOfst;
        //�_�����󂯂����̐F�̕ω�
        COLOR collisionColor;
        COLOR normalColor;
        COLOR color;

        VECTOR2 playerbr;
        int br;
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


