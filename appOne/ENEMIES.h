#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class ENEMIES :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        //����
        int totalNum;

        int curNum;
        //�G�l�~�[��ȉ~��ɕ��ׂ�
        //���̒���
        float majRadius;
        //�c�̒���
        float minRadius;
        //���S�_
        VECTOR2 centerPos;
        //���S�_���~��Ă���X�s�[�h
        float fallSpeed;
        //���S�_�̎~�܂�ʒu
        float targetPosX;
        //��p�x
        float refTheta;
        //��]����p�x�̑���
        float thetaSpeed;

        float triggerInterval;
        //���ˈʒu��ς���
        float ofstLaunchDist;


        //�Փ˗p�̔���collision
        float bcRadius;
        //���G����
        float invincibleTime;
        //�������p��hp
        int initHp;
        VECTOR2 hpGaugeOfst;
        //�_�����󂯂����̐F�̕ω�
        COLOR collisionColor;
        COLOR normalColor;

    };
private:
    //���ʃf�[�^
    DATA Enemy;
    //�P�̃f�[�^�̔z��
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta;
        //�g���K�[�������Čo�߂�������
        float triggerErapsedTime;
        //�c�薳�G����
        float invincibleRestTime;

        int hp;
        COLOR color;
    };
    ENEMY* Enemies;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();
    void move();
    void launch();
    void collision();
    void caunt();
    void draw();
    //getter
    int curNum() { return Enemy.curNum; }
};



