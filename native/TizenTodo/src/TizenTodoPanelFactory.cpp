#include "TizenTodoPanelFactory.h"
#include <FUi.h>

using namespace Tizen::Ui::Scenes;


TizenTodoPanelFactory::TizenTodoPanelFactory(void)
{
}

TizenTodoPanelFactory::~TizenTodoPanelFactory(void)
{
}

Tizen::Ui::Controls::Panel*
TizenTodoPanelFactory::CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	Tizen::Ui::Controls::Panel* pNewPanel = null;

	// TODO:
	// Add your panel creation code here
	return pNewPanel;
}
