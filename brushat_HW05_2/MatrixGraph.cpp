/*****
 * Author   : brushat
 * Date     : 2012-11-30
 * Sources  : All code is original
 * Purpose  : This .cpp file is to implement the MatrixGraph data structure required for Part 2 of HW05
 * Note     : 
 */

#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes){
	// Read number of vertices and number of edges
	num_edges = 0;
	// create m*m vector matrix full of zeroes (AKA 'M')
	// loop through num nodes
	//
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

