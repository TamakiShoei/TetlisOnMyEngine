#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
	TitleScene();
	~TitleScene();

	SceneKind Main() override;
	void Draw() override;

	void Init() override;
	void Run() override;
	SceneKind Finish() override;
	SceneKind GetKind() override { return SceneKind::TITLE; }

private:
	int backGround;
};

#endif