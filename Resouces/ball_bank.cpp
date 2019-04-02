#include "ball_bank.h"

Ball_Bank* Ball_Bank::p = nullptr;

Ball_Bank::Ball_Bank()
{

}

QPixmap *Ball_Bank::getBallImage(int in)
{
    switch (in) {
    case Object::bai:{
        return instance()->white;
    }
    case Object::fen:{
        return instance()->pink;
    }
    case Object::lan:{
        return instance()->blue;
    }
    case Object::hong:{
        return instance()->red;
    }
    case Object::zong:{
        return instance()->brown;
    }
    case Object::huang:{
    return instance()->yellow;
    }
    case Object::lv:{
    return instance()->green;
    }
    case Object::hei:{
    return instance()->black;
    }
    }
    return nullptr;
}

Ball_Bank *Ball_Bank::instance()
{
    if(p==nullptr) p = new Ball_Bank;
    return p;
}
