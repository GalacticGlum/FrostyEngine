#include <iostream>
#include <FrostyCore.h>
#include <Game.h>

int main(int argc, char *argv[])
{
	Application::CreateContext("Frosty Engine", 800, 600);
	Application::Launch((GameInstance*)new Game());

	return 0;
}