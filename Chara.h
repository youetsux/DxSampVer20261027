#pragma once
class Chara
{
public:
	Chara(int x, int y, int speed,
		unsigned int color, int size);
	void Update();
	void Draw();
	//void SetSpeed(int speed);
	int GetSize() { return size_; }
	//スピードを1だけ上げる関数
	void SpeedUp();
	//スピードを1だけ下げる関数
	void SpeedDown();
private:
	int x_;
	int y_;
	int speed_;
	unsigned int color_;
	int size_;
	void Move();
};

