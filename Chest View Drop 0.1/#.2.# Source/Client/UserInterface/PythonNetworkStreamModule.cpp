// 1. Search:
PyObject* netRegisterErrorLog(PyObject* poSelf, PyObject* poArgs)
{
	char * szLog;
	if (!PyTuple_GetString(poArgs, 0, &szLog))
		return Py_BuildException();

	return Py_BuildNone();
}
// 1. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
PyObject* netSendChestDropInfo(PyObject* poSelf, PyObject* poArgs)
{
	int iSlotIndex;
	if (!PyTuple_GetInteger(poArgs, 0, &iSlotIndex))
		return Py_BadArgument();

	CPythonNetworkStream& rkNetStream = CPythonNetworkStream::Instance();
	rkNetStream.SendChestDropInfo(iSlotIndex);

	return Py_BuildNone();
}
#endif


// 2. Search:
		{ "RegisterErrorLog",						netRegisterErrorLog,						METH_VARARGS },
// 2. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
		{ "SendChestDropInfo",						netSendChestDropInfo,						METH_VARARGS },
#endif
