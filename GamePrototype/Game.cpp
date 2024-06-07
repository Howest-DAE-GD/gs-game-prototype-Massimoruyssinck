#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Block.h"
#include "Texture.h"
#include "iostream"

Game::Game( const Window& window ) 
	:BaseGame{ window }
{

	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
		for (int collumns = 0; collumns < 4; collumns++)
		{
	for (int rows = 0; rows < 4; rows++)
	{
			m_FieldBlocks[rows][collumns] = new Block{ true ,collumns,rows };
		}
	}
	const int randomA = rand() % 4;
	const int randomB = rand() % 4;

	delete m_FieldBlocks[randomA][randomB];
	m_FieldBlocks[randomA][randomB] = new Block{ randomB ,randomA };
	m_GameWon = false;
	m_GameLost = false;

}

void Game::Cleanup( )
{

		for (int collumns = 0; collumns < 4; collumns++)
		{
	for (int rows = 0; rows < 4; rows++)
	{
			delete m_FieldBlocks[rows][collumns];
		}
	}
}

void Game::Update( float elapsedSec )
{
	if (m_direction == 0)
	{
		std::cout << "UP";

		for (int movesA = 0; movesA < 3; movesA++)
		{
			for (int moves = 0; moves < 3; moves++)
			{

				for (int collums = 0; collums < 4; collums++)
				{
					for (int rows = 2; rows >= 0; rows--)
					{
						if (!m_FieldBlocks[rows][collums]->CheckEmpty() && m_FieldBlocks[rows + 1][collums]->CheckEmpty())
						{
							delete m_FieldBlocks[rows + 1][collums];
							m_FieldBlocks[rows + 1][collums] = new Block{ collums,rows + 1,m_FieldBlocks[rows][collums]->CheckValue() };
							delete m_FieldBlocks[rows][collums];
							m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
						}
					}
				}
			}

			for (int moves = 0; moves < 3; moves++)
			{

				for (int collums = 0; collums < 4; collums++)
				{
					for (int rows = 2; rows >= 0; rows--)
					{
						if (!m_FieldBlocks[rows][collums]->CheckEmpty() && !m_FieldBlocks[rows + 1][collums]->CheckEmpty() && m_FieldBlocks[rows][collums]->CheckValue() == m_FieldBlocks[rows + 1][collums]->CheckValue())
						{
							m_FieldBlocks[rows + 1][collums]->IncreaseBlock();
							delete m_FieldBlocks[rows][collums];
							m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
						}
					}
				}
			}
		}


		/*
		for (int rows = 0; rows < 4; rows++)
		{
			for (int collumns = 0; collumns < 4; collumns++)
			{
				if (rows == 2 && !m_FieldBlocks[collumns][2]->CheckEmpty() && m_FieldBlocks[collumns][3]->CheckEmpty())
				{
					m_FieldBlocks[collumns][3] = m_FieldBlocks[collumns][2];
					m_FieldBlocks[collumns][2] = new Block{ true,collumns,2 };
				}
			}
		}
		*/
	}
	if (m_direction == 1)
	{
		std::cout << "RIGHT";

		for (int movesA = 0; movesA < 3; movesA++)
		{
			for (int moves = 0; moves < 3; moves++)
			{

				for (int collums = 2; collums >= 0; collums--)
				{
					for (int rows = 0; rows < 4; rows++)
					{
						if (!m_FieldBlocks[rows][collums]->CheckEmpty() && m_FieldBlocks[rows][collums + 1]->CheckEmpty())
						{
							delete m_FieldBlocks[rows][collums + 1];
							m_FieldBlocks[rows][collums + 1] = new Block{ collums + 1,rows,m_FieldBlocks[rows][collums]->CheckValue() };
							delete m_FieldBlocks[rows][collums];
							m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
						}

					}
				}
			}
			for (int moves = 0; moves < 3; moves++)
			{

				for (int collums = 2; collums >= 0; collums--)
				{
					for (int rows = 0; rows < 4; rows++)
					{
						if (!m_FieldBlocks[rows][collums]->CheckEmpty() && !m_FieldBlocks[rows][collums + 1]->CheckEmpty() && m_FieldBlocks[rows][collums]->CheckValue() == m_FieldBlocks[rows][collums + 1]->CheckValue())
						{
							m_FieldBlocks[rows][collums + 1]->IncreaseBlock();
							delete m_FieldBlocks[rows][collums];
							m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
						}
					}
				}
			}
		}
	}
	if (m_direction == 2)
	{
		std::cout << "LEFT";

		for (int movesA = 0; movesA < 3; movesA++)
		{
			for (int moves = 0; moves < 3; moves++)
			{

				for (int collums = 1; collums <= 3; collums++)
				{
					for (int rows = 0; rows < 4; rows++)
					{
						if (!m_FieldBlocks[rows][collums]->CheckEmpty() && m_FieldBlocks[rows][collums - 1]->CheckEmpty())
						{
							delete m_FieldBlocks[rows][collums - 1];
							m_FieldBlocks[rows][collums - 1] = new Block{ collums - 1,rows,m_FieldBlocks[rows][collums]->CheckValue() };
							delete m_FieldBlocks[rows][collums];
							m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
						}
					}
				}
			}

			for (int moves = 0; moves < 3; moves++)
			{

				for (int collums = 1; collums <= 3; collums++)
				{
					for (int rows = 0; rows < 4; rows++)
					{
						if (!m_FieldBlocks[rows][collums]->CheckEmpty() && !m_FieldBlocks[rows][collums - 1]->CheckEmpty() && m_FieldBlocks[rows][collums]->CheckValue() == m_FieldBlocks[rows][collums - 1]->CheckValue())
						{
							m_FieldBlocks[rows][collums - 1]->IncreaseBlock();
							delete m_FieldBlocks[rows][collums];
							m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
						}
					}
				}
			}
		}
	}
	if (m_direction == 3)
	{
		std::cout << "DOWN";

		for (int moves = 0; moves < 3; moves++)
		{

			for (int collums = 0; collums < 4; collums++)
			{
				for (int rows = 1; rows <= 3; rows++)
				{
					if (!m_FieldBlocks[rows][collums]->CheckEmpty() && m_FieldBlocks[rows - 1][collums]->CheckEmpty())
					{
						delete m_FieldBlocks[rows - 1][collums];
						m_FieldBlocks[rows - 1][collums] = new Block{ collums,rows - 1,m_FieldBlocks[rows][collums]->CheckValue() };
						delete m_FieldBlocks[rows][collums];
						m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
					}
				}
			}
		}

		for (int moves = 0; moves < 3; moves++)
		{

			for (int collums = 0; collums < 4; collums++)
			{
				for (int rows = 1; rows <= 3; rows++)
				{
					if (!m_FieldBlocks[rows][collums]->CheckEmpty() && !m_FieldBlocks[rows - 1][collums]->CheckEmpty() && m_FieldBlocks[rows][collums]->CheckValue() == m_FieldBlocks[rows - 1][collums]->CheckValue())
					{
						m_FieldBlocks[rows - 1][collums]->IncreaseBlock();
						delete m_FieldBlocks[rows][collums];
						m_FieldBlocks[rows][collums] = new Block{ true,collums,rows };
					}
				}
			}
		}
	}
	int emptySquares = 0;
	
		for (int collumns = 0; collumns < 4; collumns++)
		{
	for (int rows = 0; rows < 4; rows++)
	{
			if (m_FieldBlocks[rows][collumns]->CheckEmpty())
			{
				emptySquares++;
			}
			if (m_FieldBlocks[rows][collumns]->CheckValue() == 10)
			{
				m_GameWon = true;
			}
		}
	}
	if (emptySquares == 0 && m_direction != 4 && !m_GameWon)
	{
		m_GameLost = true;
	}
	if (emptySquares > 0 && m_direction != 4)
	{
	int randomA = rand() % 4;
	int randomB = rand() % 4;
	do
	{
		randomA = rand() % 4;
		randomB = rand() % 4;

	} while (!m_FieldBlocks[randomA][randomB]->CheckEmpty());

	delete m_FieldBlocks[randomA][randomB];
	m_FieldBlocks[randomA][randomB] = new Block{ randomB ,randomA };
	}

	m_direction = 4;
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
	if (m_Restart)
	{
		Cleanup();
		Initialize();
		m_Restart = false;
	}
}

void Game::Draw( ) const
{
	glColor4f(0.4, 0.8, 0.4, 1);
	utils::FillRect(Rectf{ 20,20,740,740 });
	glColor4f(0.4, 0.9, 0.4, 1);
	utils::FillRect(Rectf{ 40,40,700,700 });
		for (int collumns = 0; collumns < 4; collumns++)
		{
	for (int rows = 0; rows < 4; rows++)
	{
			m_FieldBlocks[rows][collumns]->Draw();
		}
		}
		if (m_GameWon) {

			glColor4f(0.4, 0.8, 0.4, 1);
			utils::FillRect(Rectf{ 20,20,740,740 });
			glColor4f(0.4, 0.9, 0.4, 1);
			utils::FillRect(Rectf{ 40,40,700,700 });
			glColor4f(0, 1, 0, 1);
			utils::FillRect(Rectf{ 60,60,660,660 });

		}
		else if (m_GameLost) {

			glColor4f(0.4, 0.8, 0.4, 1);
			utils::FillRect(Rectf{ 20,20,740,740 });
			glColor4f(0.4, 0.9, 0.4, 1);
			utils::FillRect(Rectf{ 40,40,700,700 });
			glColor4f(1, 0, 0, 1);
			utils::FillRect(Rectf{ 60,60,660,660 });

		}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
	const Uint8* keyStateArrPtr = SDL_GetKeyboardState(nullptr);
	if (!m_GameWon && !m_GameLost)
	{

	if (keyStateArrPtr[SDL_SCANCODE_W] && !keyStateArrPtr[SDL_SCANCODE_D] && !keyStateArrPtr[SDL_SCANCODE_S] && !keyStateArrPtr[SDL_SCANCODE_A]){m_direction = 0;}
	if (keyStateArrPtr[SDL_SCANCODE_D] && !keyStateArrPtr[SDL_SCANCODE_W] && !keyStateArrPtr[SDL_SCANCODE_S] && !keyStateArrPtr[SDL_SCANCODE_A]){m_direction = 1;}
	if (keyStateArrPtr[SDL_SCANCODE_A] && !keyStateArrPtr[SDL_SCANCODE_D] && !keyStateArrPtr[SDL_SCANCODE_S] && !keyStateArrPtr[SDL_SCANCODE_W]){m_direction = 2;}
	if (keyStateArrPtr[SDL_SCANCODE_S] && !keyStateArrPtr[SDL_SCANCODE_D] && !keyStateArrPtr[SDL_SCANCODE_W] && !keyStateArrPtr[SDL_SCANCODE_A]){m_direction = 3;}
	if (keyStateArrPtr[SDL_SCANCODE_UP] && !keyStateArrPtr[SDL_SCANCODE_RIGHT] && !keyStateArrPtr[SDL_SCANCODE_DOWN] && !keyStateArrPtr[SDL_SCANCODE_LEFT]){m_direction = 0;}
	if (keyStateArrPtr[SDL_SCANCODE_RIGHT] && !keyStateArrPtr[SDL_SCANCODE_UP] && !keyStateArrPtr[SDL_SCANCODE_DOWN] && !keyStateArrPtr[SDL_SCANCODE_LEFT]){m_direction = 1;}
	if (keyStateArrPtr[SDL_SCANCODE_LEFT] && !keyStateArrPtr[SDL_SCANCODE_RIGHT] && !keyStateArrPtr[SDL_SCANCODE_DOWN] && !keyStateArrPtr[SDL_SCANCODE_UP]){m_direction = 2;}
	if (keyStateArrPtr[SDL_SCANCODE_DOWN] && !keyStateArrPtr[SDL_SCANCODE_RIGHT] && !keyStateArrPtr[SDL_SCANCODE_UP] && !keyStateArrPtr[SDL_SCANCODE_LEFT]){m_direction = 3;}
	}
	else
	{
		if (keyStateArrPtr[SDL_SCANCODE_SPACE])
		{
			m_Restart = true;
		}
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
	
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
