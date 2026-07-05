StarterGifts_EventScript_Gen1Gen2NPC::
	lock
	faceplayer
	goto_if_set FLAG_GIFT_STARTER_GEN1_GEN2, StarterGifts_EventScript_Gen1Gen2NPC_Done
	msgbox StarterGifts_Text_Gen1Gen2Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Decline
	msgbox StarterGifts_Text_ChooseRegion, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Kanto, StarterGifts_Text_Johto, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_ChooseKanto
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_ChooseJohto
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_ChooseKanto:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Bulbasaur, StarterGifts_Text_Charmander, StarterGifts_Text_Squirtle, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveBulbasaur
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveCharmander
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GiveSquirtle
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveBulbasaur:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_BULBASAUR
	goto StarterGifts_EventScript_GiveStarter_Gen1Gen2
	end

StarterGifts_EventScript_GiveCharmander:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHARMANDER
	goto StarterGifts_EventScript_GiveStarter_Gen1Gen2
	end

StarterGifts_EventScript_GiveSquirtle:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SQUIRTLE
	goto StarterGifts_EventScript_GiveStarter_Gen1Gen2
	end

StarterGifts_EventScript_ChooseJohto:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Chikorita, StarterGifts_Text_Cyndaquil, StarterGifts_Text_Totodile, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveChikorita
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveCyndaquil
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GiveTotodile
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveChikorita:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIKORITA
	goto StarterGifts_EventScript_GiveStarter_Gen1Gen2
	end

StarterGifts_EventScript_GiveCyndaquil:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CYNDAQUIL
	goto StarterGifts_EventScript_GiveStarter_Gen1Gen2
	end

StarterGifts_EventScript_GiveTotodile:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TOTODILE
	goto StarterGifts_EventScript_GiveStarter_Gen1Gen2
	end

StarterGifts_EventScript_GiveStarter_Gen1Gen2:
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, StarterGifts_EventScript_ReceiveParty_Gen1Gen2
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, StarterGifts_EventScript_ReceivePC_Gen1Gen2
	goto Common_EventScript_NoMoreRoomForPokemon
	end

StarterGifts_EventScript_ReceiveParty_Gen1Gen2:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Received_Gen1Gen2
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto StarterGifts_EventScript_Received_Gen1Gen2
	end

StarterGifts_EventScript_ReceivePC_Gen1Gen2:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_TransferredToPC_Gen1Gen2
	call Common_EventScript_NameReceivedBoxMon
	goto StarterGifts_EventScript_TransferredToPC_Gen1Gen2
	end

StarterGifts_EventScript_TransferredToPC_Gen1Gen2:
	call Common_EventScript_TransferredToPC
	goto StarterGifts_EventScript_Received_Gen1Gen2
	end

StarterGifts_EventScript_Received_Gen1Gen2:
	setflag FLAG_GIFT_STARTER_GEN1_GEN2
	release
	end

StarterGifts_EventScript_Gen1Gen2NPC_Done:
	msgbox StarterGifts_Text_Gen1Gen2Done, MSGBOX_DEFAULT
	release
	end


StarterGifts_EventScript_Gen4Gen5NPC::
	lock
	faceplayer
	goto_if_set FLAG_GIFT_STARTER_GEN4_GEN5, StarterGifts_EventScript_Gen4Gen5NPC_Done
	msgbox StarterGifts_Text_Gen4Gen5Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Decline
	msgbox StarterGifts_Text_ChooseRegion, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Sinnoh, StarterGifts_Text_Unova, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_ChooseSinnoh
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_ChooseUnova
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_ChooseSinnoh:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Turtwig, StarterGifts_Text_Chimchar, StarterGifts_Text_Piplup, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveTurtwig
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveChimchar
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GivePiplup
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveTurtwig:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TURTWIG
	goto StarterGifts_EventScript_GiveStarter_Gen4Gen5
	end

StarterGifts_EventScript_GiveChimchar:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIMCHAR
	goto StarterGifts_EventScript_GiveStarter_Gen4Gen5
	end

StarterGifts_EventScript_GivePiplup:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_PIPLUP
	goto StarterGifts_EventScript_GiveStarter_Gen4Gen5
	end

StarterGifts_EventScript_ChooseUnova:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Snivy, StarterGifts_Text_Tepig, StarterGifts_Text_Oshawott, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveSnivy
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveTepig
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GiveOshawott
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveSnivy:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SNIVY
	goto StarterGifts_EventScript_GiveStarter_Gen4Gen5
	end

StarterGifts_EventScript_GiveTepig:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_TEPIG
	goto StarterGifts_EventScript_GiveStarter_Gen4Gen5
	end

StarterGifts_EventScript_GiveOshawott:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_OSHAWOTT
	goto StarterGifts_EventScript_GiveStarter_Gen4Gen5
	end

StarterGifts_EventScript_GiveStarter_Gen4Gen5:
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, StarterGifts_EventScript_ReceiveParty_Gen4Gen5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, StarterGifts_EventScript_ReceivePC_Gen4Gen5
	goto Common_EventScript_NoMoreRoomForPokemon
	end

StarterGifts_EventScript_ReceiveParty_Gen4Gen5:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Received_Gen4Gen5
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto StarterGifts_EventScript_Received_Gen4Gen5
	end

StarterGifts_EventScript_ReceivePC_Gen4Gen5:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_TransferredToPC_Gen4Gen5
	call Common_EventScript_NameReceivedBoxMon
	goto StarterGifts_EventScript_TransferredToPC_Gen4Gen5
	end

StarterGifts_EventScript_TransferredToPC_Gen4Gen5:
	call Common_EventScript_TransferredToPC
	goto StarterGifts_EventScript_Received_Gen4Gen5
	end

StarterGifts_EventScript_Received_Gen4Gen5:
	setflag FLAG_GIFT_STARTER_GEN4_GEN5
	release
	end

StarterGifts_EventScript_Gen4Gen5NPC_Done:
	msgbox StarterGifts_Text_Gen4Gen5Done, MSGBOX_DEFAULT
	release
	end


StarterGifts_EventScript_Gen6Gen7NPC::
	lock
	faceplayer
	goto_if_set FLAG_GIFT_STARTER_GEN6_GEN7, StarterGifts_EventScript_Gen6Gen7NPC_Done
	msgbox StarterGifts_Text_Gen6Gen7Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Decline
	msgbox StarterGifts_Text_ChooseRegion, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Kalos, StarterGifts_Text_Alola, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_ChooseKalos
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_ChooseAlola
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_ChooseKalos:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Chespin, StarterGifts_Text_Fennekin, StarterGifts_Text_Froakie, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveChespin
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveFennekin
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GiveFroakie
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveChespin:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHESPIN
	goto StarterGifts_EventScript_GiveStarter_Gen6Gen7
	end

StarterGifts_EventScript_GiveFennekin:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FENNEKIN
	goto StarterGifts_EventScript_GiveStarter_Gen6Gen7
	end

StarterGifts_EventScript_GiveFroakie:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FROAKIE
	goto StarterGifts_EventScript_GiveStarter_Gen6Gen7
	end

StarterGifts_EventScript_ChooseAlola:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Rowlet, StarterGifts_Text_Litten, StarterGifts_Text_Popplio, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveRowlet
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveLitten
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GivePopplio
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveRowlet:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_ROWLET
	goto StarterGifts_EventScript_GiveStarter_Gen6Gen7
	end

StarterGifts_EventScript_GiveLitten:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_LITTEN
	goto StarterGifts_EventScript_GiveStarter_Gen6Gen7
	end

StarterGifts_EventScript_GivePopplio:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_POPPLIO
	goto StarterGifts_EventScript_GiveStarter_Gen6Gen7
	end

StarterGifts_EventScript_GiveStarter_Gen6Gen7:
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, StarterGifts_EventScript_ReceiveParty_Gen6Gen7
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, StarterGifts_EventScript_ReceivePC_Gen6Gen7
	goto Common_EventScript_NoMoreRoomForPokemon
	end

StarterGifts_EventScript_ReceiveParty_Gen6Gen7:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Received_Gen6Gen7
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto StarterGifts_EventScript_Received_Gen6Gen7
	end

StarterGifts_EventScript_ReceivePC_Gen6Gen7:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_TransferredToPC_Gen6Gen7
	call Common_EventScript_NameReceivedBoxMon
	goto StarterGifts_EventScript_TransferredToPC_Gen6Gen7
	end

StarterGifts_EventScript_TransferredToPC_Gen6Gen7:
	call Common_EventScript_TransferredToPC
	goto StarterGifts_EventScript_Received_Gen6Gen7
	end

StarterGifts_EventScript_Received_Gen6Gen7:
	setflag FLAG_GIFT_STARTER_GEN6_GEN7
	release
	end

StarterGifts_EventScript_Gen6Gen7NPC_Done:
	msgbox StarterGifts_Text_Gen6Gen7Done, MSGBOX_DEFAULT
	release
	end


StarterGifts_EventScript_Gen8Gen9NPC::
	lock
	faceplayer
	goto_if_set FLAG_GIFT_STARTER_GEN8_GEN9, StarterGifts_EventScript_Gen8Gen9NPC_Done
	msgbox StarterGifts_Text_Gen8Gen9Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Decline
	msgbox StarterGifts_Text_ChooseRegion, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Galar, StarterGifts_Text_Paldea, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_ChooseGalar
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_ChoosePaldea
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_ChooseGalar:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Grookey, StarterGifts_Text_Scorbunny, StarterGifts_Text_Sobble, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveGrookey
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveScorbunny
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GiveSobble
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveGrookey:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_GROOKEY
	goto StarterGifts_EventScript_GiveStarter_Gen8Gen9
	end

StarterGifts_EventScript_GiveScorbunny:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SCORBUNNY
	goto StarterGifts_EventScript_GiveStarter_Gen8Gen9
	end

StarterGifts_EventScript_GiveSobble:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SOBBLE
	goto StarterGifts_EventScript_GiveStarter_Gen8Gen9
	end

StarterGifts_EventScript_ChoosePaldea:
	msgbox StarterGifts_Text_ChooseStarter, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 4, 0, DYN_MULTICHOICE_CB_NONE, StarterGifts_Text_Sprigatito, StarterGifts_Text_Fuecoco, StarterGifts_Text_Quaxly, StarterGifts_Text_Cancel
	goto_if_eq VAR_RESULT, 0, StarterGifts_EventScript_GiveSprigatito
	goto_if_eq VAR_RESULT, 1, StarterGifts_EventScript_GiveFuecoco
	goto_if_eq VAR_RESULT, 2, StarterGifts_EventScript_GiveQuaxly
	goto StarterGifts_EventScript_Decline
	end

StarterGifts_EventScript_GiveSprigatito:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPRIGATITO
	goto StarterGifts_EventScript_GiveStarter_Gen8Gen9
	end

StarterGifts_EventScript_GiveFuecoco:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_FUECOCO
	goto StarterGifts_EventScript_GiveStarter_Gen8Gen9
	end

StarterGifts_EventScript_GiveQuaxly:
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_QUAXLY
	goto StarterGifts_EventScript_GiveStarter_Gen8Gen9
	end

StarterGifts_EventScript_GiveStarter_Gen8Gen9:
	givemon VAR_TEMP_TRANSFERRED_SPECIES, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, StarterGifts_EventScript_ReceiveParty_Gen8Gen9
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, StarterGifts_EventScript_ReceivePC_Gen8Gen9
	goto Common_EventScript_NoMoreRoomForPokemon
	end

StarterGifts_EventScript_ReceiveParty_Gen8Gen9:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_Received_Gen8Gen9
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto StarterGifts_EventScript_Received_Gen8Gen9
	end

StarterGifts_EventScript_ReceivePC_Gen8Gen9:
	call StarterGifts_EventScript_ReceiveFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, StarterGifts_EventScript_TransferredToPC_Gen8Gen9
	call Common_EventScript_NameReceivedBoxMon
	goto StarterGifts_EventScript_TransferredToPC_Gen8Gen9
	end

StarterGifts_EventScript_TransferredToPC_Gen8Gen9:
	call Common_EventScript_TransferredToPC
	goto StarterGifts_EventScript_Received_Gen8Gen9
	end

StarterGifts_EventScript_Received_Gen8Gen9:
	setflag FLAG_GIFT_STARTER_GEN8_GEN9
	release
	end

StarterGifts_EventScript_Gen8Gen9NPC_Done:
	msgbox StarterGifts_Text_Gen8Gen9Done, MSGBOX_DEFAULT
	release
	end


StarterGifts_EventScript_Decline:
	msgbox StarterGifts_Text_Decline, MSGBOX_DEFAULT
	release
	end

StarterGifts_EventScript_ReceiveFanfare:
	bufferspeciesname STR_VAR_2, VAR_TEMP_TRANSFERRED_SPECIES
	playfanfare MUS_OBTAIN_ITEM
	message StarterGifts_Text_ObtainedStarter
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, VAR_TEMP_TRANSFERRED_SPECIES
	return


StarterGifts_Text_Gen1Gen2Intro:
	.string "Hi there! I am a researcher from Kanto\n"
	.string "and Johto.\p"
	.string "I'm studying how starter POKéMON adapt\n"
	.string "to Hoenn's diverse environment.\p"
	.string "Would you like to take one of my rare\n"
	.string "starter POKéMON with you?$"

StarterGifts_Text_Gen1Gen2Done:
	.string "I hope you are taking good care of the\n"
	.string "starter POKéMON I gave you!$"

StarterGifts_Text_Gen4Gen5Intro:
	.string "Hello! I traveled all the way here from\n"
	.string "Sinnoh and Unova.\p"
	.string "I want to see how these starters do in\n"
	.string "the tropical climate of Slateport.\p"
	.string "Would you like to adopt one of these\n"
	.string "rare starter POKéMON?$"

StarterGifts_Text_Gen4Gen5Done:
	.string "Sinnoh and Unova starters are amazing!\n"
	.string "Train them well!$"

StarterGifts_Text_Gen6Gen7Intro:
	.string "Bonjour! I'm here from Kalos and Alola.\p"
	.string "This city is famous for its Lilycove\n"
	.string "Dept Store, but I'm here to find a\l"
	.string "great trainer for my starters!\p"
	.string "Would you like to take one of these\n"
	.string "charming starter POKéMON?$"

StarterGifts_Text_Gen6Gen7Done:
	.string "The Kalos and Alola starters seem very\n"
	.string "happy to be on your team!$"

StarterGifts_Text_Gen8Gen9Intro:
	.string "Hi! I am visiting Mossdeep City from the\n"
	.string "distant Galar and Paldea regions.\p"
	.string "I'm looking for a skilled trainer who can\n"
	.string "help me train these starters.\p"
	.string "Would you like to choose one of my\n"
	.string "starter POKéMON?$"

StarterGifts_Text_Gen8Gen9Done:
	.string "Galar and Paldea starters have incredible\n"
	.string "hidden potential!$"

StarterGifts_Text_ChooseRegion:
	.string "Which region's starter would you like\n"
	.string "to choose from?$"

StarterGifts_Text_ChooseStarter:
	.string "Which starter POKéMON will you choose?$"

StarterGifts_Text_Decline:
	.string "No problem. Let me know if you change\n"
	.string "your mind!$"

StarterGifts_Text_ObtainedStarter:
	.string "{PLAYER} obtained a {STR_VAR_2}!$"

StarterGifts_Text_Kanto:
	.string "Kanto$"

StarterGifts_Text_Johto:
	.string "Johto$"

StarterGifts_Text_Sinnoh:
	.string "Sinnoh$"

StarterGifts_Text_Unova:
	.string "Unova$"

StarterGifts_Text_Kalos:
	.string "Kalos$"

StarterGifts_Text_Alola:
	.string "Alola$"

StarterGifts_Text_Galar:
	.string "Galar$"

StarterGifts_Text_Paldea:
	.string "Paldea$"

StarterGifts_Text_Cancel:
	.string "Cancel$"

StarterGifts_Text_Bulbasaur:
	.string "Bulbasaur$"

StarterGifts_Text_Charmander:
	.string "Charmander$"

StarterGifts_Text_Squirtle:
	.string "Squirtle$"

StarterGifts_Text_Chikorita:
	.string "Chikorita$"

StarterGifts_Text_Cyndaquil:
	.string "Cyndaquil$"

StarterGifts_Text_Totodile:
	.string "Totodile$"

StarterGifts_Text_Turtwig:
	.string "Turtwig$"

StarterGifts_Text_Chimchar:
	.string "Chimchar$"

StarterGifts_Text_Piplup:
	.string "Piplup$"

StarterGifts_Text_Snivy:
	.string "Snivy$"

StarterGifts_Text_Tepig:
	.string "Tepig$"

StarterGifts_Text_Oshawott:
	.string "Oshawott$"

StarterGifts_Text_Chespin:
	.string "Chespin$"

StarterGifts_Text_Fennekin:
	.string "Fennekin$"

StarterGifts_Text_Froakie:
	.string "Froakie$"

StarterGifts_Text_Rowlet:
	.string "Rowlet$"

StarterGifts_Text_Litten:
	.string "Litten$"

StarterGifts_Text_Popplio:
	.string "Popplio$"

StarterGifts_Text_Grookey:
	.string "Grookey$"

StarterGifts_Text_Scorbunny:
	.string "Scorbunny$"

StarterGifts_Text_Sobble:
	.string "Sobble$"

StarterGifts_Text_Sprigatito:
	.string "Sprigatito$"

StarterGifts_Text_Fuecoco:
	.string "Fuecoco$"

StarterGifts_Text_Quaxly:
	.string "Quaxly$"
