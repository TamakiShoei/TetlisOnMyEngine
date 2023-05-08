#include "GameScene.h"
#include "../FieldManager.h"
#include "../MinoGenerator.h"

GameScene::GameScene()
{
	m_myScene = SceneKind::GAME;
}

GameScene::~GameScene()
{

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