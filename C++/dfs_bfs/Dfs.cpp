#include <iostream>

typedef struct Node
{
	int			node;
	struct Node	*next;
}				t_node;

class Graph
{
  private:
	int num_node;
	Node **nodes;
	bool *visited;

  public:
	Graph(int verices);
	~Graph();
	Graph(const Graph &other);
	Graph &operator=(const Graph &other);
	Node *getNode();
	void setNode(int vertices);
	Node *create_node(int node);
	void printf_graph();
	void add_node_to_graph(int src, int dest);
	void spanning_tree_with_dfs(int start);
	void dfs(int vertex);
	void restVisited();
	void spanning_tree_with_bfs(int start);
	void dfsUtils(int start, bool *visited, Graph *tree);
	void spanning_tree_with_dfs_stack(int start);
};

void Graph::spanning_tree_with_dfs_stack(int start)
{
	int visited[num_node];
	int	stack_route[num_node];
	int	top = -1;
	Graph *tree = new Graph(num_node);

	stack_route[++top] = start; //1. first pop is start
	visited[start] = true;

	while (top >= 0) // 2. until the stack route is not empty
	{
		int u = stack_route[top--]; //3. pop to check there is adjancy?
		Node *temp = nodes[u]; // 4. refere to poped element from stack route
		while (temp)
		{
			int v = temp->node; // 5. check if not visired add to addjances list for top elemnt from stack
			if (!visited[v])
			{
				visited[v] = true;
				tree->add_node_to_graph(u, v);
				stack_route[top++] = v; // after add and visited add to stack, to avoid miss the route in graph
			}
			temp = temp->next;
		}
		tree->printf_graph();		
	}
	
}

void Graph::restVisited()
{
	for (size_t i = 0; i < num_node; i++)
	{
		visited[i] = 0;
	}
}

Node *Graph::create_node(int val)
{
	Node	*node;

	node = new Node;
	node->node = val;
	node->next = nullptr;
	return (node);
}
Graph::Graph(const Graph &other)
{
	*this = other;
}

Graph &Graph::operator=(const Graph &other)
{
	for (size_t i = 0; i < this->num_node; i++)
	{
		this->nodes[i] = other.nodes[i];
	}
	return (*this);
}

Graph::Graph(int verices)
{
	num_node = verices;
	nodes = new Node *[verices]; // allocare dynamiclly num of node
	for (size_t i = 0; i < verices; i++)
	{
		nodes[i] = nullptr;
	}
}

Graph::~Graph()
{
	for (size_t i = 0; i < num_node; i++)
	{
		delete this->nodes[i];
	}
	this->nodes;
}

void Graph::add_node_to_graph(int src, int dest)
{
	Node	*newNode;

	newNode = create_node(dest);
	newNode->next = nodes[src];
	nodes[src] = newNode;
	newNode = create_node(src); // undirect without ->
	newNode->next = nodes[dest];
	nodes[dest] = newNode;
}

void Graph::printf_graph()
{
	Node	*temp;

	for (size_t i = 0; i < this->num_node; i++)
	{
		temp = nodes[i];
		std::cout << "Vertex " << i << ": ";
		while (temp)
		{
			std::cout << temp->node << " -> ";
			temp = temp->next;
		}
		std::cout << "NULL\n";
	}
}
void Graph::dfsUtils(int start, bool *visited, Graph *tree)
{
	Node	*temp;
	int		v;

	visited[start] = true;
	temp = nodes[start];
	while (temp != nullptr)
	{
		v = temp->node;
		if (!visited[v])
		{
			tree->add_node_to_graph(start, v);
			dfsUtils(v, visited, tree); // nested, go in deep
		}
		temp = temp->next;
	}
}
/* span tree with dfs solution */
void Graph::spanning_tree_with_dfs(int start)
{
	bool	*visited;
	Graph	*tree;

	visited = new bool(num_node);
	for (size_t i = 0; i < num_node; i++)
	{
		visited[i] = false;
	}
	tree = new Graph(num_node);
	dfsUtils(start, visited, tree);
	tree->printf_graph();
	std::cout << std::endl;
}

void Graph::spanning_tree_with_bfs(int start)
{
	int		bfs_visited[num_node] = {false};
	Graph	*tree;
	int		explore;
	int		poineer;
	int		Q_traverse[num_node];
	int		neighbor;

	/* phsoudo code for spanning tree */
	tree = new Graph(num_node); // allocate node in heap for tree;
	explore = 0;
	poineer = 0;
	bfs_visited[start] = true;
	Q_traverse[poineer++] = start;
	for (size_t j = 0; j < num_node; j++)
	{
		int current = Q_traverse[explore++]; // get one node from q to explore
		Node *temp = nodes[current];         //
		while (temp)
		{
			neighbor = temp->node;
			if (!bfs_visited[neighbor])
			{
				bfs_visited[neighbor] = true;              
					// check it has already visited?
				Q_traverse[poineer++] = neighbor;          
					// add at the and of Q
				tree->add_node_to_graph(current, neighbor);
					// expan the connected nodes
			}
			temp = temp->next;
		}
	}
	tree->printf_graph();
}

void Graph::dfs(int vertex)
{
	Node	*temp;
	int		isConnected;

	visited[vertex] = true;
	std::cout << vertex << " ";
	temp = nodes[vertex];
	while (temp)
	{
		isConnected = temp->node;
		if (!visited[isConnected])
			dfs(isConnected);
		temp = temp->next;
	}
}

int	main(void)
{
	Graph graph(5);
	graph.add_node_to_graph(0, 1);
	graph.add_node_to_graph(0, 3);
	graph.add_node_to_graph(1, 4);
	graph.add_node_to_graph(1, 2);
	graph.add_node_to_graph(2, 0);
	graph.printf_graph();
	std::cout << "traverse dfs: \n";
	// graph.dfs_span_tree(0);
	graph.dfs(0);
	std::cout << std::endl;

	std::cout << "spanning tree with bfs\n";
	graph.spanning_tree_with_bfs(0);
	std::cout << std::endl;
	return (0);
}