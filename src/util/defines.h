#ifndef TD_DEFINES_H
#define TD_DEFINES_H

// TD Version
// Update this whenever an incompatible change is made, to ensure that features
// are matched between clients and the server
#define TD_VERSION      0x0002

// Network information
#define TD_PORT 26631
#define TD_GROUP(x) QHostAddress(QString("232.22.42.") + QString::number(x))

// milliseconds between game ticks
#define GAME_TICK_INTERVAL  30

// based on the number keys used to select the menu option
#define TOWER_ARROW         49
#define TOWER_CANNON        50
#define TOWER_FLAME         51
#define TOWER_TAR           52
#define TOWER_FLAK          53
#define UPGRADE_TOWER       49
#define SELL_TOWER          53
#define UPGRADE_SPEED       49
#define UPGRADE_HARVEST     50
#define UPGRADE_RECOVERY    51

// for tower upgrade bitmask
#define PLAYER_NONE         0x0
#define PLAYER_SPEED        0x1
#define PLAYER_HARVEST      0x2
#define PLAYER_RECOVERY     0x4

#define MAX_TOWER_LEVEL         5

// context menu image index
#define MENU_BASE               0
#define MENU_UPGRADE_ALL        1
#define MENU_TOWER_RESOURCES    2
#define MENU_TOWER_UPGRADE      7
#define MENU_TOWER_SELL         8

#define TOWER_ARROW_2       0
#define TOWER_ARROW_3       1
#define TOWER_CANNON_2      2
#define TOWER_CANNON_3      3
#define TOWER_FLAME_2       4
#define TOWER_FLAME_3       5
#define TOWER_TAR_2         6
#define TOWER_TAR_3         7
#define TOWER_FLAK_2        8
#define TOWER_FLAK_3        9

// Current map to use
#define MAP      "bigmap"
#define MAP_TMX   QString("./maps/") + QString(MAP) + QString(".tmx")
#define MAP_NFO   QString("./maps/") + QString(MAP) + QString(".nfo")

// how often the tower type can fire (in game ticks)
#define FIRE_INTERVAL_ARROW     45
#define FIRE_INTERVAL_ARROW_2   35
#define FIRE_INTERVAL_ARROW_3   25
#define FIRE_INTERVAL_CANNON    120
#define FIRE_INTERVAL_CANNON_2  100
#define FIRE_INTERVAL_CANNON_3  80
#define FIRE_INTERVAL_FLAME     70
#define FIRE_INTERVAL_FLAME_2   60
#define FIRE_INTERVAL_FLAME_3   50
#define FIRE_INTERVAL_TAR       90
#define FIRE_INTERVAL_TAR_2     75
#define FIRE_INTERVAL_TAR_3     60
#define FIRE_INTERVAL_FLAK      15
#define FIRE_INTERVAL_FLAK_2    10
#define FIRE_INTERVAL_FLAK_3    5

// a tower's range
#define RADIUS_ARROW    240
#define RADIUS_ARROW_2  270
#define RADIUS_ARROW_3  300
#define RADIUS_CANNON   150
#define RADIUS_CANNON_2 180
#define RADIUS_CANNON_3 210
#define RADIUS_FLAME    90
#define RADIUS_FLAME_2  120
#define RADIUS_FLAME_3  150
#define RADIUS_TAR      170
#define RADIUS_TAR_2    200
#define RADIUS_TAR_3    230
#define RADIUS_FLAK     300
#define RADIUS_FLAK_2   330
#define RADIUS_FLAK_3   360

//Tile action types specifying action for spacebar
#define TILE_REGULAR    0
#define TILE_BUILDABLE  1
#define TILE_BUILDING   2
#define TILE_BUILT      3
#define TILE_BASE       4
#define TILE_RESOURCE   5

//state of tower completion
#define TOWER_COMPLETE_25   0
#define TOWER_COMPLETE_50   1
#define TOWER_COMPLETE_75   2

// resources that can be picked up by the player
#define RESOURCE_NONE   -1
#define RESOURCE_WOOD   0
#define RESOURCE_STONE  1
#define RESOURCE_BONE   2
#define RESOURCE_TAR    3
#define RESOURCE_TYPE_MAX   4
#define RESOURCE_GEM        99

// time to harvest a resource (in game ticks)
#define HARVEST_COUNTDOWN   60

// NPC types
#define NPC_NORM    0
#define NPC_SLOW    1
#define NPC_FAST    2
#define NPC_FLY     3
#define NPC_BOSS    4

// Acceleration of NPC types
#define NPC_NORM_ACCEL  0.2  
#define NPC_SLOW_ACCEL  0.1  
#define NPC_FAST_ACCEL  0.3  
#define NPC_FLY_ACCEL   0.2  
#define NPC_BOSS_ACCEL  0.1  

// Deceleration of NPC types
#define NPC_NORM_DECEL  0.25  
#define NPC_SLOW_DECEL  0.15  
#define NPC_FAST_DECEL  0.4  
#define NPC_FLY_DECEL   0.25  
#define NPC_BOSS_DECEL  0.15  

// Maximum Velocity of NPC types
#define NPC_NORM_MAX_V  2  
#define NPC_SLOW_MAX_V  1
#define NPC_FAST_MAX_V  4
#define NPC_FLY_MAX_V   2
#define NPC_BOSS_MAX_V  1

//Player velocity
#define PLAYER_MAX_V 5

//effect types for operator==
#define EFFECT_NONE         0
#define EFFECT_NPCPLAYER    1
#define EFFECT_SLOW         2
#define EFFECT_FAST         3
// These 5 need to stay in the same block
#define EFFECT_ARROW        4
#define EFFECT_TAR          5
#define EFFECT_BURN         6
#define EFFECT_CANNON       7
#define EFFECT_FIRE         8
#define EFFECT_FLAK         9

//Effect durations for each type
#define NPC_PLAYER_TIME 20
#define TAR_TIME        100
#define ARROW_TIME      1
#define FLAK_TIME       1
#define CANNON_TIME     1
#define FIRE_TIME       1
#define BURN_TIME       75
//DONT USE THIS MACRO UNLESS YOUR NAME IS DTRAIN
#define NO_TIME         0,false

//Projectile types
#define PROJ_ARROW      0
#define PROJ_ARROW_2    1
#define PROJ_ARROW_3    2
#define PROJ_CANNON     3
#define PROJ_CANNON_2   4
#define PROJ_CANNON_3   5
#define PROJ_FIRE       6
#define PROJ_FIRE_2     7
#define PROJ_FIRE_3     8
#define PROJ_TAR        9
#define PROJ_TAR_2      10
#define PROJ_TAR_3      11
#define PROJ_FLAK       12
#define PROJ_FLAK_2     13
#define PROJ_FLAK_3     14

//Projectile Velocity
#define ARROW_VELOCITY  15
#define CANNON_VELOCITY 10
#define FIRE_VELOCITY   6
#define TAR_VELOCITY    10
#define FLAK_VELOCITY   15

// collectable misc
#define COLLECTABLE_VELOCITY    3
#define GEM_SIZE                0.6
#define RESOURCE_SIZE           0.8
#define TIME_TO_DISAPPEAR       600
#define FLICKER_RATE            9
#define FLICKER_POINT           (int) (TIME_TO_DISAPPEAR * 0.25) \
                              - (int) (TIME_TO_DISAPPEAR * 0.25) % FLICKER_RATE

// healthbar info (sizes are in pixels)
#define HEALTHBAR_WIDTH     50
#define HEALTHBAR_HEIGHT    4
#define DAMAGE_DISPLAY_TIME 50

// resource collection bar size, in pixels
#define RESBAR_WIDTH    30
#define RESBAR_HEIGHT   6

// tower requirements
#define COST_FLAK_WOOD    0
#define COST_FLAK_STONE   1
#define COST_FLAK_BONE    0
#define COST_FLAK_OIL     0

#define COST_ARROW_WOOD   0
#define COST_ARROW_STONE  1
#define COST_ARROW_BONE   0
#define COST_ARROW_OIL    0

#define COST_CANNON_WOOD  0
#define COST_CANNON_STONE 1
#define COST_CANNON_BONE  0
#define COST_CANNON_OIL   0

#define COST_TAR_WOOD     0
#define COST_TAR_STONE    1
#define COST_TAR_BONE     0
#define COST_TAR_OIL      0

#define COST_FLAME_WOOD    0
#define COST_FLAME_STONE   1
#define COST_FLAME_BONE    0
#define COST_FLAME_OIL     0

#define COST_TOWER_UPGRADE      1
#define COST_TOWER_UPGRADE_2    2

#endif

