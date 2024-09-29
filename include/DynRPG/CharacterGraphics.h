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
	DListPtr<Image*>* images;
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

	int addFile(const std::string& filename);

	int findIndex(const std::string& filename);

	int require(const std::string& filename);

	/*! \brief Draws a character graphic from the cache. The coordinates specify the **bottom center** of the sprite! Also, in most cases you need to set the `transparency` value before drawing, because otherwise it will be whatever the last drawn graphic happened to use!
		\example
		int index = RPG::map->properties->charsetGraphics->require("monster1");
  		RPG::map->properties->charsetGraphics->transparency = 0;
		RPG::map->properties->charsetGraphics->draw(RPG::screen->canvas, 100, 100, index, 3, RPG::DIR_DOWN, RPG::ANI_FRAME_MIDDLE_A, RPG::TSD_DISP_NORMAL);
	*/
	void draw(Canvas* canvas, int x, int y, int fileIndex, int spriteIndex, Direction direction, AnimationFrameCharset step, TerrainSpriteDisplay spriteDisplay);
};

}

#endif // DYNRPG_CHARACTER_GRAPHICS_H
