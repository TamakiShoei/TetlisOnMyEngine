#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include "BaseScene.h"

class ResultScene : public BaseScene
{
public:
	ResultScene();
	~ResultScene();

	SceneKind Main() override;
	void Draw() override;

	void Init() override;
	void Run() override;
	SceneKind Finish() override;
	SceneKind GetKind() override { return SceneKind::RESULT; }

private:
	int handle = 0;
};

#endif