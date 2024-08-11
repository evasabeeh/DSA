#inlcude<bits/stdc++.h>
using namespace std; 
struct adjNode{                             //adjacency list
    int val;
    adjNode* next;
};
struct graphEdge{                           //store edges
    int start, int end;
};
class graph{
    graph(graphEdge edges[], int n){

    }
    adjNode* getAdjacentListNode(int value, adjNode* head){           //insert node into adjacent list
        adjNode* newNode=new adjNode();
        adjNode->val=value;
        adjNode->next=head;
        return newNode;
    }
};

int main(){
    graphEdge edges[]={
        {0, 1},
        {0, 2},
        {1, 4},
        {2, 3},
        {3, 1},
        {4, 3}
    };
    int n=6;                          //no. of vertices
    return 0;
}