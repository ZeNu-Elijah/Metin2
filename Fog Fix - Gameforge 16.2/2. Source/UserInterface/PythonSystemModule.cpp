//1. Search:
PyObject * systemSetShadowLevel(PyObject * poSelf, PyObject * poArgs)
{
	...
}
//1. Add after:
#ifdef ENABLE_FOG_FIX
PyObject * systemSetFogMode(PyObject * poSelf, PyObject * poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();

	CPythonSystem::Instance().SetFogMode(iFlag);

	return Py_BuildNone();
}

PyObject * systemIsFogMode(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsFogMode());
}
#endif


//2. Search:
		{ "SetShadowLevel",				systemSetShadowLevel,			METH_VARARGS },
//2. Add after:
#ifdef ENABLE_FOG_FIX
		{ "SetFogMode",				systemSetFogMode,				METH_VARARGS },
		{ "IsFogMode",				systemIsFogMode,				METH_VARARGS },
#endif