#pragma once
#include <Texture.h>
class Block
{
public:
	Block();
	Block(int posX, int posY);
	Block(int posX, int posY, int value);
	Block( bool empty, int posX, int posY);
	 void Draw() const;
	int CheckValue();
	bool CheckEmpty();
	void IncreaseBlock();
	
protected:
	bool m_empty;
	int m_Value;
	int m_PosX;
	int m_PosY;
};
