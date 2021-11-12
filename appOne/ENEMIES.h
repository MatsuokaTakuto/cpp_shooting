#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class ENEMIES :
    public GAME_OBJECT
{
public:
    struct DATA {
        int img;
        //総数
        int totalNum;
    //エネミーを楕円上に並べる
        //横の長さ
        float majRadius;
        //縦の長さ
        float minRadius;
        //中心点
        VECTOR2 centerPos;
        //中心点が降りてくるスピード
        float fallSpeed;
        //中心点の止まる位置
        float targetPosY;
        //基準角度
        float refTheta;
        //回転する角度の速さ
        float thetaSpeed;
    };
private:
    //共通データ
    DATA Enemy;
    //単体データの配列
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

