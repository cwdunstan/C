#include "lives.h"

Lives::Lives(int startingLives):
    currLives(startingLives) {
    for (int i = 0; i < 10; i++) {
        std::string spritePath = ":sprites/" + std::to_string(i) + ".png";
        QPixmap sprite(QString::fromStdString(spritePath));
        digits[i] = sprite;
    }
}

void Lives::increment() {
    currLives++;
}

void Lives::decrement() {
    if(currLives>0){
        currLives--;
    }
}

// Render score from left to right. Requires FILO reading of integer
void Lives::render(Renderer &renderer) {
    if(currLives>0){
        renderer.draw(20, 20, digits[currLives]);
    }
}
