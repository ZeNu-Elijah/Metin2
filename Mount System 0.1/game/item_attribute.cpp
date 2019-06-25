///cautã:
	if (GetType() == ITEM_ARMOR || GetType() == ITEM_COSTUME)
	{
		switch (GetSubType())
		{
			case ARMOR_BODY:
//			case COSTUME_BODY: // ??? ??? ?? ??? ??? Attribute Set? ???? ???? ?? (ARMOR_BODY == COSTUME_BODY)
				return ATTRIBUTE_SET_BODY;

			case ARMOR_WRIST:
				return ATTRIBUTE_SET_WRIST;

			case ARMOR_FOOTS:
				return ATTRIBUTE_SET_FOOTS;

			case ARMOR_NECK:
				return ATTRIBUTE_SET_NECK;

			case ARMOR_HEAD:
//			case COSTUME_HAIR: // ??? ??? ?? ?? ???? ??? Attribute Set? ???? ???? ?? (ARMOR_HEAD == COSTUME_HAIR)
				return ATTRIBUTE_SET_HEAD;

			case ARMOR_SHIELD:
				return ATTRIBUTE_SET_SHIELD;

			case ARMOR_EAR:
				return ATTRIBUTE_SET_EAR;
		}

///modificã:
	if (GetType() == ITEM_ARMOR)
	{
		switch (GetSubType())
		{
			case ARMOR_BODY:
				return ATTRIBUTE_SET_BODY;

			case ARMOR_WRIST:
				return ATTRIBUTE_SET_WRIST;

			case ARMOR_FOOTS:
				return ATTRIBUTE_SET_FOOTS;

			case ARMOR_NECK:
				return ATTRIBUTE_SET_NECK;

			case ARMOR_HEAD:
				return ATTRIBUTE_SET_HEAD;

			case ARMOR_SHIELD:
				return ATTRIBUTE_SET_SHIELD;

			case ARMOR_EAR:
				return ATTRIBUTE_SET_EAR;	
		}
	}
	else if (GetType() == ITEM_COSTUME)
	{
		switch (GetSubType())
		{
			case COSTUME_BODY: // ??? ??? ?? ??? ??? Attribute Set? ???? ???? ?? (ARMOR_BODY == COSTUME_BODY)
				return ATTRIBUTE_SET_BODY;

			case COSTUME_HAIR: // ??? ??? ?? ?? ???? ??? Attribute Set? ???? ???? ?? (ARMOR_HEAD == COSTUME_HAIR)
				return ATTRIBUTE_SET_HEAD;

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			case COSTUME_MOUNT:
				break;
#endif
		}
	}