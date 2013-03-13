#ifndef _TIZEN_TODO_PANEL_FACTORY_H_
#define _TIZEN_TODO_PANEL_FACTORY_H_

#include <FUi.h>

class TizenTodoPanelFactory
	: public Tizen::Ui::Scenes::IPanelFactory
{
public:
	TizenTodoPanelFactory(void);
	virtual ~TizenTodoPanelFactory(void);

	virtual Tizen::Ui::Controls::Panel* CreatePanelN(const Tizen::Base::String& panelId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _FORMBASEDWITHSCENEMANAGER_PANEL_FACTORY_H_
