/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>
 * Released under GNU AGPL v3 license
 * https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"
#include "Config.h"
#include "Chat.h"
#include "MapMgr.h"

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
    uint32 faction = 0;

    QueryResult result = CharacterDatabase.Query("SELECT `factionID` FROM `mod_crossfaction_pve` WHERE `instanceID`={}", player->GetMap()->GetInstanceId());

    if (!result)
    {
        CharacterDatabase.DirectExecute("INSERT INTO `mod_crossfaction_pve` (`instanceID`, `factionID`) VALUES ({}, {})", player->GetMap()->GetInstanceId(), player->GetFaction());
        faction = player->GetFaction();
    }
    else
    {
        faction = (*result)[0].Get<int32>();
    }

    player->SetFaction(faction);
}

class CfPlayerScript : public PlayerScript
{
public:
    CfPlayerScript() : PlayerScript("CfPlayerScript") { }

    void OnLogin(Player* player)
    {
        switch (player->GetMapId())
        {
            case ICC_MAP_ID:
            case TOCHAMPION_MAP_ID:
            case TOCRUSADER_MAP_ID:
            case POS_MAP_ID:
            case HOR_MAP_ID:
            case FOS_MAP_ID:
            case HOS_MAP_ID:
            case TN_MAP_ID:
                temporaryFactionChange(player);
                break;
        }
    }

    void OnUpdateZone(Player* player, uint32 newZone, uint32 /*newArea*/)
    {
        switch (newZone)
        {
            case ICC_MAP_ID:
            case TOCHAMPION_MAP_ID:
            case TOCRUSADER_MAP_ID:
            case POS_MAP_ID:
            case HOR_MAP_ID:
            case FOS_MAP_ID:
            case HOS_MAP_ID:
            case TN_MAP_ID:
                temporaryFactionChange(player);
                break;
        }
    }

    void OnMapChanged(Player* player) override
    {
        switch (player->GetMapId())
        {
        case ICC_MAP_ID:
        case TOCHAMPION_MAP_ID:
        case TOCRUSADER_MAP_ID:
        case POS_MAP_ID:
        case HOR_MAP_ID:
        case FOS_MAP_ID:
        case HOS_MAP_ID:
        case TN_MAP_ID:
            temporaryFactionChange(player);
            break;
        }
    }
};

class CfAllMapScript : public AllMapScript
{
public:
    CfAllMapScript() : AllMapScript("CfAllMapScript") { }

    void OnDestroyInstance(MapInstanced* /*mapInstanced*/, Map* map) override
    {
        QueryResult result = CharacterDatabase.Query("SELECT `factionID` FROM `mod_crossfaction_pve` WHERE `instanceID`={}", map->GetInstanceId());

        if (result)
        {
            CharacterDatabase.DirectExecute("DELETE FROM `mod_crossfaction_pve` WHERE `instanceID`={}", map->GetInstanceId());
        }
    }
};

class CfServerScript : public ServerScript
{
public:
    CfServerScript() : ServerScript("CfServerScript") { }

    void OnNetworkStart() override
    {
        CharacterDatabase.DirectExecute("DELETE FROM `mod_crossfaction_pve`");
    }
};

void CfpveScripts()
{
    new CfPlayerScript();
    new CfAllMapScript();
    new CfServerScript();
}
