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
        float targetPosY;
        //��p�x
        float refTheta;
        //��]����p�x�̑���
        float thetaSpeed;
    };
private:
    //���ʃf�[�^
    DATA Enemy;
    //�P�̃f�[�^�̔z��
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta;
    };
    ENEMY* Enemies;
public:
    ENEMIES(class GAME* game);
    ~ENEMIES();
    void create();
    void init();
    void update();
    void draw();
};

