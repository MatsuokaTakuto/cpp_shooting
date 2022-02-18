#pragma once
#include "GAME_OBJECT.h"
#include"libOne.h"
class BULLETS :
    public GAME_OBJECT
{
public:
    //バレット全体で使用するデータ
    struct DATA {
        int totalNum;
        int curNum;//現在のNum
        int img;
        float advSpeed;
        float angSpeed;
        float bcRadius;//敵と弾の当たり判定
    };

private:
    DATA Bullet;//共通データ

    //弾一つのデータ
    struct BULLET {
        VECTOR2 pos;
        VECTOR2 vec;
        float angle;
    };

    BULLET* Bullets;//単体データの配列
protected:
    void SetBullets(const BULLETS::DATA& data);
public:
    BULLETS(class GAME* game);
    ~BULLETS();
    void init();//データの初期化
    void launch(const VECTOR2& pos, const VECTOR2& vec);//弾の発射準備(発射場所　発射方向)
    void update();//弾を動かす
    void kill(int i);//i番目の弾を消す
    void draw();//弾を表示させる

    //弾の情報getter
    VECTOR2 pos(int i) { return Bullets[i].pos; }
    float bcRadius() { return Bullet.bcRadius; }
    //現在の画面に表示されている弾の数
    int curNum() { return Bullet.curNum; }
};



