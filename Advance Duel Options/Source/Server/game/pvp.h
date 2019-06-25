//01 : Search :

DWORD 	GetCRC() { return m_dwCRC; }

//01 Add after :

#ifdef ENABLE_DUEL_OPTIONS
		void	SetSpecialDuelStatus(bool bStatus) { m_bIsSpecialDuel = bStatus; }
		bool	IsSpecialDuel() { return m_bIsSpecialDuel; }
		bool	IsRevenge() { return m_bRevenge; }
#endif

// 02 : Search :

	protected:
		TPlayer	m_players[2];
		DWORD	m_dwCRC;
		bool	m_bRevenge;
		
// 02 : Add after :

#ifdef ENABLE_DUEL_OPTIONS
		bool	m_bIsSpecialDuel;
#endif


//03. Search :

void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim);

//04 : Replace with :

#ifdef ENABLE_DUEL_OPTIONS
	void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim, bool bSpecialDuelStatus);
	bool 			IsSpecialDuel(LPCHARACTER pkChr, LPCHARACTER pkVictim);
#else
	void			Insert(LPCHARACTER pkChr, LPCHARACTER pkVictim);
#endif

