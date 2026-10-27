#include "Chara.h"
#include "globals.h"
#include <DxLib.h>

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
	if (x_ < WIN_WIDTH - size_)
		x_ = x_ + speed_;
}

void Chara::Draw()
{
	DrawBox(x_, y_,
		x_ + size_, y_ + size_,
		color_, true);
}

