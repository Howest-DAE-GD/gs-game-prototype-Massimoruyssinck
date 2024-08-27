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
	m_Color = rand() % 3 + 1;
}
Block::Block(int posX, int posY) : m_PosX{ posX }, m_PosY{ posY }
{
	m_Value = (rand() % 2);
	m_empty = false;

	m_Color = rand() % 3 + 1;
}
Block::Block(int posX, int posY, int value, int color) : m_PosX{ posX }, m_PosY{ posY }, m_Value{ value }, m_Color{ color}
{
	m_empty = false;
}
Block::Block(bool empty, int posX, int posY) :  m_empty{empty}, m_PosX{ posX }, m_PosY{ posY }
{
	m_Value = (rand() % 2 );

	m_Color = rand() % 3 + 1;

}
int Block::CheckValue()
{
	return m_Value;
}
int Block::CheckColor()
{
	return m_Color;
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
		if (m_Color == 1)
		{
			glColor4f(0, 0, ((float)m_Value/5) + 0.20, 1);
		}
		else if (m_Color == 2)
		{
			glColor4f(0, ((float)m_Value / 5 ) +0.20, 0, 1);
		}
		else if (m_Color == 3)
		{
			glColor4f(((float)m_Value /5) + 0.20,0 , 0, 1);
		}
		utils::FillRect(Rectf{ (60 + (float)112 * m_PosX),(60 + (float)112 * m_PosY),100,100 });
	}
	else
	{
		glColor4f(1, 1, 1, 1);
		utils::FillRect(Rectf{ (60 + (float)112*m_PosX),(60 + (float)112 *m_PosY),100,100});

	}

	
}