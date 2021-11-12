#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class BULLETS :
    public GAME_OBJECT
{
public:
    //バレット全体で使用するデータ
    struct DATA{
        int totalNum;
        //現在のNum
        int curNum;
        int img;
        float advSpeed;
        float angSpeed;
        //敵と弾の当たり判定
        float bcRadius;
    };
private:
    //共通データ
    DATA Bullet;

    //弾一つのデータ
    struct BULLET{
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };
    //単体データの配列
    BULLET* Bullets;

protected:
    //データを作るところ
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    //データの初期化
    void init();
    //弾の発射準備(発射場所　発射方向)
    void launch(const VECTOR2& pos, const VECTOR2& vec);
    //弾を動かす
    void update();
    //i番目の弾を消す
    void kill(int i);
    //弾を表示させる
    void draw();
};

