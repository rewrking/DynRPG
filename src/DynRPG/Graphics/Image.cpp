#define DYNRPG_STATIC
#include <DynRPG/Graphics/Image.hpp>

#include <cstring>

#include <DynRPG/Delphi/DStringPtr.hpp>
#include <DynRPG/Graphics/Transition.hpp>
#include <DynRPG/System/System.hpp>
#include <DynRPG/Utility/AsmRegisters.hpp>

namespace RPG
{
enum
{
	MASK_NONE = -1 //!< Used for RPG::Image::draw if no transparent color should be used
};

/******************************************************************************
 *
 *****************************************************************************/
void Image::applyPalette()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x467384), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // FlushPalette
}

/******************************************************************************
 *
 *****************************************************************************/
uchar& Image::pixel(int x, int y)
{
	return pixels[x + y * width];
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::free()
{
	if (!pixels)
		return;
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x466E70), "a"(this)
				 : "edx", "ecx", "cc", "memory"); // FreeImage
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::init(int newWidth, int newHeight)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x466DEC), "a"(this), "d"(newWidth), "c"(newHeight)
				 : "cc", "memory"); // CreateImage
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::setPalette(int* newPalette)
{
	memcpy(palette, newPalette, sizeof(palette));
	applyPalette();
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::copy(Image* image)
{
	if (!image->pixels)
	{
		free();
	}
	else
	{
		init(image->width, image->height);
		memcpy(pixels, image->pixels, image->width * image->height);
	}
	setPalette(image->palette);
	useMaskColor = image->useMaskColor;
	alpha = image->alpha;
	autoResize = image->autoResize;
	colorControl1->red = image->colorControl1->red;
	colorControl1->green = image->colorControl1->green;
	colorControl1->blue = image->colorControl1->blue;
	colorControl1->chroma = image->colorControl1->chroma;
	colorControl2->red = image->colorControl2->red;
	colorControl2->green = image->colorControl2->green;
	colorControl2->blue = image->colorControl2->blue;
	colorControl2->chroma = image->colorControl2->chroma;
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::loadFromFile(std::string filename, bool throwErrors, bool autoResize)
{
	this->autoResize = autoResize;
	DStringPtr s(filename);
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx), "=c"(_ecx)
				 : "S"(0x467ABC), "a"(this), "d"(s.str), "c"(throwErrors)
				 : "cc", "memory");
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::draw(int x, int y, uchar* newPixels, int srcWidth, int srcHeight, int srcLineWidth, int maskColor)
{
	if (maskColor != static_cast<int>(Transition::None))
	{
		for (int cy = 0; cy < srcHeight; cy++)
		{
			uchar* dst = pixels + x + (y + cy) * width;
			uchar* src = newPixels + cy * srcLineWidth;
			for (int cx = 0; cx < srcWidth; cx++)
			{
				if (src[cx] != maskColor)
					dst[cx] = src[cx];
			}
		}
	}
	else
	{
		for (int cy = 0; cy < srcHeight; cy++)
		{
			uchar* dst = pixels + x + (y + cy) * width;
			uchar* src = newPixels + cy * srcLineWidth;
			memcpy(dst, src, srcWidth);
		}
	}
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::draw(int x, int y, Image* image, int srcX, int srcY, int srcWidth, int srcHeight, int maskColor)
{
	if (srcWidth == -1)
		srcWidth = image->width;
	if (srcHeight == -1)
		srcHeight = image->height;
	draw(x, y, &image->pixel(srcX, srcY), srcWidth, srcHeight, image->width, maskColor);
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::clear()
{
	memset(pixels, 0, width * height);
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::setSystemPalette()
{
	setPalette(system->systemGraphic->systemImage->palette);
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::drawText(int x, int y, std::string text, int color)
{
	DStringPtr s(text);
	asm volatile(
		"pushl %7;"
		"pushl %8;"
		"pushl %9;"
		"call *%%esi;"
		: "=a"(_eax), "=d"(_edx), "=c"(_ecx)
		: "S"(0x4892AC), "a"(system->systemGraphic), "d"(this), "c"(x), "m"(y), "m"(s.str), "m"(color)
		: "cc", "memory" // DrawText
	);
}

/******************************************************************************
 * TODO: revisit drawText / drawString
 *****************************************************************************/
void Image::drawString(int x, int y, std::string text, int color)
{
	DStringPtr* par2 = new DStringPtr(text); // *cue holy music*
	asm volatile("push %%eax"
				 :
				 : "a"(y));
	asm volatile("push %%eax"
				 :
				 : "a"(par2->str));
	asm volatile("push %%eax"
				 :
				 : "a"(color));
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4892AC), "a"(system->systemGraphic), "c"(x), "d"(this)
				 : "cc", "memory");
	delete par2;
}

/******************************************************************************
 *
 *****************************************************************************/
Image* Image::create()
{
	Image* ret;
	asm volatile("call *%%esi"
				 : "=a"(ret), "=d"(_edx)
				 : "S"(0x466D3C), "a"(*(void**)0x46679C), "d"(1)
				 : "ecx", "cc", "memory"); // TAuroraSheet_Constructor
	return ret;
}

/******************************************************************************
 *
 *****************************************************************************/
Image* Image::create(int newWidth, int newHeight)
{
	Image* image = create();
	image->init(newWidth, newHeight);
	return image;
}

/******************************************************************************
 *
 *****************************************************************************/
Image* Image::create(Image* templateImage)
{
	Image* image = create();
	image->copy(templateImage);
	return image;
}

/******************************************************************************
 *
 *****************************************************************************/
void Image::destroy(Image*& image)
{
	asm volatile("call *%%esi"
				 : "=a"(_eax), "=d"(_edx)
				 : "S"(0x466DB4), "a"(image), "d"(1)
				 : "ecx", "cc", "memory"); // TAuroraSheet_Destructor
	image = NULL;
}
}
