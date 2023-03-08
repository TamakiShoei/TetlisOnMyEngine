#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include"BaseScene.h"
#include "SceneDefinition.h"

class SceneManager
{
public:
	static void CreateInstance()
	{
		instance = new SceneManager;
	}
	static SceneManager* GetInstance()
	{
		return instance;
	}
	static void DeleteInstance()
	{
		delete(instance);
	}

	void Initialize();
	void Update();
	void Draw();

private:
	SceneManager() = default;
	~SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&&) = delete;

	void Change(SceneKind scene);
private:
	static SceneManager* instance;
	BaseScene* pScene;
};

#endif