#ifndef _TIZENTODOFRAME_H_
#define _TIZENTODOFRAME_H_

#include <FBase.h>
#include <FUi.h>


class TizenTodoFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	TizenTodoFrame(void);
	virtual ~TizenTodoFrame(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	// _TIZENTODOFRAME_H_
