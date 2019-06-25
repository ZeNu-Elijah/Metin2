//1. Search:
#include "../mileslib/SoundManager.h"
//1. Add after:
#include "../UserInterface/Locale_inc.h"


//2. Search:
	BOOL bFogEnable;
//2. Replace with:
#ifdef ENABLE_FOG_FIX
	mutable BOOL bFogEnable;
#else
	BOOL bFogEnable;
#endif