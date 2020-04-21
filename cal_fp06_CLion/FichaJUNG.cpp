#include <cstdio>
#include "graphviewer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
// TODO: Implement here exercise 1!
    GraphViewer *gv = new GraphViewer(600, 600, true);
    gv->setBackground("background.jpg");
    gv->createWindow(1920, 1080);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    gv->addNode(0);


    gv->addNode(1);

    gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
    gv->addEdge(1,0,1, EdgeType::DIRECTED);

    gv->removeNode(1);

    gv->addNode(2);
    gv->addEdge(2,0,2,EdgeType::UNDIRECTED);
    gv->setVertexLabel(2, "Isto e um no");

    gv->setEdgeLabel(2, "Isto e uma aresta");

    gv->setVertexColor(2, "green");

    gv->setEdgeColor(2, "yellow");

    gv->rearrange();
}

void exercicio2()
{
// TODO: Implement here exercise 2!
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("background.jpg");
    gv->createWindow(1920, 1080);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    gv->addNode(0,300,50);
    gv->addNode(1,318,58);
    gv->addNode(2,325,75);
    gv->addNode(3,318,93);
    gv->addNode(4,300,100);
    gv->addNode(5,282,93);
    gv->addNode(6,275,75);
    gv->addNode(7,282,58);
    gv->addNode(8,150,200);
    gv->addNode(9,300,200);
    gv->addNode(10,450,200);
    gv->addNode(11,300,400);
    gv->addNode(12,200,550);
    gv->addNode(13,400,550);

    gv->addEdge(0,0,1,EdgeType::UNDIRECTED);
    gv->addEdge(1,1,2,EdgeType::UNDIRECTED);
    gv->addEdge(2,2,3,EdgeType::UNDIRECTED);
    gv->addEdge(3,3,4,EdgeType::UNDIRECTED);
    gv->addEdge(4,4,5,EdgeType::UNDIRECTED);
    gv->addEdge(5,5,6,EdgeType::UNDIRECTED);
    gv->addEdge(6,6,7,EdgeType::UNDIRECTED);
    gv->addEdge(7,7,0,EdgeType::UNDIRECTED);
    gv->addEdge(8,4,9,EdgeType::UNDIRECTED);
    gv->addEdge(9,9,8,EdgeType::UNDIRECTED);
    gv->addEdge(10,9,10,EdgeType::UNDIRECTED);
    gv->addEdge(11,9,11,EdgeType::UNDIRECTED);
    gv->addEdge(12,11,12,EdgeType::UNDIRECTED);
    gv->addEdge(13,11,13,EdgeType::UNDIRECTED);

    //Animacao - alinea c)
    gv->rearrange();
    bool first = true;
    while(1)
    {
        Sleep(1);
        if (first)
        {
            gv->removeNode(12);
            gv->removeNode(13);
            first=false;
        }
        else
        {
            gv->removeNode(20);
            gv->removeNode(21);
        }
        gv->addNode(14,250,550);
        gv->addNode(15,350,550);
        gv->addEdge(14, 11, 14, EdgeType::UNDIRECTED);
        gv->addEdge(15, 11, 15, EdgeType::UNDIRECTED);
        gv->rearrange();
        Sleep(1000);
        gv->removeNode(14);
        gv->removeNode(15);
        gv->addNode(16,300,550);
        gv->addNode(17,300,550);
        gv->addEdge(16, 11, 16, EdgeType::UNDIRECTED);
        gv->addEdge(17, 11, 17, EdgeType::UNDIRECTED);
        gv->rearrange();
        Sleep(1000);
        gv->removeNode(16);
        gv->removeNode(17);
        gv->addNode(18,250,550);
        gv->addNode(19,350,550);
        gv->addEdge(18, 11, 18, EdgeType::UNDIRECTED);
        gv->addEdge(19, 11, 19, EdgeType::UNDIRECTED);
        gv->rearrange();
        Sleep(1000);
        gv->removeNode(18);
        gv->removeNode(19);
        gv->addNode(20,200,550);
        gv->addNode(21,400,550);
        gv->addEdge(20, 11, 20, EdgeType::UNDIRECTED);
        gv->addEdge(21, 11, 21, EdgeType::UNDIRECTED);
        gv->rearrange();
    }

}

vector<int> stringToVector(string str){
    string delimiter = ";";
    vector<string> data;
    vector<int> result;
    size_t pos = 0;
    string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        data.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    data.push_back(str);
    for (auto & i : data) {
        result.push_back(stoi(i));
    }

    return result;
}

void exercicio3()
{
// TODO: Implement here exercise 3!
    //Window and Graph setup
    GraphViewer *gv = new GraphViewer(600, 600, false);
    gv->setBackground("background.jpg");
    gv->createWindow(1920, 1080);
    gv->defineVertexColor("blue");
    gv->defineEdgeColor("black");

    //Node file read
    ifstream nodefile;
    string line;
    vector<int> current;
    nodefile.open("../nodes.txt");
    if (nodefile.is_open()) {
        while (!nodefile.eof()) {
            getline(nodefile, line);
            current = stringToVector(line);
            gv->addNode(current.at(0),current.at(1),current.at(2));
        }
    }
    nodefile.close();

    //Edge file read
    ifstream edgefile;
    edgefile.open("../edges.txt");
    if (edgefile.is_open()) {
        while (!edgefile.eof()) {
            getline(edgefile, line);
            current = stringToVector(line);
            gv->addEdge(current.at(0),current.at(1),current.at(2),EdgeType::UNDIRECTED);
        }
    }
    edgefile.close();
    gv->rearrange();
}

int main() {
    /*
     * Uncomment the line below to run Exercise 1
     */
    //exercicio1();

    /*
      * Uncomment the line below to run Exercise 2
      */
    //exercicio2();

    /*
      * Uncomment the line below to run Exercise 3
      */
	//
	exercicio3();

	getchar();
	return 0;
}
