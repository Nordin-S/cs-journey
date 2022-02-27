/*
# filnamn: MinaFuncs.hpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-05-01
# Senast ändrat: 2021-10-18
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander
# Betyg: C
 */

#ifndef MINA_FUNCS_HPP
#define MINA_FUNCS_HPP

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <time.h>
#include <regex>

class CMazeGenerator{
	private:
	struct node{
		bool visited;
		bool wall_top;
		bool wall_right;
		bool wall_bottom;
		bool wall_left;
		bool is_s_node;
		bool is_e_node;
		bool is_path;
		std::string display;
	};
	struct pos{
		size_t row;
		size_t col;
		bool hasNode;
	};
	size_t cols, rows;
	pos startNode, endNode;
	std::stack<pos> pathStack;
	std::vector<std::vector<node>> nodesContainer;

	void InitContainer();
	void SetStartEndNodes();
	void WallOpener(pos, pos);
	pos GetRandomNeighbor(pos);
	std::vector<std::vector<node>> NewDefContainer(size_t, size_t, std::string);
	void CleanContainer();

	public:
	CMazeGenerator(int, int);
	void Generate();
	std::vector<std::vector<node>> Presentation();

	std::vector<std::vector<node>> GetMaze(int, int);
	std::vector<std::vector<node>> Solve();
	void PrintMaze(std::vector<std::vector<node>>);

};
#endif