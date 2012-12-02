/*****
 * Author   : brushat
 * Date     : 2012-12-01
 * Sources  : Adam Brush
 * Purpose  : A set of methods to solve the traveling sales person problem with brute force algorithm
 * Note     : Some of this code has come from lecture notes given by Professor Bo Brinkman
 */

#include "GraphAlgs.h"

using namespace std;

double bestDist = 0;
vector<NodeID> bestTour;
Graph* graph;
int arr[];

void swap(int* start, int* i){
	int* temp = start;
	start = i;
	i = temp;
}


void tour(int* arr, int n, int start){
	double dist = 0;
	if(n - start == 1){
		// Sum up the length of the permutation
		for(int i = 0; i < (n-1); i++){
			dist += graph->weight(arr[i], arr[i+1]);
		}
		// See if it is smaller than the best seen
	}
	else{
		//swap(start, i);
		//tour(arr, n, start+1) // this must be non-destructive
		//swap(start,i)
	}
}

std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
	graph = G;
	arr[graph->size()];
	
	for(int i = 0; i < graph->size(); i++){
		arr[i] = i;
	}
	tour(arr, graph->size(), 0);
}
