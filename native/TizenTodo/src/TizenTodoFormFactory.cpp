#include "TizenTodoFormFactory.h"
#include "TizenTodoMainForm.h"
#include "TizenTodoDoneForm.h"

using namespace Tizen::Ui::Scenes;


TizenTodoFormFactory::TizenTodoFormFactory(void)
{
}

TizenTodoFormFactory::~TizenTodoFormFactory(void)
{
}

Tizen::Ui::Controls::Form*
TizenTodoFormFactory::CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Form* pNewForm = null;

	if (formId == L"IDF_FORM")
	{
		TizenTodoMainForm* pForm = new TizenTodoMainForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}
	else if (formId == L"IDF_DONE_FORM")
	{
		TizenTodoDoneForm* pForm = new TizenTodoDoneForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
		pNewForm = pForm;
	}

	// TODO:
	// Add your form creation code here

	return pNewForm;
}
