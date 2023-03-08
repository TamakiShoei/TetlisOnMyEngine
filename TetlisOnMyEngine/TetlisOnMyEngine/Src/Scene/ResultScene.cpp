#include "ResultScene.h"
#include "../../Engine/Engine.h"

ResultScene::ResultScene()
{

}

ResultScene::~ResultScene()
{

}

SceneKind ResultScene::Main()
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
	return SceneKind::RESULT;
}

void ResultScene::Draw()
{
	if (current_step == StepKind::RUN)
	{
		Engine::DrawTexture(0, 0, handle);
	}
}

void ResultScene::Init()
{
 	handle = Engine::LoadTexture("Res/Texture/GameOver.png");
	current_step = StepKind::RUN;
}

void ResultScene::Run()
{
	if (Engine::IsPushedKey(DIK_RETURN))
	{
		current_step = StepKind::FINISH;
	}
}

SceneKind ResultScene::Finish()
{
	current_step = StepKind::INIT;
	return SceneKind::TITLE;
}