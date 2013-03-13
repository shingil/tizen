/*
 * TizenTodo.h
 *
 *  Created on: Mar 12, 2013
 *      Author: shingilkang
 */
#include <FBase.h>
#include <FIo.h>

#ifndef TIZENTODODATAIO_H_
#define TIZENTODODATAIO_H_

class TizenTodoDataIO {
public:
	TizenTodoDataIO();
	virtual ~TizenTodoDataIO();

	bool WriteFile(const Tizen::Base::String& strFilePath, const Tizen::Base::String& strFileContents);
	bool ReadFile(const Tizen::Base::String& strFilePath, Tizen::Base::String& strFileContents);

	void SetDoneWork(Tizen::Base::String& done);
	Tizen::Base::String GetDoneWork();

	//static wchar_t* test;
	static Tizen::Base::String test2;

private:


};

#endif /* TIZENTODODATAIO_H_ */



