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

        /**
         * Getter for score.
         * @return score
         */
        int getScore() const;

        /**
         * Default score
         */
        Score() = default;

        /**
         * checks and changes the high score if needed.
         */
        void checkhighscore() const;

        /**
         * Getter for high score
         * @return high score, it is saved in highscore.txt
         */
        static std::string getHighscore();

        /**
         * Adding to the score for hitting a spring.
         */
        void addScoreSpring();

        /**
         * Adding to the score for taking a jetpack
         */
        void addScoreJetpack();

        /**
         * Adding to the score for reaching a new height.
         */
        void addScoreHeight();

        /**
         *  Subtracting from the score for jumping from a static platform that the player already jumped from.
         */
        void subScoreStatic();

        /**
         *  Subtracting from the score for jumping from a horizontal platform that the player already jumped from.
         */
        void subScoreHorizontal();

        /**
         *  Subtracting from the score for jumping from a vertical platform that the player already jumped from.
         */
        void subScoreVertical();
         /**
          * Handles an event.
          * @param nextpos: This argument does nothing for this observer.
          * @param s: Gives how the score should be updated.
          */
        void HandleEvent(std::tuple<float, float> nextpos, scoreUpdate s) override;
    };
}
#endif //DOODLEJUMP_SCORE_H
