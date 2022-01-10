//
// Created by khalil on 1/9/22.
//
#include "../include/score.h"
#include <fstream>
#include <string>
#include <iostream>

void DoodleJump::Score::addScoreHeight() {
    score++;
}

void DoodleJump::Score::addScoreSpring() {
    score = score + 6;
}

void DoodleJump::Score::addScoreJetpack() {
    score = score + 7;
}

void DoodleJump::Score::subScoreStatic() {
    if(score-300<=0){
        score = 0;
    }
    else{
        score = score - 300;
    }
}

void DoodleJump::Score::subScoreHorizontal() {
    if(score-200<=0){
        score = 0;
    }
    else{
        score = score - 200;
    }
}

void DoodleJump::Score::subScoreVertical() {
    if(score-100<=0){
        score = 0;
    }
    else{
        score = score - 100;
    }
}

int DoodleJump::Score::getScore() const {
    return score;
}

void DoodleJump::Score::HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) {
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
    else if(s == horizontalcol){
        subScoreHorizontal();
    }
    else if(s == verticalcol){
        subScoreVertical();
    }
}

void DoodleJump::Score::checkhighscore() const {
    std::string highscore;
    std::ifstream MyFile("highscore.txt");
    bool check = false;
    while (std::getline(MyFile, highscore)) {
        if(!highscore.empty()){
            if(std::stoi(highscore)<score){
                check = true;
                break;
            }
        }
    }
    MyFile.close();
    if(check){
        std::ofstream file("highscore.txt");
        file << score;
        file.close();
    }
}

std::string DoodleJump::Score::getHighscore() {
    std::string highscore;
    std::ifstream MyFile("highscore.txt");
    while (std::getline(MyFile, highscore)) {
        if(highscore.empty()){
            return "0";
        }
        else{
            return highscore;
        }
    }
    return highscore;
}
