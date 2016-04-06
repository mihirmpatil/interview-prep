#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Class to store information at the vertices of the graph.
class Vertex {
	public:
		int id;

		Vertex() {}
		Vertex(int x) {
			id = x;
		}

		// These overloaded operators are required so that a Vertex object can be used as a key in std::map
		bool operator==(const Vertex& rhs) const {
			return id == rhs.id;
		}
		
		bool operator<(const Vertex& rhs) const {
			return id < rhs.id;
		}
};


// This is the graph class
class Graph {
	private:
		// The directed graph is represented using two adjacency lists
		//
		// This map stores the outgoing edges of each vertex
		map<Vertex, vector<Vertex> > fwd_edges;
		// This map stores the incoming edges of each vertex
		map<Vertex, vector<Vertex> > back_edges;

	public:
		void addVertex(Vertex id);
		void addEdge(Vertex a, Vertex b);
		bool isEmpty();
		Vertex getARootNode();
		void deleteRootNode(Vertex a);
		void display();
};


// Add a new vertex to the graph
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


// Utility function that displays contents of both maps
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

// Returns the first root node (node with no incoming edges) from the graph or -1 if none is found
Vertex Graph::getARootNode() {
	Vertex result(-1);
	map< Vertex, vector<Vertex> >::iterator mit;

	// Use the back_edges map for quicker lookup of root node
	for (mit = back_edges.begin(); mit != back_edges.end(); mit++) {
		if (mit->second.empty()) {
			result = mit->first;
			break;
		}
	}
	return result;
}

// Deletes a root node and its outgoing edges from the graph
void Graph::deleteRootNode(Vertex a) {
	// Get outgoing edges
	vector<Vertex> edges = fwd_edges[a];
	vector<Vertex>::iterator vit;
	vector<Vertex> temp;
	// Remove incoming edges from back_edges map
	for (vit = edges.begin(); vit != edges.end(); vit++) {
		temp = back_edges[*vit];
		// erase-remove idiom
		temp.erase(remove(temp.begin(), temp.end(), a), temp.end());
		back_edges[*vit] = temp;
	}
	// Remove the vertex from both
	fwd_edges.erase(a);
	back_edges.erase(a);
}

// Print the vertices in sorted order by topological sort
// Assumes that there are no cycles in the graph
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
	
	// Some testing code below
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
