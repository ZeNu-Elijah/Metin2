//1. Search:
	m_Config.bShowSalesText		= true;
//1. Add after:
#ifdef ENABLE_FOG_FIX
	m_Config.bFogMode			= false;
#endif


//2. Search:
void CPythonSystem::SetShowSalesTextFlag(int iFlag)
{
	m_Config.bShowSalesText = iFlag == 1 ? true : false;
}
//2. Add after:
#ifdef ENABLE_FOG_FIX
void CPythonSystem::SetFogMode(int iFlag)
{
	m_Config.bFogMode = iFlag == 1 ? true : false;
}

bool CPythonSystem::IsFogMode()
{
	return m_Config.bFogMode;
}
#endif


//3. Search:
		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;
//3. Add after:
#ifdef ENABLE_FOG_FIX
		else if (!stricmp(command, "FOG_MODE_ON"))
			m_Config.bFogMode = atoi(value) == 1 ? true : false;
#endif


//4. Search:
	if (m_Config.bShowSalesText == 0)
		fprintf(fp, "SHOW_SALESTEXT		%d\n", m_Config.bShowSalesText);
//4. Add after:
#ifdef ENABLE_FOG_FIX
	if (m_Config.bFogMode == 0)
		fprintf(fp, "FOG_MODE_ON		%d\n", m_Config.bFogMode);
#endif
