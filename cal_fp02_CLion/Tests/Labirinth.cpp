/*
 * labirinth.cpp
 */

#include "Labirinth.h"

#include <iostream>
using namespace std;



Labirinth::Labirinth(int values[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			labirinth[i][j] = values[i][j];
}


void Labirinth::initializeVisited()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			visited[i][j] = false;
}




void  Labirinth::printLabirinth()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			cout << labirinth[i][j] << " ";

		cout << endl;
	}
}


bool Labirinth::findGoal(int x, int y)
{
    initializeVisited();
    searchGoal(x,y);
	return foundSol;
}

void Labirinth::searchGoal(int x, int y){
    if (foundSol){
        return;
    }
    if (visited[x][y]){
        return;
    } else
        visited[x][y] = true;

    // Out of Bounds
    if(x<0 || x>=10 || y<0 || y>=10) {
        return;
    }

    //Wall
    if (labirinth[x][y] == 0){
        return;
    }

    //Found exit
    if (labirinth[x][y] == 2){
        foundSol = true;
        return;
    }

    searchGoal(x+1,y);  //Right
    searchGoal(x-1,y);  //Left
    searchGoal(x,y+1);  //Up
    searchGoal(x,y-1);  //Down
}



/*
 *
 * 1b) Eficiência temporal: n^2
 */


