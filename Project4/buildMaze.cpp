#include "maze.h"
#include "DisjSets.h"
#include "mazeCell.h"

int main(){
	
	int rows, cols, total, n1, n2;
	
	std::cout << "Enter number of rows (greater than 0):: ";
	cin >> rows;
	while(rows < 1){
		std::cout << "Error, invalid input." << std::endl;
		std::cout << "Enter number of rows (greater than 0):: ";
		std::cin >> rows;
	}
	
	std::cout << "Enter number of Columns(Greater than 0):: ";
	cin >> cols;
	while (cols < 1){
		std::cout << "Error, invalid input." << std::endl;
		std::cout << "Enter number of Columns(Greater than 0):: ";
		std::cin >> cols;
	}
	
	total = rows*cols;

	DisjSets set(total);
	maze Maze(rows, cols);
	bool loop = false;
	
	
	while(loop == false)
	{

		std::cout << "enter first neighbor:: ";
		std::cin >> n1;
		std::cout << "enter second neighbor:: ";
		std::cin >> n2;
		
		if(set.isConnected(n1, n2) == false){
			if(Maze.neighbors(n1, n2)){
				set.unionSets(n1, n2);
				std::cout << "Smashing walls.\n";
				Maze.smashWall(n1, n2);
				Maze.smashWall(n2, n1);
				Maze.printMaze();
			}
			else{
				std::cout << "Cells are not neighbors. \n";
				Maze.printMaze();
			}
		}
		else{
			std::cout << "Path already exists here.\n";
			Maze.printMaze();
		}
		
		loop = set.isConnected(0, (total - 1));
	}
	
	std::cout << "The maze is built. Exiting program...\n\n\n";

}
