#include <FApp.h>
#include <FBaseLog.h>
#include "TizenTodoDoneForm.h"

using namespace Tizen::Base;
using namespace Tizen::App;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Graphics;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Utility;

TizenTodoDoneForm::TizenTodoDoneForm(void) : __pDoneList(null)
{
}

TizenTodoDoneForm::~TizenTodoDoneForm(void)
{
}

bool
TizenTodoDoneForm::Initialize()
{
	Construct(L"IDF_DONE_FORM");

	return true;
}

result
TizenTodoDoneForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Setup back event listener
	SetFormBackEventListener(this);

	Tizen::Ui::Controls::Button *pButtonOk = static_cast<Button*>(GetControl(L"IDC_BUTTON1"));
	if (pButtonOk != null)
	{
		pButtonOk->SetActionId(ID_BUTTON_TODO);
		pButtonOk->AddActionEventListener(*this);
	}

	// create list view
	__pListView = static_cast<ListView*>(GetControl(L"IDC_LISTVIEW1"));
	__pListView->SetItemProvider(*this);
	__pListView->AddListViewItemEventListener(*this);
	__pDoneList = new (std::nothrow) ArrayList();

	// read done works list from file
	String strFileContents;
	String filePath = App::GetInstance()->GetAppDataPath() + L"donelist.txt";

	__pDataIO = new (std::nothrow) TizenTodoDataIO();
	__pDataIO->ReadFile(filePath, strFileContents);

	StringTokenizer st(strFileContents, String(L"\n"));
	String token;

	while(st.HasMoreTokens())
	{
		st.GetNextToken(token);
		__pDoneList->Add(new (std::nothrow) String(token));
		__pListView->UpdateList();
	}

	CreatePopup();

	return r;
}

result
TizenTodoDoneForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	String filePath = App::GetInstance()->GetAppDataPath() + L"donelist.txt";

	String strFileContents;

	for(int i=0; i<__pDoneList->GetCount(); i++){
		String* todo = static_cast<String*>(__pDoneList->GetAt(i));
		strFileContents.Append(todo->GetPointer());
		strFileContents.Append("\n");
	}
	__pDataIO->WriteFile(filePath, strFileContents);

	return r;
}

/* Create Popup
 * You can delete unnecessary done work.
 * This popup has ok, cancel button.
 */
void
TizenTodoDoneForm::CreatePopup(void) {
	// create popup
	__pPopup = new (std::nothrow) Popup();
	__pPopup->Construct(true, Dimension(600, 450));
	__pPopup->SetTitleText(L"Delete the work ?");

	Rectangle rect;
	rect = __pPopup->GetClientAreaBounds();

	// create label
	__pLabel = new (std::nothrow) Label();
	__pLabel->Construct(Rectangle(50, 50, 500, 100), L"");
	__pPopup->AddControl(*__pLabel);

	// create "ok" button
	Button *pButtonOK = new (std::nothrow) Button();
	pButtonOK->Construct(Rectangle(50, 230, 150, 74), L"OK");
	pButtonOK->SetActionId(ID_BUTTON_POPUP_OK);
	pButtonOK->AddActionEventListener(*this);
	__pPopup->AddControl(*pButtonOK);

	// create "cancel" button
	Button *pButtonCancel = new (std::nothrow) Button();
	pButtonCancel->Construct(Rectangle(350, 230, 150, 74), L"Cancel");
	pButtonCancel->SetActionId(ID_BUTTON_POPUP_CANCEL);
	pButtonCancel->AddActionEventListener(*this);
	__pPopup->AddControl(*pButtonCancel);
}


void
TizenTodoDoneForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
								const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	// TODO: Add your implementation codes here
	if(!(__pDataIO->selectedDoneWork.IsEmpty())){
			__pDoneList->Add(new String(__pDataIO->selectedDoneWork.GetPointer()));
			__pListView->UpdateList();
			__pDataIO->selectedDoneWork = L"";
	}
}

void
TizenTodoDoneForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{
	// TODO: Add your implementation codes here
}

void
TizenTodoDoneForm::ShowPopup(Popup* __pPopup) {
	String* done = static_cast<String*>(__pDoneList->GetAt(selectIndex));
	__pLabel->SetText(done->GetPointer());
	__pPopup->SetShowState(true);
	__pPopup->Show();
}

void
TizenTodoDoneForm::HidePopup(Popup* __pPopup) {
	__pPopup->SetShowState(false);
	Invalidate(true);
}

void
TizenTodoDoneForm::OnActionPerformed(const Tizen::Ui::Control& source, int actionId)
{

	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	switch(actionId)
	{
	// go to todo screen.
	case ID_BUTTON_TODO:
		pSceneManager->GoForward(SceneTransitionId(L"ID_SCNT_3"));
		break;

	// remove done from list.
	case ID_BUTTON_POPUP_OK:
		__pDoneList->RemoveAt(selectIndex);
		__pListView->UpdateList();
		HidePopup(__pPopup);
		break;

	case ID_BUTTON_POPUP_CANCEL:
		// cancel to delete done.
		HidePopup(__pPopup);
		break;

	default:
		break;
	}
}

/*
 *  When user press back button, go to the before screen.
 */
void
TizenTodoDoneForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	pSceneManager->GoBackward(BackwardSceneTransition());
}


void
TizenTodoDoneForm::OnListViewContextItemStateChanged(
			Tizen::Ui::Controls::ListView &listView, int index, int elementId,
			Tizen::Ui::Controls::ListContextItemStatus state)
{
}
void
TizenTodoDoneForm::OnListViewItemStateChanged(
			Tizen::Ui::Controls::ListView &listView, int index, int elementId,
			Tizen::Ui::Controls::ListItemStatus status)
{
	if (status == LIST_ITEM_STATUS_SELECTED) {
		selectIndex = index;
		ShowPopup(__pPopup);
	}
}

void
TizenTodoDoneForm::OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView,
			int index, Tizen::Ui::Controls::SweepDirection direction)
{
}

Tizen::Ui::Controls::ListItemBase* TizenTodoDoneForm::CreateItem(int index,
			int itemWidth)
{
	SimpleItem* pItem = new SimpleItem();
	AppAssert(pItem);

	String* done = static_cast<String*>(__pDoneList->GetAt(index));

	pItem->Construct(Dimension(itemWidth, 50), LIST_ANNEX_STYLE_NORMAL);
	pItem->SetElement(*done);

	return pItem;
}

bool
TizenTodoDoneForm::DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem,
			int itemWidth)
{
	delete pItem;
	pItem = null;
	return true;
}

int
TizenTodoDoneForm::GetItemCount(void)
{
	if (__pDoneList) {
		return __pDoneList->GetCount();
	} else {
		return 0;
	}
}
