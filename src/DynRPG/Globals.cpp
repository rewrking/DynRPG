/*
	DynRPG v0.10
	RM2k3 Plugin SDK
	by David "Cherry" Trapp
	http://cherrytree.at
*/

#define DYNRPG_STATIC
#include <DynRPG/Globals.hpp>

#include <map>
#include <sstream>
#include <stdio.h>

#include <DynRPG/Catalog/NamedCatalogPtr.hpp>
#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Graphics/Screen.hpp>
#include <DynRPG/Item/Inventory.hpp>
#include <DynRPG/Scene/Scene.hpp>
#include <DynRPG/Scene/SceneMenu.hpp>
#include <DynRPG/Utility/Win32.hpp>
#include <DynRPG/Variable/Variables.hpp>

namespace RPG
{
/******************************************************************************
 *
 *****************************************************************************/
void showError(std::string message, int eventId, int pageId, int lineId)
{
	std::stringstream s;
	s << "An error has occured:\r\n"
	  << message << "\r\n";
	if (eventId > 0)
	{
		s << "...at map event " << eventId << ", page " << pageId << ", line " << lineId + 1 << ".";
	}
	else if (eventId < 0)
	{
		s << "...at common event " << 0 - eventId << ", line " << lineId + 1 << ".";
	}
	else
	{
		s << "...at an unknown or battle event, line " << lineId + 1 << ".";
	}
	s << "\r\nContinue game?";
	HWND hWnd = NULL;
	if (RPG::screen)
	{
		try
		{
			hWnd = RPG::screen->getCanvasHWND();
			if (GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD)
				hWnd = GetAncestor(hWnd, GA_ROOT);
		}
		catch (...)
		{
		}
		if (MessageBox(hWnd, s.str().c_str(), "DynRPG", MB_YESNO | MB_ICONWARNING) != IDYES && IsWindow(hWnd))
		{
			PostMessage(hWnd, WM_CLOSE, 0, 0);
		}
	}
}

/******************************************************************************
 *
 *****************************************************************************/
void updateBattle()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x497244), "a"(**sceneObjects[static_cast<uchar>(Scene::Battle)])
				 : "edx", "ecx", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void updateBattleEvents(BattleEventUpdateMode mode, Battler* battler)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x499800), "a"(**sceneObjects[static_cast<uchar>(Scene::Battle)]), "d"(battler), "c"(mode)
				 : "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
int getSelectedMonsterIndex()
{
	int* window = ((int**)**sceneObjects[static_cast<uchar>(Scene::Battle)])[15];
	if (!window[20])
		return -1;
	return window[window[17] + 30];
}

/******************************************************************************
 *
 *****************************************************************************/
std::string getSkillName(int id)
{
	DStringPtr* p = (**reinterpret_cast<NamedCatalogPtr<DStringPtr*>**>(0x4CDBC4))[id];
	if (!p)
		return "";
	return p[2];
}

/******************************************************************************
 *
 *****************************************************************************/
std::string getSkillDescription(int id)
{
	DStringPtr* p = (**reinterpret_cast<NamedCatalogPtr<DStringPtr*>**>(0x4CDBC4))[id];
	if (!p)
		return "";
	return p[3];
}

/******************************************************************************
 *
 *****************************************************************************/
std::string getItemName(int id)
{
	DStringPtr* p = (**reinterpret_cast<NamedCatalogPtr<DStringPtr*>**>(0x4CDB14))[id];
	if (!p)
		return "";
	return p[2];
}

/******************************************************************************
 *
 *****************************************************************************/
std::string getItemDescription(int id)
{
	DStringPtr* p = (**reinterpret_cast<NamedCatalogPtr<DStringPtr*>**>(0x4CDB14))[id];
	if (!p)
		return "";
	return p[3];
}

/******************************************************************************
 *
 *****************************************************************************/
std::string getConditionName(int id)
{
	DStringPtr* p = (**reinterpret_cast<NamedCatalogPtr<DStringPtr*>**>(0x4CDE84))[id];
	if (!p)
		return "";
	return p[2];
}

/******************************************************************************
 *
 *****************************************************************************/
std::map<std::string, std::string> loadConfiguration(char* sectionName, char* filename)
{
	char* buffer = new char[32768];
	char* pKey = buffer;
	std::map<std::string, std::string> data;

	std::string sFilename(".\\");
	if (filename)
	{
		sFilename += filename;
	}
	else
	{
		sFilename += "DynRPG.ini";
	}
	GetPrivateProfileSection(sectionName, buffer, 32767, sFilename.c_str());

	while (*pKey)
	{
		std::string strKey = pKey;
		std::string::size_type nPos = strKey.find('=', 0);
		data[strKey.substr(0, nPos)] = strKey.substr(nPos + 1);
		pKey += strlen(pKey) + 1;
	}

	delete[] buffer;
	return data;
}

/******************************************************************************
 *
 *****************************************************************************/
std::string encode(int value)
{
	std::string ret;
	for (int i = 0; value != 0; i++)
	{
		ret.insert(0, 1, (value & 0x7F) | (i ? 0x80 : 0));
		value >>= 7;
	}
	return ret;
}

/******************************************************************************
 *
 *****************************************************************************/
std::string encode(std::string value)
{
	std::string ret = encode(value.length());
	for (std::string::iterator it = value.begin(); it < value.end(); it++)
	{
		ret += encode(*it);
	}
	return ret;
}

/******************************************************************************
 *
 *****************************************************************************/
int getDiceRoll(int maxValue)
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out)
				 : "S"(0x403054), "a"(maxValue)
				 : "edx", "ecx", "cc", "memory");
	// If maxValue is 20, by default, 19 is the actual max that will be returned by the function, so out+1 is returned below. This also ensures 1 is returned instead of 0, to simulate actual dice rolls
	return out + 1;
	// Alternative:
	//return rand() % maxValue +1;
}

/******************************************************************************
 *
 *****************************************************************************/
void goToTitle()
{
	asm volatile("call *%%esi"
				 :
				 : "S"(0x46BC00)
				 : "edx", "ecx", "eax", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void quitGame()
{
	asm volatile("push $0; call *%%esi"
				 :
				 : "S"(0x40729C)
				 : "edx", "ecx", "eax", "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
/*static void openOrderMenu() {
	asm volatile("call *%%esi"
		:
		: "S" (0x4A0104)
		: "edx", "ecx", "eax", "cc", "memory");

}*/

/******************************************************************************
 *
 *****************************************************************************/
int getAvgPartyAgl()
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out)
				 : "S"(0x4A690C), "a"(inventory) // It doesn't make sense to put this function in inventory, even though it references it
				 : "edx", "ecx", "cc", "memory");
	return out;
}

/******************************************************************************
 *
 *****************************************************************************/
int getAvgMonsterPartyAgl()
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out)
				 : "S"(0x4BEDF4), "a"(inventory) // It doesn't make sense to put this function in inventory, even though it references it
				 : "edx", "ecx", "cc", "memory");
	return out;
}

/******************************************************************************
 *
 *****************************************************************************/
void openMenu(MenuSubScreen screen, int heroId, int skillOrItemId)
{
	//menu->repaint = false;

	if (system->scene == Scene::Menu && menu->screen == MenuSubScreen::Main)
	{
		*reinterpret_cast<char*>(0x4A3368) = 0xA9; // Default = 0x91
		switch (screen)
		{
			case MenuSubScreen::Item: { //open MENU_ITEM
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10    //speed up transition
				*reinterpret_cast<ushort*>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A110C), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}
			case MenuSubScreen::ItemUse: { //open MENU_ITEM_USE
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10        //speed up transition
				*reinterpret_cast<char*>(0x4A17FC) = 0xE9; // Default: 0x53        //re-route closeItemUseMenu() to closeMenu()
				*reinterpret_cast<int*>(0x4A17FD) = 0xFFFFF893; // Default: 0x0068D88B
				menu->selectedItem = skillOrItemId; //Item_ID (must be in inventory)
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A1144), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}
			case MenuSubScreen::Skill: { //open MENU_SKILL
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10    //speed up transition
				*reinterpret_cast<ushort*>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
				*reinterpret_cast<ushort*>(0x4A1874) = 0x0EEB; // Default: 0x438B  //jump a few bytes
				*reinterpret_cast<char*>(0x4A1884) = 0xBA; // Default: 0x00    //allow to set new Hero_ID
				*reinterpret_cast<int*>(0x4A1885) = variables[3327]; // Default: 0x04508B00
				*reinterpret_cast<ushort*>(0x4A2224) = 0x0EEB; // Default: 0x438B  //jump a few bytes
				*reinterpret_cast<char*>(0x4A2234) = 0xBA; // Default: 0x00    //allow to set new Hero_ID (return from SKILL_USE)
				*reinterpret_cast<int*>(0x4A2235) = skillOrItemId; // Default: 0x04508B00
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A1858), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}
			case MenuSubScreen::SkillUse: { //open MENU_SKILL_USE
				//WIP
				break;
			}
			case MenuSubScreen::Teleport: { //open MENU_TELEPORT
				//WIP
				break;
			}
			case MenuSubScreen::Equip: { //open MENU_EQUIP
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10    //speed up transition
				*reinterpret_cast<ushort*>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
				*reinterpret_cast<ushort*>(0x4A22F8) = 0x0EEB; // Default: 0x438B  //jump a few bytes
				*reinterpret_cast<char*>(0x4A2308) = 0xBA; // Default: 0x00    //allow to set new Hero_ID
				*reinterpret_cast<int*>(0x4A2309) = heroId; // Default: 0x04508B00
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A22DC), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}
			case MenuSubScreen::Quit: { //open MENU_QUIT
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10    //speed up transition
				*reinterpret_cast<ushort*>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A2328), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}
			case MenuSubScreen::Status: { //open MENU_STATUS
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10    //speed up transition
				*reinterpret_cast<ushort*>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
				*reinterpret_cast<ushort*>(0x4A2378) = 0x0EEB; // Default: 0x438B  //jump a few bytes
				*reinterpret_cast<char*>(0x4A2388) = 0xBA; // Default: 0x00    //allow to set new Hero_ID
				*reinterpret_cast<int*>(0x4A2389) = heroId; // Default: 0x04508B00
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A235C), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}
			case MenuSubScreen::Order: { //open MENU_ORDER
				*reinterpret_cast<char*>(0x4A109A) = 0x34; // Default: 0x10    //speed up transition
				*reinterpret_cast<ushort*>(0x4A10D4) = 0xBEEB; // Default: 0x8B53  //re-route closeSubMenu() to closeMenu()
				asm volatile("call *%%esi"
							 :
							 : "S"(0x4A23BC), "a"(menu)
							 : "edx", "ecx", "cc", "memory");
				break;
			}

			default:
				break;
		}
	}
}

/******************************************************************************
 *
 *****************************************************************************/
void OpenMenuUnpatch()
{
	*reinterpret_cast<char*>(0x4A109A) = 0x10;
	*reinterpret_cast<ushort*>(0x4A10D4) = 0x8B53;
	*reinterpret_cast<char*>(0x4A17FC) = 0x53;
	*reinterpret_cast<int*>(0x4A17FD) = 0x0068D88B;
	*reinterpret_cast<ushort*>(0x4A1874) = 0x438B;
	*reinterpret_cast<char*>(0x4A1884) = 0x00;
	*reinterpret_cast<int*>(0x4A1885) = 0x04508B00;
	*reinterpret_cast<ushort*>(0x4A2224) = 0x438B;
	*reinterpret_cast<char*>(0x4A2234) = 0x00;
	*reinterpret_cast<int*>(0x4A2235) = 0x04508B00;
	*reinterpret_cast<ushort*>(0x4A22F8) = 0x438B;
	*reinterpret_cast<char*>(0x4A2308) = 0x00;
	*reinterpret_cast<int*>(0x4A2309) = 0x04508B00;
	*reinterpret_cast<ushort*>(0x4A2378) = 0x438B;
	*reinterpret_cast<char*>(0x4A2388) = 0x00;
	*reinterpret_cast<int*>(0x4A2389) = 0x04508B00;
}
}
