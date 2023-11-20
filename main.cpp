#include "SFMLDrawer.h"
#include <iostream>

int main() {

	std::cout << "App SFML Drawer\n";

	//===Description of buttons===//
	//Mouse::Left - add circle
	//Mouse::Right - switch off all the circles
	//Keyboard::Up/Right/Down/Left - move circles

	SFMLDrawer drawer;
	drawer.Run();

	return 0;
}