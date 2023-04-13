#include "Game.h"
int main(int argc, char* argv[]) {
	const float FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	Game game;
	game.init("FirstGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 760, false);
	while (game.running()) {
		frameStart = SDL_GetTicks();
		game.handleEvent();
		game.update();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game.clean();
	return 0;
}