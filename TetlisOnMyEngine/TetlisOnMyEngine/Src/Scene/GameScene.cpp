#include "GameScene.h"
#include "../FieldManager.h"
#include "../MinoGenerator.h"

GameScene::GameScene()
{

}

GameScene::~GameScene()
{

}

SceneKind GameScene::Main()
{
	switch (current_step)
	{
	case StepKind::INIT:
		Init();
		break;

	case StepKind::RUN:
		Run();
		break;

	case StepKind::FINISH:
		return Finish();
		break;
	}
	return SceneKind::GAME;
}

void GameScene::Draw()
{
	if (current_step != StepKind::RUN)
	{
		return;
	}
	FieldManager::GetInstance()->Draw();
}

void GameScene::Init()
{
	FieldManager::GetInstance()->Initialize();
	MinoGenerator::GetInstance()->Initialize();

	current_step = StepKind::RUN;
}

void GameScene::Run()
{
	MinoGenerator::GetInstance()->Update();

	if (FieldManager::GetInstance()->GetIsGameOver() == true)
	{
		current_step = StepKind::FINISH;
	}
}

SceneKind GameScene::Finish()
{
	MinoGenerator::GetInstance()->Finalize();

	current_step = StepKind::INIT;
	return SceneKind::RESULT;
}