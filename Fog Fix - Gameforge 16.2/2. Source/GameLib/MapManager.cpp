// 1. Search:
void CMapManager::BlendEnvironmentData(const TEnvironmentData * c_pEnvironmentData, int iTransitionTime)
{
}
// 1. Add after:
#ifdef ENABLE_FOG_FIX
void CMapManager::SetEnvironmentFog(bool flag)
{	
	if (mc_pcurEnvironmentData)
	{
		mc_pcurEnvironmentData->bFogEnable = flag;
		ResetEnvironmentDataPtr(mc_pcurEnvironmentData);
	}
}
#endif