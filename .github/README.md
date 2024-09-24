# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

# Crossfaction PVE

[![Build Status](https://github.com/pangolp/mod-cfpve/actions/workflows/core-build.yml/badge.svg)](https://github.com/pangolp/mod-cfpve)

> [!WARNING]
> The module is currently under development and will be gradually improved. Use it with caution.

> [!IMPORTANT]
> This module requires an emulator from this [commit](https://github.com/azerothcore/azerothcore-wotlk/commit/cfd7bf416207f78028ed1532db3d2bfd44dab406) onwards.

This module serves as a complement to the crossfaction pve system that the emulator has built in. Currently, within some instances, a series of events are executed, which can only be executed by members of a certain faction, for example, the battle of the ships within icc. With this change, the faction of the first person who enters the instance is taken, and the instance id and the player's faction are stored in a database. All players, who have the same id (that is, who belong to the group or raid of that same player), take the faction stored in the DB. In this way, although the client does not reflect the change, and it seems that the player has his original faction, in reality, he has changed faction momentarily, within these instances, to guarantee that the events can be carried out without problems.

![WoWScrnShot_092424_004650](https://github.com/user-attachments/assets/7935e810-c144-4862-a934-03052be95b2b)

![WoWScrnShot_092424_004718](https://github.com/user-attachments/assets/afb00ca1-9766-4655-a2ae-ccf50691582b)
