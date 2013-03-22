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
	// prepare Scene management.
	SceneManager* pSceneManager = SceneManager::GetInstance();
	static TizenTodoFormFactory formFactory;

	// register formfactory.
	pSceneManager->RegisterFormFactory(formFactory);

	// register scene.
	pSceneManager->RegisterScene(L"workflow");

	// go to the todo scene.
	result r = pSceneManager->GoForward(SceneTransitionId(L"ID_SCNT_1"));

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
