/*****
 * Author   : brushat
 * Date     : 2012-11-30
 * Sources  : All code is original
 * Purpose  : This .cpp file is to implement the ListGraph data structure required for Part 3 of HW05
 * Note     : 
 */

#include "ListGraph.h"

ListGraph::ListGraph(int numNodes){

}

ListGraph::~ListGraph(){

}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){

}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	return 0;
}

/**
* Returns a list of all of the adjacent nodes/edgeweights to the node u
* Credit to Dr. Brinkman for some of this code which he gave out in lecture
*/
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	std::list<NWPair> ret;

	return ret;
}

unsigned ListGraph::degree(NodeID u) const{
	return 0;
}

unsigned ListGraph::size() const{
	return edgeList.size();
}

unsigned ListGraph::numEdges() const{
	return num_edges;
}


