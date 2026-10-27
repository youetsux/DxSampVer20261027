#pragma once

//XGA SIZE
const int WIN_WIDTH = 1024; // ウィンドウ幅
const int WIN_HEIGHT = 768; // ウィンドウ高さ

extern float gDeltaTime; // フレーム間の時間差

inline float GetDeltaTime()
{
	return gDeltaTime;
}