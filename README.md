# Project doodle jump Khalil Ouald Chaib
Compile and run
* ./build.sh
* ./run.sh

Game Description
* The goal of the game is to go as high as possible.
* You can only move left and right and the player jumps without any user input.
* There are bonuses that give you a jump boost.
* There are 4 types of platforms:
  * Static platform (green platform) &#8594; these are just normal platforms.
  * Temporary platform (white platform) &#8594; after jumping once on these platforms, it will disappear.
  * Horizontal platform (blue platform) &#8594; these platforms keep moving horizontally across the whole window.
  * Vertical platform (yellow platform) &#8594; these platforms keep moving a certain distance vertically.
* A player can move left or right through the window and will then spawn on the opposite side.

Score system
* Jumping more than once on the same platform gives you minus points depending on the platform.
  * Static platform: -300 points
  * Vertical platform: -100 points
  * Horizontal platform: -200 points
* If the minus point makes the score negative, score will just reset to 0.
* Bonus:
  * Spring: +6 points
  * jetpack: +7 points
* Everytime the player's y coordinate is above or equal to 0, you will gain +1 point (this means the player has reached a new height).

Controls
* Left arrow key: The player moves left.
* Right arrow key: The player moves right.
