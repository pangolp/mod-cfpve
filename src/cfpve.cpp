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

class CfAllMapScript : public AllMapScript
{
public:
    CfAllMapScript() : AllMapScript("CfAllMapScript") { }

    void OnPlayerEnterAll(Map* map, Player* player) override
    {
        if (map->IsBattlegroundOrArena())
            return;

        if (map->GetInstanceId() == 0)
            return;

        temporaryFactionChange(player);
    }

    void OnPlayerLeaveAll(Map* map, Player* player) override
    {
        if (map->GetInstanceId() == 0)
            player->SetFactionForRace(player->getRace());
    }

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
    new CfAllMapScript();
    new CfServerScript();
}
