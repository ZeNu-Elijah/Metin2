//1. Search:
PyObject * backgroundDisableGuildArea(PyObject * poSelf, PyObject * poArgs)
{
	CPythonBackground::Instance().DisableGuildArea();
	return Py_BuildNone();
}
//1. Add after:
#ifdef ENABLE_FOG_FIX
PyObject * backgroundSetEnvironmentFog(PyObject * poSelf, PyObject * poArgs)
{
	bool bFlag;
	if (!PyTuple_GetBoolean(poArgs, 0, &bFlag))
		return Py_BadArgument();

	CPythonBackground& rkBG=CPythonBackground::Instance();
	rkBG.SetEnvironmentFog(bFlag);
		
	return Py_BuildNone();
}
#endif


//2. Search:
		{ "DisableGuildArea",					backgroundDisableGuildArea,					METH_VARARGS },
//2. Add after:
#ifdef ENABLE_FOG_FIX
		{ "SetEnvironmentFog",					backgroundSetEnvironmentFog,				METH_VARARGS }, 
#endif