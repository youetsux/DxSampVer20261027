#include "DxLib.h"
#include "globals.h"
#include "input.h"
#include "chara.h"


// グローバル変数の定義,定数の定義
//ウィンドウサイズは1024×768
namespace
{
	//lemonchiffon
	const int BGCOLOR[3] = {255, 250, 205}; // 背景色{ 255, 250, 205 }; // 背景色
	int crrTime;
	int prevTime;
	
	//１匹目のキャラの初期座標
	int x = 50;
	int y = 300;
	//constを頭につけると定数になるよ
	const int SPEED = 2;//1フレーム２ピクセル進む
	const unsigned int CHAR1_COLOR = GetColor(173, 255, 47); // キャラクター1の色

	//もう一匹、下にキャラを追加して徒競走させよう。
	int x2 = 50;
	int y2 = 450;
	const int SPEED2 = 3;//1フレーム３ピクセル進む
	const unsigned int CHAR2_COLOR = GetColor(218, 112, 214); // キャラクター2の色

	//もう一匹、下にキャラを追加して徒競走させよう。
	int x3 = 50;
	int y3 = 150;
	const int SPEED3 = 1;//1フレーム３ピクセル進む
	const unsigned int CHAR3_COLOR = GetColor(218, 0, 214); // キャラクター3の色

	//もう一匹、下にキャラを追加して徒競走させよう。
	int x4 = 50;
	int y4 = 600;
	const int SPEED4 = 5;//1フレーム３ピクセル進む
	const unsigned int CHAR4_COLOR = GetColor(200, 10, 150); // キャラクター4の色

	const int CHAR_SIZE = 100; // キャラクターのサイズ
	Chara c1( x,  y, SPEED , CHAR1_COLOR, CHAR_SIZE);
	Chara c2(x2, y2, SPEED2, CHAR2_COLOR, CHAR_SIZE);
	Chara c3(x3, y3, SPEED3, CHAR3_COLOR, CHAR_SIZE);
	Chara c4(x4, y4, SPEED4, CHAR4_COLOR, CHAR_SIZE);
}


float gDeltaTime = 0.0f; // フレーム間の時間差

//DxLibの初期化処理
void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0],BGCOLOR[1],BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}

//ゲームの初期化処理
void Init()
{
	DxInit();
}

void Update()
{
	c1.Update();
	c2.Update();
	c3.SpeedUp();
	c3.Update();
	c4.Update();
}

void Draw()
{
	c1.Draw();
	c2.Draw();
	c3.Draw();
	c4.Draw();
}

void MyGame()
{
	//DrawFormatString(100, 100, GetColor(0, 0, 0), "ウィンドウのテスト");
	//static int timer = 0;//はじめだけ０で初期化して、後は覚えててくれる
	//timer++;
	//DrawFormatString(100, 150, GetColor(0, 0, 0), "%010d", timer);

	Update();
	Draw();
}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{

	Init();//初期化処理
	crrTime = GetNowCount();
	prevTime = GetNowCount();



	while (true)
	{
		ClearDrawScreen();
		Input::KeyStateUpdate(); // キー入力の状態を更新

		crrTime = GetNowCount(); // 現在の時間を取得
		// 前回の時間との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f; // 秒単位に変換
		gDeltaTime = deltaTime; // グローバル変数に保存

		//ここにやりたい処理を書く
		MyGame();


		ScreenFlip();
		WaitTimer(16);//時間調整

		prevTime = crrTime; // 現在の時間を前回の時間として保存

		if (ProcessMessage() == -1)
			break;
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}