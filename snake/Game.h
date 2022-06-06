#pragma once
class Game
{
public:
	Game() {
		this->mode = 0;
	}

	Game(int &mode) {
		this->mode = mode;
	}
private:
	int mode;
};

