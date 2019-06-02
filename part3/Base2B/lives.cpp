#include "lives.h"

Lives::Lives(int startingLives):
    currLives(startingLives) {
    for (int i = 1; i < 9; i++) {
        std::string spritePath = ":sprites/h" + std::to_string(i) + ".png";
        QPixmap sprite(QString::fromStdString(spritePath));
        digits[i] = sprite;
    }
}

void Lives::increment() {
    currLives++;
}

void Lives::decrement() {
        currLives--;
}

int Lives::getLives() {
    return currLives;
}

// Render score from left to right. Requires FILO reading of integer
void Lives::render(Renderer &renderer) {
    if(currLives>=0){
        renderer.draw(20, 20, digits[currLives-1]);
    }
}
