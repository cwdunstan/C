#ifndef SWAPLEVELSTAGE_H
#define SWAPLEVELSTAGE_H

#include "gamestagedecorator.h"

class SwapLevelStage : public GameStageDecorator {
public:
    SwapLevelStage(std::unique_ptr<GameStage> stage1, std::unique_ptr<GameStage> stage2 );

    void render(Renderer &renderer);
    void input(QKeyEvent &event);

private:
    /**
     * @brief debug A flag for the debug rendering mode.
     */
    bool debug;
};

#endif // SWAPLEVELSTAGE_H
