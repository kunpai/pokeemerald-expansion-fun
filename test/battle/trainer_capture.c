#include "global.h"
#include "test/battle.h"
#include "event_data.h"
#include "battle_setup.h"
#include "item_use.h"
#include "battle_main.h"

SINGLE_BATTLE_TEST("Capture: Magma Ball successfully catches a basic trainer's Pokémon and prevents Bad Eggs")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAGMA_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKEBALL), BALL_MAGMA);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    }
}

SINGLE_BATTLE_TEST("Capture: Aqua Ball successfully catches a basic trainer's Pokémon and prevents Bad Eggs")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_AQUA_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } SCENE {
        ANIMATION(ANIM_TYPE_SPECIAL, B_ANIM_BALL_THROW);
    } THEN {
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_POKEBALL), BALL_AQUA);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_PLAYER][1], MON_DATA_SANITY_IS_BAD_EGG), FALSE);
    }
}

SINGLE_BATTLE_TEST("Capture: trainer blocks standard Poké Ball")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_POKE_BALL); }
    } SCENE {
        MESSAGE("The Trainer blocked your Poké Ball!");
        MESSAGE("Don't be a thief!");
    }
}

SINGLE_BATTLE_TEST("Capture: Boss trainer blocks Magma Ball")
{
    GIVEN {
        gBattleTestRunnerState->data.recordedBattle.opponentA = 1; // Boss trainer (RIVAL / RED)
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAGMA_BALL); }
    } SCENE {
        MESSAGE("The Trainer blocked your Poké Ball!");
        MESSAGE("Don't be a thief!");
    }
}

DOUBLE_BATTLE_TEST("Capture: double battles block throwing Poké Balls if two opponents are standing")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentLeft); }
    } THEN {
        EXPECT(CannotUseItemsInBattle(ITEM_MAGMA_BALL, NULL) == TRUE);
    }
}

DOUBLE_BATTLE_TEST("Capture: catching is allowed in double battles if only one opponent is standing")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
        PLAYER(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { HP(1); }
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_TACKLE, target: opponentRight); }
    } THEN {
        EXPECT(CannotUseItemsInBattle(ITEM_MAGMA_BALL, NULL) == FALSE);
    }
}

SINGLE_BATTLE_TEST("Capture: Caught Pokemon does not appear in rematches and is replaced")
{
    GIVEN {
        gBattleTestRunnerState->data.recordedBattle.opponentA = TRAINER_ROSE_1;
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_ZIGZAGOON);
        OPPONENT(SPECIES_EEVEE);
    } WHEN {
        TURN { USE_ITEM(player, ITEM_MAGMA_BALL, WITH_RNG(RNG_BALLTHROW_SHAKE, 0)); }
    } THEN {
        u32 rematchIdx = TrainerIdToRematchTableId(gRematchTable, TRAINER_ROSE_1);
        EXPECT_EQ(rematchIdx, REMATCH_ROSE);

        bool8 savedDebugBattle = gIsDebugBattle;
        u32 savedBattleFlags = gBattleTypeFlags;
        u16 savedDifficulty = VarGet(B_VAR_DIFFICULTY);
        gIsDebugBattle = FALSE;
        gBattleTypeFlags = BATTLE_TYPE_TRAINER;
        VarSet(B_VAR_DIFFICULTY, DIFFICULTY_NORMAL);

        ZeroPartyMons(gParties[B_TRAINER_OPPONENT_A]);
        gSaveBlock1Ptr->caughtRematchMons[rematchIdx] = 0;
        u8 retVal2 = CreateNPCTrainerParty(gParties[B_TRAINER_OPPONENT_A], TRAINER_ROSE_2);
        EXPECT_EQ(retVal2, 2);
        EXPECT_EQ(GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES), SPECIES_ZIGZAGOON);

        // Now set the caught bit
        gSaveBlock1Ptr->caughtRematchMons[rematchIdx] = 1; // bit 0

        ZeroPartyMons(gParties[B_TRAINER_OPPONENT_A]);
        u8 retVal = CreateNPCTrainerParty(gParties[B_TRAINER_OPPONENT_A], TRAINER_ROSE_2);
        EXPECT_EQ(retVal, 2);

        u16 partySpecies = GetMonData(&gParties[B_TRAINER_OPPONENT_A][0], MON_DATA_SPECIES);
        EXPECT_NE(partySpecies, SPECIES_ZIGZAGOON);
        EXPECT_NE(partySpecies, SPECIES_NONE);

        u8 originalType1 = gSpeciesInfo[SPECIES_ZIGZAGOON].types[0];
        u8 originalType2 = gSpeciesInfo[SPECIES_ZIGZAGOON].types[1];
        u8 newType1 = gSpeciesInfo[partySpecies].types[0];
        u8 newType2 = gSpeciesInfo[partySpecies].types[1];
        EXPECT(newType1 == originalType1 || newType1 == originalType2 || newType2 == originalType1 || newType2 == originalType2);

        gIsDebugBattle = savedDebugBattle;
        gBattleTypeFlags = savedBattleFlags;
        VarSet(B_VAR_DIFFICULTY, savedDifficulty);
    }
}

