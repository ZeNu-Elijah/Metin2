// Search:
const char*	CPythonNonPlayer::GetMonsterName(DWORD dwVnum)
{
	...
}
// Add after:
bool CPythonNonPlayer::MonsterHasRaceFlag(DWORD dwVnum, const char * szSearchString)
{
	string raceFlagList[] = {
		"ANIMAL","UNDEAD","DEVIL","HUMAN","ORC","MILGYO","INSECT","FIRE","ICE","DESERT","TREE",
		"ATT_ELEC","ATT_FIRE","ATT_ICE","ATT_WIND","ATT_EARTH","ATT_DARK"
	};
	
	const CPythonNonPlayer::TMobTable * c_pTable = GetTable(dwVnum);
	if (!c_pTable)
		return false;
	
	DWORD dwRaceFlag = c_pTable->dwRaceFlag;
	
	if (dwRaceFlag == 0)
		return false;

	string toSearchString("");
	string searchString(szSearchString);
	int tmpFlag;
	
	for(int i = 0; i < sizeof(raceFlagList)/sizeof(raceFlagList[0]); i++)
	{
		tmpFlag = static_cast<int>(pow(2.0, static_cast<double>(i)));
		if (dwRaceFlag & tmpFlag)
		{
			if (!!toSearchString.compare(""))
				toSearchString += ",";
			toSearchString += raceFlagList[i];
		}
	}
	
    size_t found = toSearchString.find(searchString);
    if(found != string::npos){ 
        return true;
    }
	
	return false;
}