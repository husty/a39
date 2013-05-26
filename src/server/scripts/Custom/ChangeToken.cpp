#include "ScriptPCH.h"

class npc_change : public CreatureScript
{
    public:
        npc_change() : CreatureScript("npc_change") { }

	       bool OnGossipHello(Player *player, Creature *_creature)
           {
		        if (player->isInCombat()) 
                {		
				     /// @todo check Combat
                    creature->MonsterWhisper("You are in Combat", player->GetGUID());
				    player->CLOSE_GOSSIP_MENU();
					return true;
                }
                else
                { 
				    player->ADD_GOSSIP_ITEM( 0, "10 Mark -> Reset Instance"                                    , GOSSIP_SENDER_MAIN, 1);
				    player->ADD_GOSSIP_ITEM( 0, "10 Mark -> 25 Arena Pointu"                                   , GOSSIP_SENDER_MAIN, 2);
				    player->ADD_GOSSIP_ITEM( 0, "10 BOJ -> 1 Mark"                                             , GOSSIP_SENDER_MAIN, 3);
				    player->ADD_GOSSIP_ITEM( 0, "5 Mark -> 1 EoT"                                             , GOSSIP_SENDER_MAIN, 4);
				    player->ADD_GOSSIP_ITEM( 0, "10 Mark -> 5000 Honor"                                        , GOSSIP_SENDER_MAIN, 5);
		        }	


				player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, _creature->GetGUID());         
			    return true;
            }

            bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
            {

                if (sender != GOSSIP_SENDER_MAIN)
				    return true;

                player->PlayerTalkClass->ClearMenus();

                switch(uiAction)
                {

                    case 1:
					    if (player->HasItemCount(19322, 10, true))
						{
							player->DestroyItemCount(19322, 10, true);
							player->UnbindInstance(player->GetMapId(), player->GetDifficulty(true), true);
							_creature->MonsterWhisper("Unbind all Instances complete!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();

						}
						else
						{
							_creature->MonsterWhisper("Missing items", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();
						}
                        break;
 
                    case 2:
					    if (player->HasItemCount(19322, 10, true))
						{

							player->DestroyItemCount(19322, 10, true);								
							player->ModifyArenaPoints(+25);
							_creature->MonsterWhisper("Change Succesful!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();

						}
						else
						{
							_creature->MonsterWhisper("Missing Items.", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();									
						}
                        break;


                    case 3:
					    if (player->HasItemCount(29434, 10, true))
						{
						    player->DestroyItemCount(29434, 10, true);								
							player->AddItem(19322, 1);
							_creature->MonsterWhisper("Chance Succesful!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();

						}
						else
						{									
							_creature->MonsterWhisper("You need more Badge of Justice!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();
						}
                        break;

                    case 4:
					    if (player->HasItemCount(19322, 5, true))
						{

							player->DestroyItemCount(19322, 5, true);								
							player->AddItem(47241, 1);
							_creature->MonsterWhisper("Chance Succesful!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();

					    }
						else
						{									
							_creature->MonsterWhisper("Missing Items!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();
					    }
                        break;

                    case 5:
					    if (player->HasItemCount(19322, 10, true))
						{

							player->ModifyHonorPoints(+5000);							
							player->DestroyItemCount(19322, 10, true);
							_creature->MonsterWhisper("Chance Succesful!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();

					    }
						else
						{
							_creature->MonsterWhisper("Missing Items!", player->GetGUID());
							player->CLOSE_GOSSIP_MENU();

					    }
                        break;
                    default:
                        break;
                }
                return true;
        }
};

void AddSC_npc_change()
{
    new npc_change();
}
