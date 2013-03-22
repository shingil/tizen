#ifndef _TIZENTODO_MAIN_FORM_H_
#define _TIZENTODO_MAIN_FORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FIo.h>
#include "TizenTodoDataIO.h"

class TizenTodoMainForm
	: public Tizen::Ui::Controls::Form
	, public Tizen::Ui::IActionEventListener
	, public Tizen::Ui::Controls::IFormBackEventListener
 	, public Tizen::Ui::Scenes::ISceneEventListener
 	, public Tizen::Ui::Controls::IListViewItemEventListener
 	, public Tizen::Ui::Controls::IListViewItemProvider
{
public:
	TizenTodoMainForm(void);
	virtual ~TizenTodoMainForm(void);
	bool Initialize(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
									const Tizen::Ui::Scenes::SceneId& nextSceneId);

	 // IListViewItemEventListener
    virtual void OnListViewContextItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListContextItemStatus state);
    virtual void OnListViewItemStateChanged(Tizen::Ui::Controls::ListView &listView, int index, int elementId, Tizen::Ui::Controls::ListItemStatus status);
    virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView, int index, Tizen::Ui::Controls::SweepDirection direction);

	// IListViewItemProvider
    virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
    virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem, int itemWidth);
    virtual int GetItemCount(void);

	void HidePopup(Tizen::Ui::Controls::Popup* __pPopup);
	void ShowPopup(Tizen::Ui::Controls::Popup* __pPopup);

	void CreatePopup(void);
	void CreatePopup2(void);

private:
	static const int ID_BUTTON_CREATE = 101;
	static const int ID_BUTTON_DONE = 102;
	static const int ID_BUTTON_POPUP_OK = 103;
	static const int ID_BUTTON_POPUP_CANCEL = 104;
	static const int ID_BUTTON_POPUP2_DONE = 105;
	static const int ID_BUTTON_POPUP2_DELETE = 106;
	static const int ID_BUTTON_POPUP2_CANCEL = 107;

	Tizen::Ui::Controls::Popup *__pPopup;
	Tizen::Ui::Controls::Popup *__pPopup2;

	Tizen::Ui::Controls::ListView* __pListView;

	Tizen::Base::Collection::ArrayList* __pTodosList;

	Tizen::Ui::Controls::EditField *__pEditField;
	Tizen::Ui::Controls::Label *__pLabel;
	TizenTodoDataIO* __pDataIO;


	int selectIndex	;
};

#endif	//_TIZENTODO_MAIN_FORM_H_
