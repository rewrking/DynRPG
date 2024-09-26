#ifndef DYNRPG_CHARACTER_GRAPHICS_H
#define DYNRPG_CHARACTER_GRAPHICS_H

#include <DynRPG/Canvas.h>
#include <DynRPG/Character.h>
#include <DynRPG/DList.h>
#include <DynRPG/Enum/AnimationFrameCharset.h>
#include <DynRPG/Enum/TerrainSpriteDisplay.h>
#include <DynRPG/Image.h>
#include <DynRPG/WindowMessageBox.h>

namespace RPG
{
class DYNRPG_API CharacterGraphics
{
public:
	void** vTable;
	WindowMessageBox* filenames; // WindowMessageBox should actually be called DStringList
	DList<Image*>* images;
	DList<bool>* inUse;
	bool useMaskColor;
	int transparency; // 0-8 (corresponding to 255-15 opacity values in steps of 30)
	bool monochrome;

	/*
		Methods:
		constructor @ 0x4839D0
		destructor @ 0x483A2C
	*/
	void clearAll();

	void markAllUnused();

	void cleanUp();

	// Note: isCharSet2 in addFile/draw should be always false! It was intended for large charsets, a feature that was never finished. Setting it to true in addFile would attempt to load a hardcoded file "CharSet2\主人公1", in draw it has no effect.
	int addFile(std::string filename, bool isCharSet2);

	int findIndex(std::string filename);

	/**
	 *
	 * @example
	 * int index = RPG::map->properties->charsetGraphics->findIndex("Monster1");
	 * if (index == -1) index = RPG::map->properties->charsetGraphics->add("Monster1");
	 * RPG::map->properties->charsetGraphics->draw(RPG::screen->canvas, 100, 100, index, 3, RPG::DIR_DOWN, RPG::ANI_FRAME_MIDDLE_A, RPG::TSD_DISP_NORMAL, false);
	 */
	void draw(Canvas* canvas, int x, int y, int fileIndex, int spriteIndex,
		Direction direction, AnimationFrameCharset step, TerrainSpriteDisplay spriteDisplay,
		bool isCharSet2);
};

}

#endif // DYNRPG_CHARACTER_GRAPHICS_H
