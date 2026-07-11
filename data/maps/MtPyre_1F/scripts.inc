MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

MtPyre_1F_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KANTO_SABRINA, MtPyre_1F_EventScript_SabrinaDefeated
	msgbox MtPyre_1F_Text_SabrinaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MtPyre_1F_EventScript_SabrinaBattle
	msgbox MtPyre_1F_Text_SabrinaDecline, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_SabrinaBattle::
	msgbox MtPyre_1F_Text_SabrinaPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_SABRINA, MtPyre_1F_Text_SabrinaDefeat
	setflag FLAG_DEFEATED_KANTO_SABRINA
	giveitem ITEM_SPELL_TAG
	msgbox MtPyre_1F_Text_SabrinaRewardExplain, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_SabrinaDefeated::
	msgbox MtPyre_1F_Text_SabrinaDefeatedPost, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_Text_SabrinaIntro:
	.string "I am SABRINA, the GYM LEADER of Saffron\n"
	.string "City in the KANTO region.\p"
	.string "I felt a strong concentration of spiritual\n"
	.string "and psychic energy at this mountain...\p"
	.string "My psychic powers foresaw this meeting.\n"
	.string "Do you wish to battle me?$"

MtPyre_1F_Text_SabrinaDecline:
	.string "I see. I do not wish to use my powers\n"
	.string "unnecessarily either.$"

MtPyre_1F_Text_SabrinaPreBattle:
	.string "I dislike conflict, but if we must...$"

MtPyre_1F_Text_SabrinaDefeat:
	.string "Your mind's power exceeded my vision...$"

MtPyre_1F_Text_SabrinaRewardExplain:
	.string "That SPELL TAG boosts the power of\n"
	.string "GHOST-type moves.\p"
	.string "It resonates with this spooky place.$"

MtPyre_1F_Text_SabrinaDefeatedPost:
	.string "The spirits here are quiet today.\n"
	.string "We both paid our respects in battle.$"


