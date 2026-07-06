AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
	.byte 0

AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	end

AlteringCave_EventScript_Portal_Naruto::
	lock
	faceplayer
	msgbox AlteringCave_Text_NarutoPortal, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, AlteringCave_EventScript_CancelPortal
	playmoncry SPECIES_NARUTO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_NARUTO, 30
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedNarutoPortal
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_DefeatedNarutoPortal
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_DefeatedNarutoPortal
	release
	end

AlteringCave_EventScript_DefeatedNarutoPortal::
	setflag FLAG_DEFEATED_PORTAL_NARUTO
	goto Common_EventScript_RemoveStaticPokemon
	end

AlteringCave_EventScript_CancelPortal::
	msgbox AlteringCave_Text_LeftPortalAlone, MSGBOX_DEFAULT
	release
	end

AlteringCave_Text_NarutoPortal:
	.string "A strange, swirling rift of orange\n"
	.string "and blue energy floats here.\p"
	.string "Reach inside?$"

AlteringCave_Text_LeftPortalAlone:
	.string "Decided to leave the strange rift\n"
	.string "alone.$"
