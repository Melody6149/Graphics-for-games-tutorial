#include "GraphicsApp.h"



int main() {
	GraphicsApp* app = new GraphicsApp(1920, 1080, "Game");
	
	app->run();

	delete app;

	return 0;
}
