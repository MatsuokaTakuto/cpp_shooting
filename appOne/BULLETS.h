#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class BULLETS :
    public GAME_OBJECT
{
public:
    //�o���b�g�S�̂Ŏg�p����f�[�^
    struct DATA{
        int totalNum;
        //���݂�Num
        int curNum;
        int img;
        float advSpeed;
        float angSpeed;
        //�G�ƒe�̓����蔻��
        float bcRadius;
    };
private:
    //���ʃf�[�^
    DATA Bullet;

    //�e��̃f�[�^
    struct BULLET{
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };
    //�P�̃f�[�^�̔z��
    BULLET* Bullets;

protected:
    //�f�[�^�����Ƃ���
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    //�f�[�^�̏�����
    void init();
    //�e�̔��ˏ���(���ˏꏊ�@���˕���)
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    //�e�𓮂���
    void update();
    //i�Ԗڂ̒e������
    void kill(int i);
    //�e��\��������
    void draw();
};

