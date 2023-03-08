#include "TitleScene.h"
#include "../../Engine/Engine.h"

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}

SceneKind TitleScene::Main()
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
	return SceneKind::TITLE;
}

void TitleScene::Draw()
{
	if (current_step != StepKind::RUN)
	{
		return;
	}
	Engine::DrawTexture(0, 0, backGround);
}

void TitleScene::Init()
{
	backGround = Engine::LoadTexture("Res/Texture/Title.png");

	current_step = StepKind::RUN;
}

void TitleScene::Run()
{
	if (Engine::IsPushedKey(DIK_RETURN) == true)
	{
		current_step = StepKind::FINISH;
	}
}

SceneKind TitleScene::Finish()
{

	current_step = StepKind::INIT;
	return SceneKind::GAME;
}