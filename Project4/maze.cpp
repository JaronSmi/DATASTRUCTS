#include "maze.h"

maze::maze(int r, int c){
	row = r;
	col = c;
	theMaze.push_back(mazeCell(false, true, false, true));
	for(int i = 0; i < (row * col) - 2; ++i){
		theMaze.push_back(mazeCell());
	}
	theMaze.push_back(mazeCell(true, false, true, false));
}

bool maze::neighbors(int cell, int neigh) const
{
	//if cell directly next to neighbor
	if( ( (cell + 1) == neigh || (cell - 1) == neigh) && (neigh % col != 0){
		std::cout  << cell << " and " << neigh << " are neighbors.\n ";
		return true;
	}


	//if cell directly above/below neighbor.
	else if ((cell + col) == neigh || (cell - col) == neigh){
		std::cout  << cell << " and " << neigh << " are neighbors. \n";
		return true;
	}
	
	//if cell not by neighbor
	return false;
	
}

void maze::smashWall(int cell, int neigh)
{
	if(cell + 1 == neigh)
	{
		theMaze[cell].setRight(false);
	}
	else if(cell - 1 == neigh)
	{
		theMaze[cell].setLeft(false);
	}
	else if(cell + col == neigh)
	{
		theMaze[cell].setBot(false);
	}
	else
	{
		theMaze[cell].setTop(false);
	}
}

void maze::printMaze()
{
	std::cout << "  ";
	for(int i = 0; i < col - 1; ++i)
		std::cout << " _";

	for(int i = 0; i < row*col; ++i){
		if(i % col == 0){
			if(i != 0 && theMaze[i].getRight() == true)
				std::cout << "|";
			std::cout << std::endl;
		}
		
		if(theMaze[i].getLeft() == true){
			std::cout << "|";
		}
		else{
			std::cout << " ";
		}
		if(theMaze[i].getBot() == true){
			std::cout << "_";
		}
		else{
			std::cout << " ";
		}
	

	}
	std::cout << std::endl;
}
