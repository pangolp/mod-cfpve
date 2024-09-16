# ![logo](https://raw.githubusercontent.com/azerothcore/azerothcore.github.io/master/images/logo-github.png) AzerothCore

# Crossfaction PVE

[![Build Status](https://github.com/pangolp/mod-cfpve/actions/workflows/core-build.yml/badge.svg)](https://github.com/pangolp/mod-cfpve)

> [!WARNING]
> The module is currently under development and will be gradually improved. Use it with caution.

> [!IMPORTANT]
> This module requires this [pull request](https://github.com/azerothcore/azerothcore-wotlk/pull/19979) for its full operation.

This module serves as a complement to the crossfaction pve system that the emulator has built in. Currently, within some instances, those that will be mentioned later, a series of events are executed, which can only be executed by members of a certain faction, for example, the battle of the ships within icc. With this change, the faction of the first person who enters the instance is taken, and the instance id and the player's faction are stored in a database. All players, who have the same id (that is, who belong to the group or raid of that same player), take the faction stored in the DB. In this way, although the client does not reflect the change, and it seems that the player has his original faction, in reality, he has changed faction momentarily, within these instances, to guarantee that the events can be carried out without problems.

The current list of instances where this script is running are:

- https://www.wowhead.com/wotlk/zone=4812/icecrown-citadel
- https://www.wowhead.com/wotlk/zone=4723/trial-of-the-champion
- https://www.wowhead.com/wotlk/zone=4722/trial-of-the-crusader
- https://www.wowhead.com/wotlk/zone=4813/pit-of-saron
- https://www.wowhead.com/wotlk/zone=4820/halls-of-reflection
- https://www.wowhead.com/wotlk/zone=4809/the-forge-of-souls
- https://www.wowhead.com/wotlk/zone=4264/halls-of-stone
- https://www.wowhead.com/wotlk/zone=4265/the-nexus
