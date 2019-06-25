// 1. Search:
#ifdef M2_USE_POOL
#include "pool.h"
#endif
// 1. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
#include "packet.h"
#endif


// 2. Search:
		static void		CopyAllAttrTo(LPITEM pkOldItem, LPITEM pkNewItem);
// 2. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
		void 			GetChestItemList(DWORD dwChestVnum, std::vector<TChestDropInfoTable>& vec_item);
#endif

// 2. Search:
		DWORD GetAttrVnum(DWORD dwVnum) const
		{
			
		}
// 2. Add after:
#ifdef ENABLE_SHOW_CHEST_DROP
		int GetGroupSize() const
		{
			return m_vecProbs.size();
		}
#endif