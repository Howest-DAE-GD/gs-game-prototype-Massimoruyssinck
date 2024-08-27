#pragma once
#include <Texture.h>
class Block
{
public:
	Block();
	Block(int posX, int posY);
	Block(int posX, int posY, int value, int color);
	Block( bool empty, int posX, int posY);
	 void Draw() const;
	 int CheckValue();
	 int CheckColor();
	bool CheckEmpty();
	void IncreaseBlock();
	
protected:
	bool m_empty;
	int m_Value;
	int m_PosX;
	int m_PosY;
	int m_Color;
};
