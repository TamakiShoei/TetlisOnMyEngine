#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include "BaseScene.h"

class GameScene : public BaseScene
{
public:
	GameScene();
	~GameScene();

	void Draw() override;

	void Init() override;
	void Run() override;
	SceneKind Finish() override;
	SceneKind GetKind() override { return SceneKind::GAME; }
};

#endif