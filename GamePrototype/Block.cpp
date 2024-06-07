#include "pch.h"
#include "Block.h"
#include "utils.h"
#include "Texture.h"
Block::Block()
{
	m_PosX = 1;
	m_PosY = 1;
	m_Value = (rand() % 2 + 1);
	m_empty = false;
}
Block::Block(int posX, int posY) : m_PosX{ posX }, m_PosY{ posY }
{
	m_Value = (rand() % 2);
	m_empty = false;
}
Block::Block(int posX, int posY, int value) : m_PosX{ posX }, m_PosY{ posY }, m_Value{ value }
{
	m_empty = false;
}
Block::Block(bool empty, int posX, int posY) :  m_empty{empty}, m_PosX{ posX }, m_PosY{ posY }
{
	m_Value = (rand() % 2 );
}
int Block::CheckValue() 
{
	return m_Value;
}
bool Block::CheckEmpty()
{
	return m_empty;
}

void Block::IncreaseBlock()
{
	m_Value++;
}

 void Block::Draw() const
{
	if (m_empty == false) 
	{

	glColor4f(0, (float)m_Value/10, 0, 1);
	utils::FillRect(Rectf{ (60 + (float)170 * m_PosX),(60 + (float)170 * m_PosY),150,150 });
	}
	else
	{
		glColor4f(1, 1, 1, 1);
		utils::FillRect(Rectf{ (60 + (float)170*m_PosX),(60 + (float)170*m_PosY),150,150 });

	}


}