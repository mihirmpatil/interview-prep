#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Vertex {
	public:
		int id;

		Vertex() {}
		Vertex(int x) {
			id = x;
		}

		bool operator==(const Vertex& rhs) const {
			return id == rhs.id;
		}
		
		bool operator<(const Vertex& rhs) const {
			return id < rhs.id;
		}
};


class Graph {
	private:
		// adjacency lists for representation
		map<Vertex, vector<Vertex> > fwd_edges;
		map<Vertex, vector<Vertex> > back_edges;

	public:
		void addVertex(Vertex id);
		void addEdge(Vertex a, Vertex b);
		bool isEmpty();
		Vertex getARootNode();
		void deleteRootNode(Vertex a);
		void display();
};

void Graph::addVertex(Vertex id) {
	vector<Vertex> temp;
	fwd_edges.insert(make_pair(id, temp));
	back_edges.insert(make_pair(id, temp));
}

// Add edge from Vertex a to Vertex b
// Assumes that both vertices exist in the graph
void Graph::addEdge(Vertex a, Vertex b) {
	vector<Vertex> temp = fwd_edges[a];
	temp.push_back(b);
	fwd_edges[a] = temp;
	back_edges[b].push_back(a);
}

bool Graph::isEmpty() {
	return fwd_edges.empty() && back_edges.empty();
}

void Graph::display() {
	map< Vertex, vector<Vertex> >::iterator mit;
	vector<Vertex>::iterator vit;
	
	cout << endl << "Forward edges" << endl;
	for (mit = fwd_edges.begin(); mit != fwd_edges.end(); mit++) {
		cout << (mit->first).id << " -> ";
		for (vit = (mit->second).begin(); vit != (mit->second).end(); vit++) {
			cout << vit->id << ", ";
		}
		cout << endl;
	}

	cout << endl << "Backward edges" << endl;	
	for (mit = back_edges.begin(); mit != back_edges.end(); mit++) {
		cout << (mit->first).id << " -> ";
		for (vit = (mit->second).begin(); vit != (mit->second).end(); vit++) {
			cout << vit->id << ", ";
		}
		cout << endl;
	}
}

Vertex Graph::getARootNode() {
	Vertex result(-1);
	map< Vertex, vector<Vertex> >::iterator mit;
	for (mit = back_edges.begin(); mit != back_edges.end(); mit++) {
		if (mit->second.empty()) {
			result = mit->first.id;
			break;
		}
	}
	return result;
}

void Graph::deleteRootNode(Vertex a) {
	vector<Vertex> edges = fwd_edges[a];
	vector<Vertex>::iterator vit;
	vector<Vertex> temp;
	for (vit = edges.begin(); vit != edges.end(); vit++) {
		temp = back_edges[*vit];
		temp.erase(remove(temp.begin(), temp.end(), a), temp.end());
		back_edges[*vit] = temp;
	}
	fwd_edges.erase(a);
	back_edges.erase(a);
}

void topological_sort(Graph graph) {
	Vertex val(-1);
	while (!graph.isEmpty()) {
		val = graph.getARootNode();
		cout << val.id << " ";
		graph.deleteRootNode(val);
	}
	cout << endl;
}

int main() {
	
	Graph graph;
	
	Vertex a(0);
	Vertex b(1);
	Vertex c(2);
	Vertex d(3);
	Vertex e(4);
	Vertex f(5);
	
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
	cout << endl << "Topological sorting" << endl;
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
