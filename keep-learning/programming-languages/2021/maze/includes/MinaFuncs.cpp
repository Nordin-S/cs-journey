/*
# filnamn: MinaFuncs.cpp
# Skrivet av: Nordin Suleimani
# Skapat datum: 2021-05-01
# Senast ändrat: 2021-10-18
# Kurs: Objectbaserad Programmering
# Handledare: Jimmy Åhlander
# Betyg: C
 */

#include "MinaFuncs.hpp"
CMazeGenerator::CMazeGenerator(int inY, int inX){
			PrintMaze(GetMaze(inY, inX));
};

/*
# Init container, sets nodesContainer to default values with specified rows,
# cols and look.
*/
void CMazeGenerator::InitContainer(){
    nodesContainer = NewDefContainer(rows, cols, "██");
}

/*
# New default container, creates a new continer with default values, size and
# display look.
# @param "rows", type of size_t.
# @param "cols", type of size_t.
# @param "look", type of string.
# @returns a two dimensional vector consisting of nodes.
*/
std::vector<std::vector<CMazeGenerator::node>> CMazeGenerator::NewDefContainer(size_t rows, size_t cols, std::string look){
    std::vector<std::vector<CMazeGenerator::node>> newNodeContainer;

    node defaultNode;
    defaultNode.visited = false;
    defaultNode.wall_top = true;
    defaultNode.wall_right = true;
    defaultNode.wall_bottom = true;
    defaultNode.wall_left = true;
    defaultNode.is_s_node = false;
    defaultNode.is_e_node = false;
    defaultNode.is_path = false;
    defaultNode.display = look;
    newNodeContainer.resize(rows, std::vector<CMazeGenerator::node>(cols, defaultNode));
    return newNodeContainer;
}

/*
# Clean container, emptyies nodesContainer, startNode and endNode.
*/
void CMazeGenerator::CleanContainer(){
    nodesContainer.resize(0, std::vector<CMazeGenerator::node>(0));
    startNode = {.row = 0, .col = 0, .hasNode = false};
    endNode = {.row = 0, .col = 0, .hasNode = false};
}

/*
# Generate, uses DFS algorythm to traverse through nodes in a two dimensional
# vector container, randomly picks a possible neighbor if there is one that has
# not been visited and visits it and adds nodes to a stack in order to be able
# to trackback to neighbors that need to be visited. Rince and repeat till
# every node has been visited.
*/
void CMazeGenerator::Generate(){
    CleanContainer();
    InitContainer();
    SetStartEndNodes();
    pos n;
    std::stack<pos> nodesStack;
    n = startNode;

    nodesContainer[n.row][n.col].visited = true;
    nodesStack.push(n);

    while(!nodesStack.empty()){
        n = nodesStack.top();
        if(nodesContainer[n.row][n.col].is_e_node){
            pathStack = nodesStack;
        }
        nodesStack.pop();
        pos randomNode = GetRandomNeighbor(n);
        if(randomNode.hasNode){
            nodesStack.push(n);
            WallOpener(n, randomNode);
            nodesContainer[randomNode.row][randomNode.col].visited = true;
            nodesStack.push(randomNode);
        }
    }
}

/*
# Get random neighbor node, randomly chooses between possible neighbors in a
# given container and returns a neighbor if one is found.
# @param "nContainer", two dimensional vector of type node.
# @param "loc", struct of type pos.
# @returns a struct of type pos contining the position of a neighbor.
*/
CMazeGenerator::pos CMazeGenerator::GetRandomNeighbor(pos loc){
    std::vector<pos> notVisited;
    pos randomNode = {.row = 0, .col = 0, .hasNode = false};

    // Check to see if you are withing the walls then look for neighbors
    // on same row and cols.
	if(loc.row > 0){// top neighbor
		if(!nodesContainer[loc.row - 1][loc.col].visited){
			notVisited.push_back({loc.row - 1, loc.col, .hasNode = true});
		}
	}
	if(loc.col < cols - 1){// right neighbor
		if(!nodesContainer[loc.row][loc.col + 1].visited){
			notVisited.push_back({loc.row, loc.col + 1, .hasNode = true});
		}
	}
	if(loc.col > 0){// left neighbor
		if(!nodesContainer[loc.row][loc.col - 1].visited){
			notVisited.push_back({loc.row, loc.col - 1, .hasNode = true});
		}
	}
	if(loc.row < rows - 1){// bottom neighbor
		if(!nodesContainer[loc.row + 1][loc.col].visited){
			notVisited.push_back({loc.row + 1, loc.col, .hasNode = true});
		}
	}

    // randomly pick a neighbor to return
    if(notVisited.size() > 0){
        randomNode = notVisited[rand() % notVisited.size()];
    }

    return randomNode;
}

/*
# Wall opener, opens a path between a node and it's neighbor by setting the
# given nodes wall in the direction of the neighbor to false
# @param "nodeToOpen", a struct of type pos.
# @param "toNeighbor", a struct of type pos.
*/
void CMazeGenerator::WallOpener(pos nodeToOpen, pos toNeighbor){
    if(nodeToOpen.row > toNeighbor.row){
        nodesContainer[nodeToOpen.row][nodeToOpen.col].wall_top = false;
    }else if(nodeToOpen.col > toNeighbor.col){
        nodesContainer[nodeToOpen.row][nodeToOpen.col].wall_left = false;
    }else if(nodeToOpen.col < toNeighbor.col){
        nodesContainer[nodeToOpen.row][nodeToOpen.col].wall_right = false;
    }else{
        nodesContainer[nodeToOpen.row][nodeToOpen.col].wall_bottom = false;
    }
}

/*
# Presentation, Takes in a two dimensional nodes vector, creates a two
# dimensional nodes vector twice the size + 1 of the input and inserts the
# input vector into the new larger vector every other row and col
# @param "toPresent", two dimensional vector of type node.
# @returns two dimensional vector of type node.
*/
std::vector<std::vector<CMazeGenerator::node>> CMazeGenerator::Presentation(){
    std::vector<std::vector<CMazeGenerator::node>> presentation;
    //set to correct cols and rows
    size_t largerRows = nodesContainer.size() * 2 + 1;
    size_t largerCols = nodesContainer[0].size() * 2 + 1;

    //fill the presentation vector with default values
    presentation = NewDefContainer(largerRows, largerCols, "██");

    // insert smaller container nodes into larger one every other row and col
    for(size_t r=1; r < largerRows; r+=2){
        for(size_t c=1; c < largerCols; c+=2){
            presentation[r][c] = nodesContainer[r/2][c/2];
            // set each inserted node to correct display
            if(presentation[r][c].is_path)
                presentation[r][c].display = "🐭";
            else
                presentation[r][c].display = "  ";
            // set start and end display to nearest wall
            if(presentation[r][c].is_s_node){
                if(r == 1 && c > 1 && c < largerCols - 2){
                    presentation[r-1][c].display = "S ";
                }else if(r == largerRows - 2 && c > 1 && c < largerCols - 2){
                    presentation[r+1][c].display = "S ";
                }else if(c == 1){
                    presentation[r][c-1].display = "S ";
                }else if(c == largerCols - 2){
                    presentation[r][c+1].display = "S ";
                }
            }else if(presentation[r][c].is_e_node){
                if(r == 1 && c > 1 && c < largerCols - 2){
                    presentation[r-1][c].display = "E ";
                }else if(r == largerRows - 2 && c > 1 && c < largerCols - 2){
                    presentation[r+1][c].display = "E ";
                }else if(c == 1){
                    presentation[r][c-1].display = "E ";
                }else if(c == largerCols - 2){
                    presentation[r][c+1].display = "E ";
                }
            }
            //change display of wall nodes between original nodes if wall should be open.
            if(!presentation[r][c].wall_top)
                presentation[r-1][c].display = "  ";
            if(!presentation[r][c].wall_right)
                presentation[r][c+1].display = "  ";
            if(!presentation[r][c].wall_left)
                presentation[r][c-1].display = "  ";
            if(!presentation[r][c].wall_bottom)
                presentation[r+1][c].display = "  ";
        }
    }
    return presentation;
}

/*
# SetStartEndNodes, randomly chosing a side of a two dimensional vector to be
# the starting side, picking either a row number and column from the edge then
# choosing an endNode on the facing side in the same way.
*/
void CMazeGenerator::SetStartEndNodes(){
    size_t rStartSide = rand() % 4 + 1;

    //top and bottom row
    if(rStartSide == 1){
        startNode = {.row = 0, .col = rand() % cols, .hasNode = true};
        endNode = {.row = rows - 1, .col = rand() % cols, .hasNode = true};
    }else if(rStartSide == 3){
        startNode = {.row = rows - 1, .col = rand() % cols, .hasNode = true};
        endNode = {.row = 0, .col = rand() % cols, .hasNode = true};
    //right and left col
    }else if(rStartSide == 2){
        startNode = {.row = rand() % rows, .col = 0, .hasNode = true};
        endNode = {.row = rand() % rows, .col = cols - 1, .hasNode = true};
    }else if(rStartSide == 4){
        startNode = {.row = rand() % rows, .col = cols - 1, .hasNode = true};
        endNode = {.row = rand() % rows, .col = 0, .hasNode = true};
    }
        nodesContainer[startNode.row][startNode.col].is_s_node = true;
        nodesContainer[endNode.row][endNode.col].is_e_node = true;
}

/*
# GetMaze, divides rows and cols input, calls generate to create a maze and
# returns a two dimensional maze ready to be printed.
# @param "rows", a position value of type int.
# @param "cols", a position value of type int.
# @returns two dimensional vector of type node.
*/
std::vector<std::vector<CMazeGenerator::node>> CMazeGenerator::GetMaze(int rows, int cols){
    this->rows = rows / 2;
    this->cols = cols / 2;
    Generate();
    return Presentation();
}

/*
# Solve, marks the nodes in a vector as path by traversing through a saved
# path stack datastructur from the same maze generated latest time.
# @returns two dimensional vector of type node.
*/
std::vector<std::vector<CMazeGenerator::node>> CMazeGenerator::Solve(){
    while(!pathStack.empty()){
        pos pathNode = pathStack.top();
        nodesContainer[pathNode.row][pathNode.col].is_path = true;
        pathStack.pop();
    }
    return Presentation();
}

/*
# GetMaze, loops through a two dimensional vector of type node and prints the
# display attribute of each node.
# @param "vectorToPrint", two dimensional vector of type node.
*/
void CMazeGenerator::PrintMaze(std::vector<std::vector<CMazeGenerator::node>> vectorToPrint){
    for(auto eachRow : vectorToPrint){
        for(auto eachCol : eachRow){
            std::cout << eachCol.display;
        }
        std::cout << std::endl;
    }
}