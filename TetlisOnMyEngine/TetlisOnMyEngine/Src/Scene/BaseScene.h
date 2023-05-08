#ifndef BASE_SCENE_
#define BASE_SCENE_

#include "SceneDefinition.h"

class BaseScene
{
public:
	BaseScene();
	virtual ~BaseScene();

	virtual SceneKind Main();
	virtual void Draw() = 0;
	virtual SceneKind GetKind() = 0;

protected:
	virtual void Init() = 0;
	virtual void Run() = 0;
	virtual SceneKind Finish() = 0;

protected:
	StepKind current_step;
	SceneKind m_myScene;


};

#endif