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

        int curNum;
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
        float targetPosX;
        //基準角度
        float refTheta;
        //回転する角度の速さ
        float thetaSpeed;

        float triggerInterval;
        //発射位置を変える
        float ofstLaunchDist;


        //衝突用の判定collision
        float bcRadius;
        //無敵時間
        float invincibleTime;
        //初期化用のhp
        int initHp;
        VECTOR2 hpGaugeOfst;
        //ダメを受けた時の色の変化
        COLOR collisionColor;
        COLOR normalColor;

    };
private:
    //共通データ
    DATA Enemy;
    //単体データの配列
    struct ENEMY {
        VECTOR2 pos;
        float ofstTheta;
        //トリガーを押して経過した時間
        float triggerErapsedTime;
        //残り無敵時間
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



