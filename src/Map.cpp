#include <DynRPG/Map.h>

namespace RPG
{
MapProperties*& Map::properties = (**reinterpret_cast<MapProperties***>(0x4CDD14));

int Map::getCameraX()
{
	return cameraSubX / 16;
}

int Map::getCameraY()
{
	return cameraSubY / 16;
}

void Map::setCamera(int x, int y)
{
	x *= 16;
	y *= 16;
	int* p = (**(int***)(0x4CDE54));
	p[43] += x - cameraSubX;
	p[44] += y - cameraSubY;
	p[45] += x - cameraSubX;
	p[46] += y - cameraSubY;
}

void Map::moveCamera(int offsetX, int offsetY, int speed)
{
	int* p = (**(int***)(0x4CDE54));
	p[45] += offsetX * 16;
	p[46] += offsetY * 16;
	p[47] = speed;
}

int Map::getWidth()
{
	return (**(int***)(0x4CDD14))[5];
}

int Map::getHeight()
{
	return (**(int***)(0x4CDD14))[6];
}

void Map::updateEvents()
{
	asm volatile("call *%%esi"
				 : "=a"(_eax)
				 : "S"(0x4AB8B4), "a"(events.ptr)
				 : "edx", "ecx", "cc", "memory");
}

int Map::getLowerLayerTileId(int x, int y)
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4A80CC), "a"(this), "c"(y), "d"(x)
				 : "cc", "memory");
	return out;
}

int Map::getUpperLayerTileId(int x, int y)
{
	int out;
	asm volatile("call *%%esi"
				 : "=a"(out), "=c"(_ecx), "=d"(_edx)
				 : "S"(0x4A80F4), "a"(this), "c"(y), "d"(x)
				 : "cc", "memory");
	return out;
}

int Map::getTerrainId(int tileId)
{
	int out;
	asm volatile("movl 20(%%eax), %%eax; call *%%esi"
				 : "=a"(out), "=d"(_edx)
				 : "S"(0x47D038), "a"(this), "d"(tileId)
				 : "ecx", "cc", "memory");
	return out;
}

int Map::getEventAt(int x, int y)
{
	// Since the events array goes by event ID, create a counter that increments
	// when an event is not found at a specific array location, thus ensuring
	// all events get checked
	// example: events 1 and 10 exist on the map, while 2-9 were deleted at some point
	int counter = events.count();
	for (int i = 1; i <= counter; ++i)
	{
		if (events[i])
		{
			if (events[i]->x == x && events[i]->y == y)
				return i;
		}
		else
		{
			counter++;
		}
	}
	return 0;
}

}
