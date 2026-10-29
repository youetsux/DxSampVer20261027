#include "Chara.h"
#include "globals.h"
#include <DxLib.h>

void Chara::Move()
{
	if (x_ < WIN_WIDTH - size_)
		x_ = x_ + speed_;
}

Chara::Chara(int x, int y, int speed,
	unsigned int color, int size)
{
	x_ = x;
	y_ = y;
	speed_ = speed;
	color_ = color;
	size_ = size;
}

void Chara::Update()
{
	Move();
}

void Chara::Draw()
{
	DrawBox(x_, y_,
		x_ + size_, y_ + size_,
		color_, true);
}

//void Chara::SetSpeed(int speed)
//{
//	speed_ = speed;
//}

void Chara::SpeedUp()
{
	speed_ = speed_ + 1;
}
void Chara::SpeedDown()
{
	speed_ = speed_ - 1;
}