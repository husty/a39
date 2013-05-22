#include "ScriptPCH.h"
#include "Player.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include <sstream>

class FastArenaCrystal : public GameObjectScript
{
    public:

        FastArenaCrystal()
            : GameObjectScript("FastArenaCrystal")
        {
        }

        bool OnGossipHello(Player* player, GameObject* go)
        {
            if (Battleground *bg = player->GetBattleground())
                if (bg->isArena())
				{
			        std::string msg (bg->ClickFastStart(player, go));
				    go->MonsterWhisper("Player Clicked on Crystal: ", msg.c_str(), player->GetGUID());
				    return true;
				}
                    

            return false;
        }
};

void AddSC_fast_arena_start()
{
    new FastArenaCrystal();
}