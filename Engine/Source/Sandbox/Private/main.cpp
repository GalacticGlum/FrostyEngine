#include <iostream>
#include <FrostyCore.h>
#include <Game.h>

#include <IrrKlang/irrKlang.h>

int main(int argc, char *argv[])
{
	Application::Launch("Frosty Engine", 800, 600, (GameInstance*)new Game());
	return 0;
}