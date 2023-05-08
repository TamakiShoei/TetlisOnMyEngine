#include "TitleScene.h"
#include "../../Engine/Engine.h"

TitleScene::TitleScene()
{
	m_myScene = SceneKind::TITLE;
}

TitleScene::~TitleScene()
{

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