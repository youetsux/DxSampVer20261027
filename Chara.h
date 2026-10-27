#pragma once
class Chara
{
public:
	int x_;
	int y_;
	int speed_;
	unsigned int color_;
	int size_;
	Chara(int x, int y, int speed,
		unsigned int color, int size);
	void Update();
	void Draw();
};

