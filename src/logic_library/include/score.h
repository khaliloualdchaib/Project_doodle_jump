//
// Created by khalil on 1/9/22.
//

#ifndef DOODLEJUMP_SCORE_H
#define DOODLEJUMP_SCORE_H
#include "observer_pattern/observer.h"
namespace DoodleJump{
    class Score: public DoodleJump::Observer{
    private:
        int score = 0;
    public:

        int getScore() const;

        Score() = default;

        void checkhighscore() const;

        static std::string getHighscore();

        void addScoreSpring();

        void addScoreJetpack();

        void addScoreHeight();

        void subScoreStatic();

        void subScoreHorizontal();

        void subScoreVertical();

        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
    };
}
#endif //DOODLEJUMP_SCORE_H
