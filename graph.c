#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<stdint.h>
#include "graph.h"


Graph  graph_new(uint32_t  size){  //initialize graph
    Graph g;
    g.size=size;  //size represents total number of nodes in the graph
    g.neighbours =(Node**)malloc (size * sizeof(Node*));    //RHS creates an !D array to store the node address.and neighbours store the address of the table

    for (int i=0; i<size;;i++){
        g.neighbours[i]=NULL;  //table are initialized to null
    }
    return g;
}


static Node*  _make_node_(int32_t data){  //creation of a node
Node *node=(Node*) malloc(sizeof(Node));
node->node_id=data;
node->cost=0;
node->next=NULL;

return node;
}

static Node*  _get_neighbour_id(int32_t  node){
int32_t  neighbour_id;
printf("Enter neighbour for %d,No neighbour enter 9999 \n ",node);
scanf("%d",&neighbour_id);

return neighbour_id;
}

/*get edge cost*/
static int32_t _get_neighbour_cost(int32_t node){
int32_t  edge_cost;
printf("Enter the edge cost %d.\n",node);
scanf("%d",&edge_cost);
return edge_cost;
}


Graph* graph_adjacency_list(Graph *g){

int32_t i,neighbour_id;
uint32_t  edge_cost;
Node *vertex,*lastNode;

for(i=0; i<g->size;++i){
    g->neighbours[i]=_make_node_(i);  //LHS neighburs(i) stores the address of the node
    neighbour_id=_get_neihbour_id_(i);  //RHS gives the neighbours of the node i.if there are 10 nodes there we need to call the function 10 times.

    while(neighbour_id!=9999){
        vertex=_make_node_(neighbour_id);  //create a node for the neighbour id
        edge_cost=_getneighbour_cost(neighbour_id);
        vertex->cost=edge_cost;

        if(g->neighbours[i]->next==NULL){
          g->neighbours[i]->next=vertex;

    }
    else{
        lastNode->next =vertex;
    }
    lastNode=vertex;
    neighbour_id=_get_neighbour_id(i);

}

}
return g;
}
