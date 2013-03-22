#ifndef TIZENTODODONEFORM_H_
#define TIZENTODODONEFORM_H_

#include <FBase.h>
#include <FUi.h>
#include "TizenTodoDataIO.h"

class TizenTodoDoneForm: public Tizen::Ui::Controls::Form,
		public Tizen::Ui::IActionEventListener,
		public Tizen::Ui::Controls::IFormBackEventListener,
		public Tizen::Ui::Scenes::ISceneEventListener,
		public Tizen::Ui::Controls::IListViewItemEventListener,
		public Tizen::Ui::Controls::IListViewItemProvider {

// Construction
public:
	TizenTodoDoneForm(void);
	virtual ~TizenTodoDoneForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Generated call-back functions
public:
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);

	virtual void OnSceneActivatedN(
			const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);


	virtual void OnActionPerformed(const Tizen::Ui::Control& source,
			int actionId);


	// IListViewItemEventListener
	virtual void OnListViewContextItemStateChanged(
			Tizen::Ui::Controls::ListView &listView, int index, int elementId,
			Tizen::Ui::Controls::ListContextItemStatus state);
	virtual void OnListViewItemStateChanged(
			Tizen::Ui::Controls::ListView &listView, int index, int elementId,
			Tizen::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView,
			int index, Tizen::Ui::Controls::SweepDirection direction);

	// IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index,
			int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem,
			int itemWidth);
	virtual int GetItemCount(void);

	void HidePopup(Tizen::Ui::Controls::Popup* __pPopup);
	void ShowPopup(Tizen::Ui::Controls::Popup* __pPopup);

	void CreatePopup(void);

private:
	static const int ID_BUTTON_TODO = 101;
	static const int ID_BUTTON_POPUP_OK = 102;
	static const int ID_BUTTON_POPUP_CANCEL = 103;

	Tizen::Ui::Controls::Popup *__pPopup;
	Tizen::Ui::Controls::ListView* __pListView;
	Tizen::Base::Collection::ArrayList* __pDoneList;
	Tizen::Ui::Controls::Label *__pLabel;
	TizenTodoDataIO* __pDataIO;

	int selectIndex;
};

#endif
