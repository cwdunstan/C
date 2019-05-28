#include "swaprendererstage.h"
#include "debugrenderer.h"

SwapLevelStage::SwapLevelStage(std::unique_ptr<GameStage> stage) : GameStageDecorator(std::move(stage)), debug(false) {

}

void SwapLevelStage::input(QKeyEvent &event) {
    if (event.key() == Qt::Key_1) {
        debug = !debug;
    }
    GameStageDecorator::input(event);
}

void SwapRendererStage::render(Renderer &renderer) {
    if (!debug) {
        GameStageDecorator::render(renderer);
    } else {
        DebugRenderer drend(renderer.getPainter());
        GameStageDecorator::render(drend);
    }
}
