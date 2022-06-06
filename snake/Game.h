#pragma once
class Game
{
public:
	Game() {
		this->mode = 0;
		this->fruitsCount = 10;
		this->speed = 50;
	}

	Game(int mode, int fruitsCount, int speed) {
		this->mode = mode;
		this->fruitsCount = fruitsCount;
		this->speed = speed;
	}

	void Start() {
	    

	}

	void setMode(int mode) {
		this->mode = mode;
	}

	int getMode(int mode) {
		return this->mode;
	}

private:
	int mode;
	int fruitsCount;
	int speed;
};

