// 1. Go at the end of the file and add:

#ifdef ENABLE_SHOW_CHEST_DROP
#include "../libgame/include/grid.h"
void ITEM_MANAGER::GetChestItemList(DWORD dwChestVnum, std::vector<TChestDropInfoTable>& vec_item)
{
	TChestDropInfoTable kTempTab;
	
	BYTE dwChestDropPageCount = 5;

	CGrid* pGrids[dwChestDropPageCount];
	
	for (int i = 0; i < dwChestDropPageCount; ++i)
	{
		pGrids[i] = new CGrid(15, 5);
		pGrids[i]->Clear();
	}
	
	const CSpecialItemGroup* pGroup = GetSpecialItemGroup(dwChestVnum);
	
	if (pGroup)
	{
		for (int i = 0; i < pGroup->GetGroupSize(); i++)
		{
			const TItemTable* itemTable = GetTable(pGroup->GetVnum(i));

			if(itemTable != NULL)
			{
				for (int iPage = 0; iPage < dwChestDropPageCount; ++iPage)
				{
					int iPos = pGrids[iPage]->FindBlank(1, itemTable->bSize);
			
					if (iPos >= 0)
					{
						pGrids[iPage]->Put(iPos, 1, itemTable->bSize);
						
						kTempTab.bPageIndex = iPage + 1;
						kTempTab.bSlotIndex = iPos;
						
						kTempTab.bItemCount = pGroup->GetCount(i);
						kTempTab.dwItemVnum = pGroup->GetVnum(i);
						
						vec_item.push_back(kTempTab);
					
						break;
					}
				}
			}
		}
	}
}
#endif