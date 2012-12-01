/*****
 * Author   : brushat
 * Date     : 2012-11-30
 * Sources  : All code is original
 * Purpose  : This .cpp file is to implement the MatrixGraph data structure required for Part 2 of HW05
 * Note     : 
 */

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){
	// Got some help here: http://au.answers.yahoo.com/question/index?qid=20081125114819AA8swQ5
	// Read number of vertices and number of edges
	num_edges = 0;
	// create m*n vector matrix full of zeroes (AKA 'M')
	M.resize(num_nodes);
	// it's a vector of vectors so...
	// loop through num nodes (n and m are equal to the number of nodes
	for(int m = 0; m < M.size(); m++){
		// for each node loop through num nodes again and put a 0 at [m][n]
		for(int n = 0; n < M.size(); n++){
			M.at(m).push_back(0);
		}
		// if num nodes = 5, results in...
		// http://www.personal.psu.edu/kes32/MichiganClasses/math217/Worksheets2/adjacency-Graphs.pdf
		// 0 0 0 0 0
		// 0 0 0 0 0
		// 0 0 0 0 0
		// 0 0 0 0 0
		// 0 0 0 0 0
		// rows and columns are determined by the number of nodes, but rows = cols ALWAYS
		
	}
	// edgeList.resize(num_nodes)
	

	
}

MatrixGraph::~MatrixGraph(){
	// Do mothiing here, M was not created with 'new' so it should not be deleted
}

/**
* Adds an edge between two nodes based on the weight of the edge
* Note: for the purpose of this program the EdgeWeight is the distance between starbucks locs
*/
void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	// Checks we need to do...
	// Check: u and v are in the right range... you will always need to check this with each node
	if((0 <= u < M.size()) && (0 <= v < M.size())){
		// Check: we are passing in a weight > 0
		if(weight > 0){
			// Check: u does not equal v
			if((u != v) && (v != u)){
				// Check: there is no weight already at that edge
				if((M.at(u).at(v) == 0) && (M.at(v).at(u) == 0)){
					// since edges go both directions in our problem
					// "x is 100 from y" also means "y is 100 from x"
					M.at(u).at(v) = weight; // Credit to Scott Vincent for showing me how to access M[u][v] for vector<vector>
					M.at(v).at(u) = weight;
					num_edges++;
				}
			}
		}
	}

}

/**
* Returns the weight of the edge between u and v
* It could be 0 if there is not edge between u and v
*/
EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	if((0 <= u < M.size()) && (0 <= v < M.size())){
		// Return the weight at the intersection of u and v in the matrix
		return M.at(u).at(v);
	}
	return 0;
}

/**
* Returns a list of all of the adjacent node/edgeweight pairs to the node u
* Credit to Dr. Brinkman for some of this code which he gave out in lecture
* also got some help via email
*/
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	if(0 <= u < M.size()){

		std::list<NWPair> ret;
		// This part is from Bo's lecture
		for(int m = 0; m < M.at(u).size(); m++){
			// new NodeID/EdgeWeight pair
			NWPair tPair = NWPair(m, M.at(u).at(m));
			// if the second value in the pair is 0 then we don't need it
			if(tPair.second == 0){
				// if it's 0 that means these nodes don't share an edge = they are NOT adjacent
			}
			else ret.push_back(tPair);
		}
		return ret;
	}
	
}

/**
* Returns the number of adjacent nodes (the degree) of the node u
* 
*/
unsigned MatrixGraph::degree(NodeID u) const{
	if(0 <= u < M.size()){
		// go to the vector at u and get the size of the adjacency list... the size is the number of adjacent nodes
		return getAdj(u).size();
	}
	else return 0;
}

/**
* Returns the size of the graph
* 
*/
unsigned MatrixGraph::size() const{
	return M.size();
}

/**
* Returns the number of edges in the graph
* An edge is only an edge if the weight is greater than 0
*/
unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

