/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>
 * Released under GNU AGPL v3 license
 * https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"

enum MiscCrossFactionPVE
{
    ZONE_ICECROWN_CITADEL = 4812,
    ICC_MAP_ID = 631,
    ZONE_TRIAL_OF_THE_CHAMPION = 4723,
    TOCHAMPION_MAP_ID = 650,
    ZONE_TRIAL_OF_THE_CRUSADER = 4722,
    TOCRUSADER_MAP_ID = 649,
    ZONE_PIT_OF_SARON = 4813,
    POS_MAP_ID = 658,
    ZONE_HALLS_OF_REFLECTION = 4820,
    HOR_MAP_ID = 668,
    ZONE_FORGE_OF_SOULS = 4809,
    FOS_MAP_ID = 632,
    ZONE_HALLS_OF_STONE = 4264,
    HOS_MAP_ID = 599,
    ZONE_THE_NEXUS = 4265,
    TN_MAP_ID = 576
};

void temporaryFactionChange(Player* player)
{
    Group* group = player->GetGroup();

    if (!group)
        return;

    Player* leader = group->GetLeader();

    if (!leader)
        return;

    player->SetFaction(leader->GetFaction());
}

class CfPlayerScript : public PlayerScript
{
public:
    CfPlayerScript() : PlayerScript("CfPlayerScript") {}

    void OnLogin(Player* player)
    {
        if (player->GetMapId() == ICC_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == TOCHAMPION_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == TOCRUSADER_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == POS_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == HOR_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == FOS_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == HOS_MAP_ID)
        {
            temporaryFactionChange(player);
        }

        if (player->GetMapId() == TN_MAP_ID)
        {
            temporaryFactionChange(player);
        }
    }

    void OnUpdateZone(Player* player, uint32 newZone, uint32 /*newArea*/)
    {
        switch (newZone)
        {
            case ZONE_ICECROWN_CITADEL:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_TRIAL_OF_THE_CHAMPION:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_TRIAL_OF_THE_CRUSADER:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_PIT_OF_SARON:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_HALLS_OF_REFLECTION:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_FORGE_OF_SOULS:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_HALLS_OF_STONE:
            {
                temporaryFactionChange(player);
            }
            break;

            case ZONE_THE_NEXUS:
            {
                temporaryFactionChange(player);
            }
            break;

            default:
                break;
        }
    }
};

void CfpveScripts()
{
    new CfPlayerScript();
}
