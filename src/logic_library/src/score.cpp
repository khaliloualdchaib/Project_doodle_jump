//
// Created by khalil on 1/9/22.
//
#include "../include/score.h"
#include <cassert>
#include <iostream>
void DoodleJump::Score::addScoreHeight() {
    score++;
}

void DoodleJump::Score::addScoreSpring() {
    score = score + 3;
}

void DoodleJump::Score::addScoreJetpack() {
    score = score + 5;
}

void DoodleJump::Score::subScoreStatic() {
    if(score-1<=0){
        score = 0;
    }
    else{
        score--;
    }
}

void DoodleJump::Score::subScoreHorizontal() {
    if(score-2<=0){
        score = 0;
    }
    else{
        score = score - 2;
    }
}

void DoodleJump::Score::subScoreVertical() {
    if(score-3<=0){
        score = 0;
    }
    else{
        score = score - 3;
    }
}

int DoodleJump::Score::getScore() const {
    return score;
}

void DoodleJump::Score::HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) {
    //std::cout<<score<<std::endl;
    if(s == zero){
        return;
    }
    if(s == jetpackcol){
        addScoreJetpack();
    }
    else if(s == springcol){
        addScoreSpring();
    }
    else if(s == newHeight){
        addScoreHeight();
    }
    else if(s == staticcol){
        subScoreStatic();
    }
    /*
    else if(s == horizontalcol){
        subScoreHorizontal();
    }
    else if(s == verticalcol){
        subScoreVertical();
    }*/

}
