#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class BULLETS :
    public GAME_OBJECT
{
public:
    //�o���b�g�S�̂Ŏg�p����f�[�^
    struct DATA {
        int totalNum;
        int curNum;//���݂�Num
        int img;
        float advSpeed;
        float angSpeed;
        float bcRadius;//�G�ƒe�̓����蔻��
    };

private:
    DATA Bullet;//���ʃf�[�^

    //�e��̃f�[�^
    struct BULLET {
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };

    BULLET* Bullets;//�P�̃f�[�^�̔z��
protected:
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    void init();//�f�[�^�̏�����
    void launch(const VECTOR2& pos, const VECTOR2& vec);//�e�̔��ˏ���(���ˏꏊ�@���˕���)
    void update();//�e�𓮂���
    void kill(int i);//i�Ԗڂ̒e������
    void draw();//�e��\��������

    //�e�̏��getter
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    float bcRadius() { return Bullet.bcRadius; }
    //���݂̉�ʂɕ\������Ă���e�̐�
    int curNum() { return Bullet.curNum; }
};



