/*****
 * Author   : brushat
 * Date     : 2012-11-30
 * Sources  : All code is original
 * Purpose  : This .cpp file is to implement the MatrixGraph data structure required for Part 2 of HW05
 * Note     : 
 */

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){
	// http://au.answers.yahoo.com/question/index?qid=20081125114819AA8swQ5
	// Read number of vertices and number of edges
	num_edges = 0;
	// create m*n vector matrix full of zeroes (AKA 'M')
	M.resize(num_nodes);
	// it's a vector of vectors so...
	// loop through num nodes
	for(int m = 0; m < M.size(); m++){
		// for each node loop through num nodes again and put a 0 at [m][n]
		for(int n = 0; n < M.size(); n++){
			M.at(m).push_back(0);
		}
		// results in...
		// 0 0 0 0 0
		// 0 0 0 0 0
		// 0 0 0 0 0
		// 0 0 0 0 0
		// 0 0 0 0 0
		// rows and columns are determined by the number of nodes
		// since edges go both directions
		// "x is A from y" also means "y is A from x"
	}
	// edgeList.resize(num_nodes)
	

	
}

MatrixGraph::~MatrixGraph(){

}

void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

}

EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	return 0;
}

/**
* Returns a list of all of the adjacent nodes/edgeweights to the node u
* Credit to Dr. Brinkman for some of this code which he gave out in lecture
*/
std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	std::list<NWPair> ret;

	return ret;
}

unsigned MatrixGraph::degree(NodeID u) const{
	return 0;
}

unsigned MatrixGraph::size() const{
	return M.size();
}

unsigned MatrixGraph::numEdges() const{
	return num_edges;
}

