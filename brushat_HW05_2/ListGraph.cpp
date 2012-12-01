/*****
 * Author   : brushat
 * Date     : 2012-11-30
 * Sources  : All code is original
 * Purpose  : This .cpp file is to implement the ListGraph data structure required for Part 3 of HW05
 * Note     : 
 */

#include "ListGraph.h"

/**
* Create the the ListGraph structure based on the number of nodes in the graph
* 
*/
ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes);
	num_edges = 0;
	
	// Needed some help on how a listgraph actual works
	// http://www.phys.psu.edu/~ralbert/phys597_09-fall/c07_graph_soft_handout.pdf
	// Also talked to Bo to make sure I was on the right track
	for(int i = 0; i < numNodes; i++){
		edgeList.push_back(EList(NULL));
	}
}

ListGraph::~ListGraph(){
	// Didn't create it with 'new' so we shouldn't put anything here
}

void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	// Checks we need to do...
	// Check: u and v are in the right range... you will always need to check this with each node
	if((0 <= u < edgeList.size()) && (0 <= v < edgeList.size())){
		bool duplicate = false;
		// Check: we are passing in a weight > 0
		if(weight > 0){
			// This code is from the lecture that we went over ListGraph implementation
			EList::const_iterator it;
			// for each node in u's node list...
			for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
				// get the nw pair
				NWPair tPair = (*it);
				if(tPair.first == v){ // not entirely sure that I need to check the weight also, I don't think I do
					// if the nw pair is equal to the edge and node we are trying to add then it is a duplicate
					// End code from Bo's Lecture
					duplicate = true;
				}
			}	

			// EDIT: This section needs to go outside the for loop
			// if it's not a duplicate in the list then add it to the list (for both nodes)
			if(duplicate == false){
				NWPair NWv = NWPair(v,weight);
				NWPair NWu = NWPair(u,weight);
				// The graph is still non-directional so...
				// "u is 100 from v" also means "v is 100 from u"
				edgeList[u].push_back(NWv);
				edgeList[v].push_back(NWu);
				num_edges++;
			}
			
		}
	}
}

EdgeWeight ListGraph::weight(NodeID u, NodeID v) const{
	if((0 <= u < edgeList.size()) && (0 <= v < edgeList.size())){
		EList::const_iterator it;
		// Same code from class that I used in addEdge
		for(it = edgeList[u].begin(); it != edgeList[u].end(); it++){
			NWPair tPair = (*it);
			if(tPair.first == v){
				return tPair.second;
			}
		}
	}
	return 0;
}

/**
* Returns a list of all of the adjacent nodes/edgeweights to the node u
* Credit to Dr. Brinkman for some of this code which he gave out in lecture
*/
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	if(0 <= u < edgeList.size()){
		// From ListGraph.cpp lecture notes
		std::list<NWPair> ret = edgeList[u];
		return ret;
	}
}

/**
* Returns the number of adjacent nodes (the degree) of the node u
* 
*/
unsigned ListGraph::degree(NodeID u) const{
	return getAdj(u).size();
}

/**
* Returns the size of the graph
* 
*/
unsigned ListGraph::size() const{
	int size = edgeList.size();
	return size;
}

/**
* Returns the number of edges in the graph
* An edge is only an edge if the weight is greater than 0
*/
unsigned ListGraph::numEdges() const{
	return num_edges;
}


