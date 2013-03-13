#include "TizenTodoFrame.h"
#include "TizenTodoFormFactory.h"
#include "TizenTodoPanelFactory.h"

using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;

TizenTodoFrame::TizenTodoFrame(void)
{
}

TizenTodoFrame::~TizenTodoFrame(void)
{
}

result
TizenTodoFrame::OnInitializing(void)
{
	// Prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static TizenTodoFormFactory formFactory;
	static TizenTodoPanelFactory panelFactory;
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->RegisterScene(L"workflow");

	// Goto the scene.
	result r = pSceneManager->GoForward(SceneTransitionId(L"ID_SCNT_1"));

	// TODO: Add your initialization code here
	return r;
}

result
TizenTodoFrame::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO:
	// Add your termination code here
	return r;
}
