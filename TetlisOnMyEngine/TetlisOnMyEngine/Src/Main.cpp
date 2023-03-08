#include "../Engine/Engine.h"
#include "FieldManager.h"
#include "MinoGenerator.h"
#include "Mino.h"
#include "Scene/SceneManager.h"

void GameProcessing();
void DrawProcessing();

//メイン関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int)
{
	Engine::SetWindowSize(800, 600);

	if (Engine::Initialize() == false)	//DirectXの初期化
	{
		Engine::Finalize();
		return 0;
	}

	FieldManager::CreateInstance();
	MinoGenerator::CreateInstance();
	SceneManager::CreateInstance();
	SceneManager::GetInstance()->Initialize();

	while (Engine::IsClosedWindow() == false)
	{
		Engine::Update();
	
		GameProcessing();

		Engine::ClearScreen();

		DrawProcessing();

		Engine::ScreenFlip();
	}

	FieldManager::DeleteInstance();
	MinoGenerator::GetInstance()->Finalize();
	MinoGenerator::DeleteInstance();
	SceneManager::DeleteInstance();

	Engine::Finalize();
	return 0;
}

void GameProcessing()
{
	SceneManager::GetInstance()->Update();
}

void DrawProcessing()
{
	SceneManager::GetInstance()->Draw();
}
