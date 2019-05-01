#include "stickman.h"
#include <QMessageBox>

using namespace std;

void Stickman::setCoordinate(Coordinate coordinate) {
    this->coordinate = coordinate;
}

void Stickman::setSize(string size) {
    this->size = size;
}

// Resize stickman based on size attribute
void Stickman::setSprite(string path) {
    QPixmap newSprite(QString::fromStdString(path));
    if (size.compare("tiny") == 0) {
        sprite = newSprite.scaledToHeight(24);
    } else if(size.compare("normal") == 0) {
        sprite = newSprite.scaledToHeight(48);
    } else if(size.compare("large") == 0) {
        sprite = newSprite.scaledToHeight(72);
    } else {
        sprite = newSprite.scaledToHeight(96);
    }
}

// Draw and update stickman position
void Stickman::render(QPainter &painter, unsigned int time) {
    if(jumping!=0){
        if(!djump){
        //normal jump
        if(jumping<sprite.height()*1.8 && !falling){
            jumping= jumping +5;
            curJump=jumping;
        }
        else{
            falling = true;
        }
        if(falling){
            if(jumping-7>0){
                if(maxJumps<1){
                    jumping=jumping-5;
                }else{
                    jumping=jumping-7;
                }
                curJump=jumping;
            }else{
                jumping=0;
                curJump=jumping;
                falling=false;
            }
          }
       }
        //double jump
       else{
            if(jumping<sprite.height()*1.8+curJump && maxJumps<1){
                jumping= jumping +5;

            }else{
                maxJumps++;
                falling = true;
                djump=false;
            }
        }

        coordinate.setYCoordinate(initalY+jumping);
    }

    painter.drawPixmap(coordinate.getQtRenderingXCoordinate(), coordinate.getQtRenderingYCoordinate() - sprite.height(), sprite);

    string spritePath = ":sprite";
    this->setSprite(spritePath.append(std::to_string((time/5)%2)).append(".png"));
}

void Stickman::jump(){
    if(jumping==0){
        initalY=coordinate.getYCoordinate();
        jumping=1;
        maxJumps=0;
    }else{
        djump=true;
    }
}
