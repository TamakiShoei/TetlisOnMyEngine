#include "BaseScene.h"

BaseScene::BaseScene() : current_step(StepKind::INIT)
{
}

BaseScene::~BaseScene()
{

}

SceneKind BaseScene::Main()
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
	return m_myScene;
}
