#include <iostream>
#include <FrostyCore.h>
#include <Game.h>

int main(int argc, char *argv[])
{
	Game* game = new Game();
	Application::Launch(800, 600, (GameInstance*)game);

	return 0;
}