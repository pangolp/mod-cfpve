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
    FACTION_HUMAN = 1,
    FACTION_ORC,
    ZONE_ICECROWN_CITADEL = 4812,
    ICC_MAP_ID = 631
};

void ChangeGroupMembersFaction(Group* group)
{
    Group::MemberSlotList const& members = group->GetMemberSlots();

    Player* leader = group->GetLeader();

    for (Group::MemberSlotList::const_iterator itr = members.begin(); itr != members.end(); ++itr)
    {
        if (Player* member = ObjectAccessor::FindPlayer((itr)->guid))
        {
            if (member == leader)
                continue;

            member->SetFaction(leader->GetFaction());
        }
    }
}

void temporaryFactionChange(Player* player)
{
    Group* group = player->GetGroup();

    if (!group)
        return;

    Player* leader = group->GetLeader();

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
        default:
            break;
        }
    }
};

void CfpveScripts()
{
    new CfPlayerScript();
}
