#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
/*
class Vertex {
	public:
		int id;

		Vertex(int x) {
			id = x;
		}

		bool operator==(const Vertex& rhs) {
			return this->id == rhs.id;
		}
};
*/

class Graph {
	private:
		// adjacency lists for representation
		unordered_map<int, vector<int>> fwd_edges;
		unordered_map<int, vector<int>> back_edges;

	public:
		void addVertex(int id);
		void addEdge(int a, int b);
		bool isEmpty();
		int getARootNode();
		void deleteRootNode(int a);
		void display();
};

void Graph::addVertex(int id) {
	vector<int> temp;
	fwd_edges.insert(make_pair(id, temp));
	back_edges.insert(make_pair(id, temp));
}

// Add edge from Vertex a to Vertex b
// Assumes that both vertices exist in the graph
void Graph::addEdge(int a, int b) {
	vector<int> temp = fwd_edges[a];
	temp.push_back(b);
	fwd_edges[a] = temp;
	back_edges[b].push_back(a);
}

bool Graph::isEmpty() {
	return fwd_edges.empty() && back_edges.empty();
}

void Graph::display() {
	unordered_map< int, vector<int> >::iterator mit;
	vector<int>::iterator vit;
	
	cout << endl << "Forward edges" << endl;
	for (mit = fwd_edges.begin(); mit != fwd_edges.end(); mit++) {
		cout << (mit->first)/*.id*/ << " -> ";
		for (vit = (mit->second).begin(); vit != (mit->second).end(); vit++) {
			cout << *vit/*->id*/ << ", ";
		}
		cout << endl;
	}
	cout << endl << "Backward edges" << endl;	
	for (mit = back_edges.begin(); mit != back_edges.end(); mit++) {
		cout << (mit->first)/*.id*/ << " -> ";
		for (vit = (mit->second).begin(); vit != (mit->second).end(); vit++) {
			cout << *vit/*->id*/ << ", ";
		}
		cout << endl;
	}
}

int Graph::getARootNode() {
	int result = -1;
	unordered_map< int, vector<int> >::iterator mit;
	for (mit = back_edges.begin(); mit != back_edges.end(); mit++) {
		if (mit->second.empty()) {
			result = mit->first;
			break;
		}
	}
	return result;
}

void Graph::deleteRootNode(int id) {
	vector<int> edges = fwd_edges[id];
	vector<int>::iterator vit;
	vector<int> temp;
	for (vit = edges.begin(); vit != edges.end(); vit++) {
		temp = back_edges[*vit];
		temp.erase(remove(temp.begin(), temp.end(), id), temp.end());
		back_edges[*vit] = temp;
	}
	fwd_edges.erase(id);
	back_edges.erase(id);
}

void topological_sort(Graph graph) {
	int val;
	while (!graph.isEmpty()) {
		val = graph.getARootNode();
		cout << val << " ";
		graph.deleteRootNode(val);
	}
	cout << endl;
}

int main() {
	
	Graph graph;
	cout << graph.isEmpty() << endl;
	/*
	Vertex a(0);
	Vertex b(1);
	Vertex c(2);
	Vertex d(3);
	Vertex e(4);
	Vertex f(5);
	*/
	int a=0, b=1, c=2, d=3, e=4, f=5;

	graph.addVertex(a);
	graph.addVertex(b);
	graph.addVertex(c);
	graph.addVertex(d);
	graph.addVertex(e);
	graph.addVertex(f);

	graph.addEdge(a, b);
	graph.addEdge(a, c);
	graph.addEdge(b, f);
	graph.addEdge(c, d);
	graph.addEdge(c, e);
	graph.addEdge(d, e);
	graph.addEdge(d, f);
	graph.addEdge(e, f);
	
	graph.addEdge(c, b);

	graph.display();
	topological_sort(graph);
	
	/*
	int root = graph.getARootNode();
	cout << "Root node " << root << endl;
	graph.deleteRootNode(root);
	graph.display();
	root = graph.getARootNode();
	cout << "Root node " << root << endl;
*/
	return 0;
}
