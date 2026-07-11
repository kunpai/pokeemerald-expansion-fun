GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "That guy who came by earlier…\n"
	.string "STEVEN, I think it was.\p"
	.string "He knew how to use FLASH, so he ought\n"
	.string "to be all right, but…\p"
	.string "Well, for us HIKERS, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Here you go, I'll pass this on to you.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Teach that hidden move FLASH to\n"
	.string "a POKéMON and use it.\p"
	.string "It lights up even the inky darkness\n"
	.string "of caves.\p"
	.string "But, to use it, you need the GYM BADGE\n"
	.string "from DEWFORD's POKéMON GYM.$"

GraniteCave_1F_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KANTO_BROCK, GraniteCave_1F_EventScript_BrockDefeated
	msgbox GraniteCave_1F_Text_BrockIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GraniteCave_1F_EventScript_BrockBattle
	msgbox GraniteCave_1F_Text_BrockDecline, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_BrockBattle::
	msgbox GraniteCave_1F_Text_BrockPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_BROCK, GraniteCave_1F_Text_BrockDefeat
	setflag FLAG_DEFEATED_KANTO_BROCK
	giveitem ITEM_HARD_STONE
	msgbox GraniteCave_1F_Text_BrockRewardExplain, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_BrockDefeated::
	msgbox GraniteCave_1F_Text_BrockDefeatedPost, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_BrockIntro:
	.string "I am BROCK, the GYM LEADER of Pewter\n"
	.string "City in the KANTO region.\p"
	.string "I travel to other regions to study rock\n"
	.string "formations in deep caves like this.\p"
	.string "Tell me, does your bond with your POKéMON\n"
	.string "have the hardness of rock?\l"
	.string "Would you like to battle me?$"

GraniteCave_1F_Text_BrockDecline:
	.string "I see. If you do not have the resolve,\n"
	.string "you cannot move me.$"

GraniteCave_1F_Text_BrockPreBattle:
	.string "Show me your determination!$"

GraniteCave_1F_Text_BrockDefeat:
	.string "Your determination is harder than\n"
	.string "any rock I've ever faced!$"

GraniteCave_1F_Text_BrockRewardExplain:
	.string "That HARD STONE boosts the power of\n"
	.string "ROCK-type moves.\p"
	.string "Keep polishing your strength!$"

GraniteCave_1F_Text_BrockDefeatedPost:
	.string "Granite Cave has a wonderful layer\n"
	.string "of stones. It was worth coming here.$"
