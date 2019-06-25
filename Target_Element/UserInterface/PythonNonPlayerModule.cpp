// Search:
PyObject * nonplayerLoadNonPlayerData(PyObject * poSelf, PyObject * poArgs)
{
	...
}
// Add after:
PyObject * nonplayerGetVnumByVID(PyObject * poSelf, PyObject * poArgs)
{
	int iVirtualID;
	if (!PyTuple_GetInteger(poArgs, 0, &iVirtualID))
		return Py_BuildException();

	CInstanceBase * pInstance = CPythonCharacterManager::Instance().GetInstancePtr(iVirtualID);

	if (!pInstance)
		return Py_BuildValue("i", -1);

	const CPythonNonPlayer::TMobTable * pMobTable = CPythonNonPlayer::Instance().GetTable(pInstance->GetVirtualNumber());

	if (!pMobTable)
		return Py_BuildValue("i", -1);

	return Py_BuildValue("i", pMobTable->dwVnum);
}

PyObject * nonplayerMonsterHasRaceFlag(PyObject * poSelf, PyObject * poArgs)
{
	int iVNum;
	if (!PyTuple_GetInteger(poArgs, 0, &iVNum))
		return Py_BuildException();
	
	char * szRaceFlag;
	if(!PyTuple_GetString(poArgs, 1, &szRaceFlag))
		return Py_BuildException();

	CPythonNonPlayer& rkNonPlayer=CPythonNonPlayer::Instance();
	return Py_BuildValue("b", rkNonPlayer.MonsterHasRaceFlag(iVNum, szRaceFlag));
}


// Search:
		{ "GetMonsterName",				nonplayerGetMonsterName,			METH_VARARGS },
// Add after:
		{ "GetVnumByVID",				nonplayerGetVnumByVID,				METH_VARARGS },
		{ "MonsterHasRaceFlag",			nonplayerMonsterHasRaceFlag,		METH_VARARGS },