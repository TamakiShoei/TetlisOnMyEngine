#include "SceneManager.h"
#include "TitleScene.h"
#include "GameScene.h"
#include "ResultScene.h"

SceneManager* SceneManager::instance;

void SceneManager::Change(SceneKind scene)
{
	if (pScene != nullptr)
	{
		delete pScene;
	}

	switch (scene)
	{
	case SceneKind::TITLE:
		pScene = new TitleScene();
		break;

	case SceneKind::GAME:
		pScene = new GameScene();
		break;

	case SceneKind::RESULT:
		pScene = new ResultScene();
		break;
	}
}

void SceneManager::Initialize()
{
	pScene = nullptr;
	Change(SceneKind::TITLE);
}

void SceneManager::Update()
{
	SceneKind sceneKind;

	sceneKind = pScene->Main();
	
	if (sceneKind != pScene->GetKind())
	{
		Change(sceneKind);
	}
}

void SceneManager::Draw()
{
	pScene->Draw();
}