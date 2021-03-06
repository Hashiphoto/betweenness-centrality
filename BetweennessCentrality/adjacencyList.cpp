#include <iostream>

using namespace std;

/*
 * Adjacency List Node
 */
struct AdjListNode
{
	int dest;
	struct AdjListNode* next;
};

/*
 * Adjacency List
 */
struct AdjList
{
	struct AdjListNode *head;
};

/*
 * Class Graph
 */
class Graph
{
private:
	int V;
	struct AdjList* array;
public:
	Graph(int V)
	{
		this->V = V;
		array = new AdjList[V];
		for (int i = 0; i < V; ++i)
			array[i].head = nullptr;
	}
	/*
	 * Creating New Adjacency List Node
	 */
	AdjListNode* newAdjListNode(int dest)
	{
		AdjListNode* newNode = new AdjListNode;
		newNode->dest = dest;
		newNode->next = nullptr;
		return newNode;
	}
	/*
	 * Adding Edge to Graph
	 */
	void addEdge(int src, int dest)
	{
		AdjListNode* newNode = newAdjListNode(dest);
		newNode->next = array[src].head;
		array[src].head = newNode;
		newNode = newAdjListNode(src);
		newNode->next = array[dest].head;
		array[dest].head = newNode;
	}
	/*
	 * Print the graph
	 */
	void printGraph()
	{
		int v;
		for (v = 0; v < V; ++v)
		{
			AdjListNode* pCrawl = array[v].head;
			cout << "\n Adjacency list of vertex " << v << "\n head ";
			while (pCrawl)
			{
				cout << "-> " << pCrawl->dest;
				pCrawl = pCrawl->next;
			}
			cout << endl;
		}
	}
};