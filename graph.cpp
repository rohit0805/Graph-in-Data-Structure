#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void printgraph(vector<int> adj[],int V){
	for(int v=0;v<V;v++){
		cout<<"\nAdjacency list of vertex "<<v<<" :"<<" head";
		for(auto x:adj[v]){
			cout<<"->"<<x;
		}
		cout<<endl;
	}
}

int main(){
	int V=5;
	vector<int> adj[V];
	addedge(adj,0,1);
	addedge(adj,0,4);
	addedge(adj,1,2);
	addedge(adj,1,3);
	addedge(adj,1,4);
	addedge(adj,2,3);
	addedge(adj,3,4);
	printgraph(adj,V);
	return 0;
}