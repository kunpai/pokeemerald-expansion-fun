NewMauville_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Entrance_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Entrance_OnTransition
	.byte 0

NewMauville_Entrance_OnLoad:
	call_if_eq VAR_NEW_MAUVILLE_STATE, 0, NewMauville_Entrance_EventScript_CloseDoor
	end

NewMauville_Entrance_EventScript_CloseDoor::
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile0, TRUE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile1, TRUE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Closed_Tile2, TRUE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile4, TRUE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Closed_Tile5, TRUE
	return

NewMauville_Entrance_OnTransition:
	setflag FLAG_LANDMARK_NEW_MAUVILLE
	end

NewMauville_Entrance_EventScript_Door::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox NewMauville_Entrance_Text_DoorIsLocked, MSGBOX_DEFAULT
	checkitem ITEM_BASEMENT_KEY
	goto_if_eq VAR_RESULT, FALSE, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UseBasementKey, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, NewMauville_Entrance_EventScript_DontOpenDoor
	msgbox NewMauville_Entrance_Text_UsedBasementKey, MSGBOX_DEFAULT
	setmetatile 3, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile0, FALSE
	setmetatile 4, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile1, FALSE
	setmetatile 5, 0, METATILE_Facility_NewMauvilleDoor_Open_Tile2, FALSE
	setmetatile 3, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile3, TRUE
	setmetatile 4, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile4, FALSE
	setmetatile 5, 1, METATILE_Facility_NewMauvilleDoor_Open_Tile5, TRUE
	special DrawWholeMapView
	playse SE_BANG
	setvar VAR_NEW_MAUVILLE_STATE, 1
	releaseall
	end

NewMauville_Entrance_EventScript_DontOpenDoor::
	releaseall
	end

NewMauville_Entrance_Text_DoorIsLocked:
	.string "The door is locked.$"

NewMauville_Entrance_Text_UseBasementKey:
	.string "Use the BASEMENT KEY?$"

NewMauville_Entrance_Text_UsedBasementKey:
	.string "{PLAYER} used the BASEMENT KEY.\p"
	.string "The door opened!$"

NewMauville_Entrance_EventScript_LtSurge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_KANTO_SURGE, NewMauville_Entrance_EventScript_LtSurgeDefeated
	msgbox NewMauville_Entrance_Text_LtSurgeIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewMauville_Entrance_EventScript_LtSurgeBattle
	msgbox NewMauville_Entrance_Text_LtSurgeDecline, MSGBOX_DEFAULT
	release
	end

NewMauville_Entrance_EventScript_LtSurgeBattle::
	msgbox NewMauville_Entrance_Text_LtSurgePreBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LEADER_LT_SURGE, NewMauville_Entrance_Text_LtSurgeDefeat
	setflag FLAG_DEFEATED_KANTO_SURGE
	giveitem ITEM_MAGNET
	msgbox NewMauville_Entrance_Text_LtSurgeRewardExplain, MSGBOX_DEFAULT
	release
	end

NewMauville_Entrance_EventScript_LtSurgeDefeated::
	msgbox NewMauville_Entrance_Text_LtSurgeDefeatedPost, MSGBOX_DEFAULT
	release
	end

NewMauville_Entrance_Text_LtSurgeIntro:
	.string "Hey there, kid! I'm LT. SURGE, the Lightning\n"
	.string "American! KANTO's electric GYM LEADER!\p"
	.string "I heard this generator place here is full\n"
	.string "of raw power! I love it!\p"
	.string "You think your team's got enough spark?\n"
	.string "Let's go, baby! Battle me!$"

NewMauville_Entrance_Text_LtSurgeDecline:
	.string "No guts, huh? In the army, we don't retreat!$"

NewMauville_Entrance_Text_LtSurgePreBattle:
	.string "Ten-hut! You're in for a shock!$"

NewMauville_Entrance_Text_LtSurgeDefeat:
	.string "Whoa, kid! You really zapped me!$"

NewMauville_Entrance_Text_LtSurgeRewardExplain:
	.string "That MAGNET boosts the power of ELECTRIC-\n"
	.string "type moves. Carry it with pride!$"

NewMauville_Entrance_Text_LtSurgeDefeatedPost:
	.string "New Mauville is a shocker of a place.\n"
	.string "I might hang around here a bit more!$"
