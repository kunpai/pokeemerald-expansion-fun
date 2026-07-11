FieryPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
	.byte 0

FieryPath_OnTransition:
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
	setflag FLAG_LANDMARK_FIERY_PATH
	end

FieryPath_EventScript_MoveScottToFallarbor::
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	return

FieryPath_EventScript_Koga::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KANTO_KOGA, FieryPath_EventScript_KogaDefeated
	msgbox FieryPath_Text_KogaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FieryPath_EventScript_KogaBattle
	msgbox FieryPath_Text_KogaDecline, MSGBOX_DEFAULT
	release
	end

FieryPath_EventScript_KogaBattle::
	msgbox FieryPath_Text_KogaPreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_KOGA, FieryPath_Text_KogaDefeat
	setflag FLAG_DEFEATED_KANTO_KOGA
	giveitem ITEM_BLACK_SLUDGE
	msgbox FieryPath_Text_KogaRewardExplain, MSGBOX_DEFAULT
	release
	end

FieryPath_EventScript_KogaDefeated::
	msgbox FieryPath_Text_KogaDefeatedPost, MSGBOX_DEFAULT
	release
	end

FieryPath_Text_KogaIntro:
	.string "Fwahahaha! I am KOGA of the KANTO Elite\n"
	.string "Four, former GYM LEADER of Fuchsia City!\p"
	.string "The hot, toxic vapors of this Fiery Path\n"
	.string "are excellent for honing ninja techniques!\p"
	.string "Would you dare challenge my toxic ninja\n"
	.string "arts in battle?$"

FieryPath_Text_KogaDecline:
	.string "Hmph. True ninjas wait for the right\n"
	.string "moment. Very well.$"

FieryPath_Text_KogaPreBattle:
	.string "Taste the toxic fury of my shadows!$"

FieryPath_Text_KogaDefeat:
	.string "Impossible! You saw through my illusions!$"

FieryPath_Text_KogaRewardExplain:
	.string "That BLACK SLUDGE slowly heals POISON-\n"
	.string "type POKéMON, but hurts others.\p"
	.string "A true ninja tool! Use it wisely!$"

FieryPath_Text_KogaDefeatedPost:
	.string "Your battle style has great precision.\n"
	.string "Perhaps you could learn the way of shadows.$"


