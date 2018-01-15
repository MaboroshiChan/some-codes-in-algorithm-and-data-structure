#include<iostream>
#include<list>
#include<stack>
#include<map>
#include<queue>
using namespace std;
class graph {
	int V;
	list<int>* Adj;
public:
	graph(int V) : V(V), Adj(new list<int>[V]) {}
	void Addedge(int u, int v);
	void DSF(int initial_point);
	void BSF(int initial_point);
	bool if_is_connected(int , int );
	void outputadj(int );
	map<int, int>val_of_node;
};

class adjacentMatrix {
	
public:
	int V;
	int** matrix;
	adjacentMatrix(int v) :V(v){
		this->matrix = new int*[v];
		for (unsigned i = 0; i < v; i++) {
			matrix[i] = new int[v];
		}
	}
	void BFS(int);
	int dijsktra(int, int, map<int, int>&);
	void DFS(int);
	map<int, int> prev;
	adjacentMatrix prim(int);
	
};

void graph::Addedge(int u, int v)
{
	Adj[v].push_back(u);
	Adj[u].push_back(v);
	cout << "Added edge from " << v << " to " << u << endl;
}

bool graph::if_is_connected(int p1, int p2)
{
	list<int>::iterator i = Adj[p1].begin();
	while(i!=Adj[p1].end()){
		if (*i == p2) {
			return true;
		}
		else{

			i++;
		}
	}
	return false;
}

void graph::DSF(int initial_point)
{
	stack<int> stack;
	map<int, bool> visited;
	for (unsigned i = 0; i < V; i++) {
		visited[i] = false;
	}
	int curr = initial_point;
	stack.push(curr);
	visited[curr] = true;
	list<int>::iterator it;
	LOOP://break nested loops.
	while (!stack.empty()) {   
		for (it = Adj[curr].begin(); it != Adj[curr].end(); it++) {
			if (visited[*it] == false) {
				stack.push(*it);
				visited[*it] = true;
				curr = *it;
				goto LOOP;
			}
		}
		stack.pop();
		if (stack.empty()) { break; }
		curr = stack.top();
	}
}

void graph::BSF(int initial_point)
{
	queue<int> queue;
	map<int, bool> visited;
	for (unsigned i = 0; i < V; i++) {
		visited[i] = false;
	}
	int curr = initial_point;
	queue.push(curr);
	visited[curr] = true;
	list<int>::iterator it;
	while (!queue.empty())
	{
		for (it = Adj[curr].begin(); it != Adj[curr].end(); it++) {
			if (visited[*it] == false) {
				visited[*it] = true;
				queue.push(*it);
			}
		}
		curr = queue.front();
		queue.pop();
	}
}
void graph::outputadj(int p)
{
	list<int>::iterator i;
	for (i = Adj[p].begin(); i != Adj[p].end(); i++){
		cout << *i << " ";
	}
}
void adjacentMatrix::BFS(int initial_pt)
{
	int curr = initial_pt;
	map<int, bool> visited;
	for (unsigned i = 0; i < V; i++) {
		visited[i] = false;
	}
	queue<int> queue;
	queue.push(curr);
	visited[curr] = true;
	while (!queue.empty())
	{
		for (unsigned i = 0; i < V; i++) {
			if (matrix[curr][i] > 0 && visited[i] == false) {
				visited[i] == true;
				queue.push(i);
			}
		}
		curr = queue.front();
		queue.pop();
	}
}
int adjacentMatrix::dijsktra(int initial_pt, int target, map<int , int>&prev)//有问题
{
	int curr = initial_pt;
	map<int, int>min_len;
	for (unsigned i = 0; i < V; i++) {
		min_len[i] = _MAX_INT_DIG;
	}
	min_len[curr] = 0;
	map<int, bool> visited;
	for (unsigned i = 0; i < V; i++) {
		visited[i] = false;
	}
	queue<int> queue;
	queue.push(curr);
	while (!queue.empty())
	{
		for (unsigned i = 0; i < V; i++) {
			if (matrix[curr][i] > 0 && visited[i] == false) {
				min_len[i] = min(min_len[i], min_len[curr] + matrix[curr][i]);
				prev[i] = curr;
				queue.push(i);
				visited[curr] = true;
			}
		}
		curr = queue.front();
		queue.pop();
	}
	return min_len[target];
}
adjacentMatrix adjacentMatrix::prim(int initial)
{
	adjacentMatrix result(V);
	for (unsigned x = 0; x < V; x++) {
		for (unsigned y = 0; y < V; y++) {
			result.matrix[x][y] = 0;
		}
	}
	list<int> V_new;
	list<int> Vertices;
	for (unsigned i = 0; i < V; i++){
		Vertices.push_back(i);
	}
	V_new.push_back(initial);
	list<int>::iterator Vnew;
	list<int>::iterator Verti;
	for (Verti = Vertices.begin();  Verti != Vertices.end();  Verti++) {
		if (*Verti == initial) {
			Vertices.erase(Verti);
			break;
		}
	}
	int temp, X, Y;
	while (V_new.size() < V) {
		temp = 99;
		for (Vnew = V_new.begin(); Vnew != V_new.end(); Vnew++) {
			for (Verti = Vertices.begin(); Verti != Vertices.end(); Verti++) {
				if (temp > matrix[*Vnew][*Verti] && matrix[*Vnew][*Verti]!= 0) {
					temp = matrix[*Vnew][*Verti];
					X = *Vnew;
					Y = *Verti;
					
					cout << "min:"<< temp << endl;
				}
			}
		}

		result.matrix[X][Y] = temp;
		result.matrix[Y][X] = temp;

		V_new.push_back(Y);
		for (Verti = Vertices.begin(); Verti != Vertices.end(); Verti++) {
			if (*Verti == Y) {
				Vertices.erase(Verti);
				break;
			}
		}
	}
	return result;
}

int main()
{
	map<int, int>prev;
	int graph[9][9] = 
	{ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }};
	adjacentMatrix M(9);
	for (unsigned i = 0; i < 9; i++) {
		for (unsigned j = 0; j < 9; j++) {
			M.matrix[i][j] = graph[i][j];
		}
	}
	for (unsigned i = 0; i < 9; i++) {
		for (unsigned j = 0; j < 9; j++) {
			cout << M.matrix[i][j] << " ";
		}
		cout << endl;
	}
	
	
	adjacentMatrix N =M.prim(2);
	cout << endl;
	for (unsigned a = 0; a < 9; a++) {
		for (unsigned b = 0; b < 9; b++) {
			cout <<N.matrix[a][b] << " ";
		}
		cout << endl;
	}

	
}
