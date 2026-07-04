LittlerootTown_Gym_MapScripts::
	.byte 0

LittlerootTown_Gym_EventScript_LeaderWebb::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LITTLEROOT_LEADER, LittlerootTown_Gym_EventScript_WebbPostBattle
	msgbox LittlerootTown_Gym_Text_WebbIntro, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_LITTLEROOT_LEADER, LittlerootTown_Gym_Text_WebbIntro, LittlerootTown_Gym_Text_WebbDefeat, LittlerootTown_Gym_EventScript_WebbDefeated, NO_MUSIC
	release
	end

LittlerootTown_Gym_EventScript_WebbDefeated::
	setflag FLAG_DEFEATED_LITTLEROOT_LEADER
	msgbox LittlerootTown_Gym_Text_ExplainReward, MSGBOX_DEFAULT
	giveitem ITEM_SILVER_POWDER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LittlerootTown_Gym_Text_WebbOutro, MSGBOX_DEFAULT
	release
	end

LittlerootTown_Gym_EventScript_WebbPostBattle::
	msgbox LittlerootTown_Gym_Text_WebbPostBattle, MSGBOX_DEFAULT
	release
	end

LittlerootTown_Gym_Text_WebbIntro:
	.string "Welcome to the Littleroot Gym!\n"
	.string "My name is WEBB, and I specialize\n"
	.string "in BUG-type POKéMON.\p"
	.string "People often overlook BUG POKéMON,\n"
	.string "but their synergy and speed will\n"
	.string "tangle you up in no time!\p"
	.string "Show me what you and your POKéMON\n"
	.string "can do!$"

LittlerootTown_Gym_Text_WebbDefeat:
	.string "Incredible!\n"
	.string "Your strategy was completely unbroken!$"

LittlerootTown_Gym_Text_ExplainReward:
	.string "That was an amazing battle.\n"
	.string "You've earned this special item!$"

LittlerootTown_Gym_Text_WebbOutro:
	.string "SILVER POWDER boosts the power of\n"
	.string "BUG-type moves when held by a POKéMON.\p"
	.string "Keep training hard, and you will\n"
	.string "go far!$"

LittlerootTown_Gym_Text_WebbPostBattle:
	.string "BUG POKéMON teach us that even the\n"
	.string "smallest creatures can grow to be\n"
	.string "incredibly strong.$"
