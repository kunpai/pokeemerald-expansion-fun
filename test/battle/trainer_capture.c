#include "global.h"
#include "test/battle.h"
#include "event_data.h"
#include "battle_setup.h"
#include "item_use.h"

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
