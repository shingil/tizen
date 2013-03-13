#ifndef _TIZENTODOFORMFACTORY_H_
#define _TIZENTODOFORMFACTORY_H_

#include <FUi.h>

class TizenTodoFormFactory
	: public Tizen::Ui::Scenes::IFormFactory
{
public:
	TizenTodoFormFactory(void);
	virtual ~TizenTodoFormFactory(void);

	virtual Tizen::Ui::Controls::Form* CreateFormN(const Tizen::Base::String& formId, const Tizen::Ui::Scenes::SceneId& sceneId);
};

#endif // _TIZENTODOFORMFACTORY_H_
