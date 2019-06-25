//1. Search:
			bool			bShowSalesText;
//1. Add after:
#ifdef ENABLE_FOG_FIX
			bool			bFogMode;
#endif


//1. Search:
		void							SetShowSalesTextFlag(int iFlag);
//1. Add after:
#ifdef ENABLE_FOG_FIX
		void							SetFogMode(int iFlag);
		bool							IsFogMode();
#endif