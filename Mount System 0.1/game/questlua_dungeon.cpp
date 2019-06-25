///cautã:
				if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))

///modificã:
				if (!pChar->IsPet() && !pChar->IsMount() && (true == pChar->IsMonster() || true == pChar->IsStone()))
