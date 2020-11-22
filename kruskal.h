#include <iostream>
#include <algorithm>
using namespace std;
/**
9 14
1 2 4
1 8 9
2 3 9
2 8 11
3 4 7
3 9 2
3 6 4
4 5 10
4 6 15
5 6 11
6 7 2
7 8 1
7 9 6
8 9 7
*/
struct Edges
{
	int source; //id repartidor
	int dest; // id pedido
	int weight; //peso
};

bool compare(Edges e1, Edges e2)
{
	return e1.weight < e2.weight;
}

int findParent(int v, int parent[])
{
	if (parent[v] == v)
		return v;
	return findParent(parent[v], parent);
}

int main()
{
	int V;
	cin >> V; //No. of vertices //Nodos lista circular ciclofor 
	int n;
	cin >> n; //No. of Edges  //RANDOM 
	int src, dst, wt;
	Edges E[n]; //Vertice de una funcion //Estructura estatica

	for (int i = 0; i < n/*RANDOM POR RESOLVER*/; ++i)
	{
		cin >> src; //random
		cin >> dst; //random
		cin >> wt; //randon
		E[i].source = src;
		E[i].dest = dst;
		E[i].weight = wt;
	}

	sort(E, E + n, compare); //Metodo ordenamiento basado en el peso
	// Sort Edges based on their weights

	int parent[V]; //array

	for (int i = 0; i < V /**Numero de nodos*/; ++i)
	{
		parent[i] = i;
	}

	int i = 0;
	int count = 0;
	Edges currentEdge[V - 1]; // Stores MST //estructura estaticas

	while (count < V - 1)
	{ // Runs till V-1 times

		int sourceParent = findParent(E[i].source, parent);
		int destParent = findParent(E[i].dest, parent);

		if (sourceParent != destParent)
		{ // checks if no cycle
			currentEdge[count].source = E[i].source;
			currentEdge[count].dest = E[i].dest;
			currentEdge[count].weight = E[i].weight;
			count++;
			parent[sourceParent] = E[i].dest;
		}

		i++;
	}
	cout << "\nMinimum spanning Tree:\n";
	for (int i = 0; i < V - 1; ++i)
	{
		cout << currentEdge[i].source << " " << currentEdge[i].dest << " ";
		cout << currentEdge[i].weight << endl;
	}
	return 0;
}
