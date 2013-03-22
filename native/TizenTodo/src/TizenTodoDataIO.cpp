/*
 * FileIO.cpp
 *
 *  Created on: Mar 12, 2013
 *      Author: shingilkang
 */

#include "TizenTodoDataIO.h"
using namespace Tizen::Base;
using namespace Tizen::Io;

String TizenTodoDataIO::selectedDoneWork(L"");

TizenTodoDataIO::TizenTodoDataIO() {
	// TODO Auto-generated constructor stub
}


TizenTodoDataIO::~TizenTodoDataIO() {
	// TODO Auto-generated destructor stub
}

/* Write string type contents to file */
bool
TizenTodoDataIO::WriteFile(const String& strFilePath, const String& strFileContents)
{
	File file;

	result r = file.Construct(strFilePath, "w");
	if (IsFailed(r))
	{
		AppLog("File::Construct() is failed by %s", GetErrorMessage(r));
		return false;
	}

	r = file.Write(strFileContents);
	if (IsFailed(r))
	{
		AppLog("File::Write() is failed by %s", GetErrorMessage(r));
		return false;
	}
	return true;
}

/* Read string type contents from file */
bool
TizenTodoDataIO::ReadFile(const String& strFilePath, String& strFileContents)
{
	strFileContents = L"";

	File file;

	result r = file.Construct(strFilePath, "r");
	TryReturn(!IsFailed(r), false, "File::Consturct() is failed with %s", GetErrorMessage(r));

	FileAttributes fileAttrs;
	file.GetAttributes(strFilePath, fileAttrs);
	long long size = fileAttrs.GetFileSize();

	ByteBuffer readBuffer;
	readBuffer.Construct(static_cast< int >(size + 1));

	r = file.Read(readBuffer);
	TryReturn(!IsFailed(r), false, "File::Read() is failed with %s", GetErrorMessage(r));

	readBuffer.Flip();

	strFileContents = String(reinterpret_cast< const char* >(readBuffer.GetPointer()));

	return true;
}
