#include "constants/abilities.h"
#include "constants/teaching_types.h"
#include "species_info/shared_dex_text.h"
#include "species_info/shared_front_pic_anims.h"

// Macros for ease of use.

#define EVOLUTION(...)                                                         \
  (const struct Evolution[]) { __VA_ARGS__, {EVOLUTIONS_END}, }
#define CONDITIONS(...)                                                        \
  ((const struct EvolutionParam[]){__VA_ARGS__, {CONDITIONS_END}})

#define ANIM_FRAMES(...)                                                       \
  (const union AnimCmd *const[]) {                                             \
    sAnim_GeneralFrame0,                                                       \
        (const union AnimCmd[]){                                               \
            __VA_ARGS__ ANIMCMD_END,                                           \
        },                                                                     \
  }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_##sprite,
#else
#define FOOTPRINT(sprite)
#endif

#if B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE
#define SHADOW(x, y, size)                                                     \
  .enemyShadowXOffset = x, .enemyShadowYOffset = y, .enemyShadowSize = size,
#define NO_SHADOW .suppressEnemyShadow = TRUE,
#else
#define SHADOW(x, y, size)                                                     \
  .enemyShadowXOffset = 0, .enemyShadowYOffset = 0, .enemyShadowSize = 0,
#define NO_SHADOW .suppressEnemyShadow = FALSE,
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
#define OVERWORLD_PAL(...)                                                     \
  .overworldPalette = DEFAULT(NULL, __VA_ARGS__),                              \
  .overworldShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#if P_GENDER_DIFFERENCES
#define OVERWORLD_PAL_FEMALE(...)                                              \
  .overworldPaletteFemale = DEFAULT(NULL, __VA_ARGS__),                        \
  .overworldShinyPaletteFemale = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define OVERWORLD_PAL_FEMALE(...)
#endif // P_GENDER_DIFFERENCES
#else
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif // OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE

#define OVERWORLD_DATA(picTable, _size, shadow, _tracks, _anims)               \
  {                                                                            \
      .tileTag = TAG_NONE,                                                     \
      .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                 \
      .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                          \
      .size = (_size == SIZE_32x32 ? 512 : 2048),                              \
      .width = (_size == SIZE_32x32 ? 32 : 64),                                \
      .height = (_size == SIZE_32x32 ? 32 : 64),                               \
      .paletteSlot = PALSLOT_NPC_1,                                            \
      .shadowSize = shadow,                                                    \
      .inanimate = FALSE,                                                      \
      .compressed = COMP,                                                      \
      .tracks = _tracks,                                                       \
      .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32                 \
                                  : &gObjectEventBaseOam_64x64),               \
      .subspriteTables =                                                       \
          (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),         \
      .anims = _anims,                                                         \
      .images = picTable,                                                      \
  }

#define OVERWORLD(objEventPic, _size, shadow, _tracks, _anims, ...)            \
  .overworldData =                                                             \
      OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),             \
  OVERWORLD_PAL(__VA_ARGS__)

#if P_GENDER_DIFFERENCES
#define OVERWORLD_FEMALE(objEventPic, _size, shadow, _tracks, _anims, ...)     \
  .overworldDataFemale =                                                       \
      OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),             \
  OVERWORLD_PAL_FEMALE(__VA_ARGS__)
#else
#define OVERWORLD_FEMALE(...)
#endif // P_GENDER_DIFFERENCES

#else
#define OVERWORLD(...)
#define OVERWORLD_FEMALE(...)
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif // OW_POKEMON_OBJECT_EVENTS

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) {type1, DEFAULT(type1, __VA_ARGS__)}
#define MON_EGG_GROUPS(group1, ...) {group1, DEFAULT(group1, __VA_ARGS__)}

#define FLIP 0
#define NO_FLIP 1

const struct SpeciesInfo gSpeciesInfo[] = {
    [SPECIES_NONE] =
        {
            .speciesName = _("??????????"),
            .cryId = CRY_PORYGON,
            .natDexNum = NATIONAL_DEX_NONE,
            .categoryName = _("Unknown"),
            .height = 0,
            .weight = 0,
            .description = gFallbackPokedexText,
            .pokemonScale = 256,
            .pokemonOffset = 0,
            .trainerScale = 256,
            .trainerOffset = 0,
            .frontPic = gMonFrontPic_CircledQuestionMark,
            .frontPicSize = MON_COORDS_SIZE(40, 40),
            .frontPicYOffset = 12,
            .frontAnimFrames = sAnims_TwoFramePlaceHolder,
            .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
            .backPic = gMonBackPic_CircledQuestionMark,
            .backPicSize = MON_COORDS_SIZE(40, 40),
            .backPicYOffset = 12,
            .backAnimId = BACK_ANIM_NONE,
            .palette = gMonPalette_CircledQuestionMark,
            .shinyPalette = gMonShinyPalette_CircledQuestionMark,
            .iconSprite = gMonIcon_QuestionMark,
            .iconPalIndex = 0,
            .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
            FOOTPRINT(QuestionMark) SHADOW(-1, 0, SHADOW_SIZE_M)
#if OW_POKEMON_OBJECT_EVENTS
                .overworldData =
                {
                    .tileTag = TAG_NONE,
                    .paletteTag = OBJ_EVENT_PAL_TAG_SUBSTITUTE,
                    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
                    .size = 512,
                    .width = 32,
                    .height = 32,
                    .paletteSlot = PALSLOT_NPC_1,
                    .shadowSize = SHADOW_SIZE_M,
                    .inanimate = FALSE,
                    .compressed = COMP,
                    .tracks = TRACKS_FOOT,
                    .oam = &gObjectEventBaseOam_32x32,
                    .subspriteTables = sOamTables_32x32,
                    .anims = sAnimTable_Following,
                    .images = sPicTable_Substitute,
                },
#endif
            .levelUpLearnset = sNoneLevelUpLearnset,
            .teachableLearnset = sNoneTeachableLearnset,
            .eggMoveLearnset = sNoneEggMoveLearnset,
        },

#include "species_info/gen_1_families.h"
#include "species_info/gen_2_families.h"
#include "species_info/gen_3_families.h"
#include "species_info/gen_4_families.h"
#include "species_info/gen_5_families.h"
#include "species_info/gen_6_families.h"
#include "species_info/gen_7_families.h"
#include "species_info/gen_8_families.h"
#include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
        {
            .frontPic = gMonFrontPic_Egg,
            .frontPicSize = MON_COORDS_SIZE(24, 24),
            .frontPicYOffset = 20,
            .backPic = gMonFrontPic_Egg,
            .backPicSize = MON_COORDS_SIZE(24, 24),
            .backPicYOffset = 20,
            .palette = gMonPalette_Egg,
            .shinyPalette = gMonPalette_Egg,
            .iconSprite = gMonIcon_Egg,
            .iconPalIndex = 1,
        },

    [SPECIES_CHUSSU] =
        {
            .baseHP = 80,
            .baseAttack = 160,
            .baseDefense = 70,
            .baseSpeed = 115,
            .baseSpAttack = 60,
            .baseSpDefense = 75,
            .types = MON_TYPES(TYPE_NORMAL, TYPE_POISON),
            .catchRate = 45,
            .expYield = 180,
            .evYield_Attack = 2,
            .evYield_Speed = 1,
            .genderRatio = MON_MALE,
            .eggCycles = 20,
            .friendship = STANDARD_FRIENDSHIP,
            .growthRate = GROWTH_MEDIUM_FAST,
            .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
            .abilities = {ABILITY_TRUANT, ABILITY_TRUANT, ABILITY_TRUANT},
            .bodyColor = BODY_COLOR_GRAY,
            .speciesName = _("Chussu"),
            .cryId = CRY_NONE,
            .natDexNum = NATIONAL_DEX_CHUSSU,
            .categoryName = _("Chussu"),
            .height = 17,
            .weight = 720,
            .description =
                COMPOUND_STRING("He owns a gutka business, but because\n"
                                "he is Gujarati, he is incredibly lazy.\n"
                                "He prefers taking long, relaxed breaks over\n"
                                "engaging in any form of intense training."),
            .pokemonScale = 256,
            .pokemonOffset = 0,
            .trainerScale = 256,
            .trainerOffset = 0,
            .frontPic = gMonFrontPic_Chussu,
            .frontPicSize = MON_COORDS_SIZE(64, 64),
            .frontPicYOffset = 0,
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
            .frontAnimId = ANIM_GROW_VIBRATE,
            .enemyMonElevation = 0,
            .backPic = gMonBackPic_Chussu,
            .backPicSize = MON_COORDS_SIZE(64, 64),
            .backPicYOffset = 0,
            .backAnimId = BACK_ANIM_NONE,
            .palette = gMonPalette_Chussu,
            .shinyPalette = gMonShinyPalette_Chussu,
            .iconSprite = gMonIcon_Chussu,
            .iconPalIndex = 2,
            FOOTPRINT(Chussu) OVERWORLD(
                sPicTable_Chussu, SIZE_32x32, SHADOW_SIZE_M, TRACKS_FOOT,
                sAnimTable_Following, gOverworldPalette_Chussu,
                gShinyOverworldPalette_Chussu)
                .levelUpLearnset = sChussuLevelUpLearnset,
            .teachableLearnset = sChussuTeachableLearnset,
        },
    [SPECIES_SLENDERMAN] =
        {
            .baseHP = 90,
            .baseAttack = 110,
            .baseDefense = 80,
            .baseSpeed = 130,
            .baseSpAttack = 130,
            .baseSpDefense = 110,
            .types = MON_TYPES(TYPE_GHOST, TYPE_DARK),
            .catchRate = 15,
            .expYield = 270,
            .evYield_SpAttack = 2,
            .evYield_Speed = 1,
            .genderRatio = MON_GENDERLESS,
            .eggCycles = 40,
            .friendship = 0,
            .growthRate = GROWTH_SLOW,
            .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
            .abilities = {ABILITY_PRESSURE, ABILITY_INSOMNIA,
                          ABILITY_SHADOW_TAG},
            .bodyColor = BODY_COLOR_WHITE,
            .speciesName = _("Slenderman"),
            .cryId = CRY_NONE,
            .natDexNum = NATIONAL_DEX_SLENDERMAN,
            .categoryName = _("Faceless"),
            .height = 30,
            .weight = 500,
            .description =
                COMPOUND_STRING("An interdimensional entity that haunts\n"
                                "dense forests. It has no face and uses\n"
                                "long, invisible tentacles to capture its\n"
                                "unsuspecting victims in the dark."),
            .pokemonScale = 256,
            .pokemonOffset = 0,
            .trainerScale = 256,
            .trainerOffset = 0,
            .frontPic = gMonFrontPic_Slenderman,
            .frontPicSize = MON_COORDS_SIZE(64, 64),
            .frontPicYOffset = 0,
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
            .frontAnimId = ANIM_GROW_VIBRATE,
            .enemyMonElevation = 0,
            .backPic = gMonBackPic_Slenderman,
            .backPicSize = MON_COORDS_SIZE(64, 64),
            .backPicYOffset = 0,
            .backAnimId = BACK_ANIM_NONE,
            .palette = gMonPalette_Slenderman,
            .shinyPalette = gMonShinyPalette_Slenderman,
            .iconSprite = gMonIcon_Slenderman,
            .iconPalIndex = 0,
            FOOTPRINT(Slenderman) OVERWORLD(
                sPicTable_Slenderman, SIZE_32x32, SHADOW_SIZE_M, TRACKS_FOOT,
                sAnimTable_Following, gOverworldPalette_Chussu,
                gShinyOverworldPalette_Chussu)
                .levelUpLearnset = sSlendermanLevelUpLearnset,
            .teachableLearnset = sSlendermanTeachableLearnset,
        },
    [SPECIES_NARUTO] =
        {
            .baseHP = 80,
            .baseAttack = 110,
            .baseDefense = 75,
            .baseSpeed = 120,
            .baseSpAttack = 90,
            .baseSpDefense = 80,
            .types = MON_TYPES(TYPE_FIGHTING, TYPE_FIRE),
            .catchRate = 45,
            .expYield = 200,
            .evYield_Attack = 2,
            .evYield_Speed = 1,
            .genderRatio = MON_MALE,
            .eggCycles = 20,
            .friendship = 70,
            .growthRate = GROWTH_MEDIUM_FAST,
            .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
            .abilities = {ABILITY_INNER_FOCUS, ABILITY_JUSTIFIED, ABILITY_NONE},
            .bodyColor = BODY_COLOR_YELLOW,
            .speciesName = _("Naruto"),
            .cryId = CRY_NONE,
            .natDexNum = NATIONAL_DEX_NARUTO,
            .categoryName = _("Ninja"),
            .height = 16,
            .weight = 540,
            .description =
                COMPOUND_STRING("A loud and hyperactive ninja from the\n"
                                "Leaf Village who dreams of becoming Hokage.\n"
                                "He holds the powerful Nine-Tailed Fox\n"
                                "sealed inside of him."),
            .pokemonScale = 256,
            .pokemonOffset = 0,
            .trainerScale = 256,
            .trainerOffset = 0,
            .frontPic = gMonFrontPic_Naruto,
            .frontPicSize = MON_COORDS_SIZE(64, 64),
            .frontPicYOffset = 0,
            .frontAnimFrames = sAnims_SingleFramePlaceHolder,
            .frontAnimId = ANIM_GROW_VIBRATE,
            .enemyMonElevation = 0,
            .backPic = gMonBackPic_Naruto,
            .backPicSize = MON_COORDS_SIZE(64, 64),
            .backPicYOffset = 10,
            .backAnimId = BACK_ANIM_NONE,
            .palette = gMonPalette_Naruto,
            .shinyPalette = gMonShinyPalette_Naruto,
            .iconSprite = gMonIcon_Naruto,
            .iconPalIndex = 0,
            FOOTPRINT(Naruto)
                OVERWORLD(sPicTable_Naruto, SIZE_32x32, SHADOW_SIZE_M,
                          TRACKS_FOOT, sAnimTable_Following,
                          gOverworldPalette_Naruto,
                          gShinyOverworldPalette_Naruto)
                    .levelUpLearnset = sNarutoLevelUpLearnset,
            .teachableLearnset = sNarutoTeachableLearnset,
        },
    /* You may add any custom species below this point based on the following
       structure: */

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_CircledQuestionMark,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_CircledQuestionMarkF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSpriteFemale = gMonIcon_QuestionMarkF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        //.perfectIVCount = NUM_STATS,
    },
    */
};

const struct EggData gEggDatas[EGG_ID_COUNT] = {
#include "egg_data.h"
};
