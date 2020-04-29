#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int search(vector<int> adj[],bool visited[],int i,int parent){
	visited[i]=true;
	for(auto x:adj[i]){
		if(visited[x]==false){
			if(search(adj,visited,x,i))	
				return 1;
		}
		else if(x!=parent){
			return 1;
		}
	}
	return 0;
}
int detectcycle(vector<int>adj[],int V){
	int i;
	bool visited[V+1];
	for(i=1;i<=V;i++){
		visited[i]=false;
	}
	for(i=1;i<=V;i++){
		if(visited[i]==false){
			if(search(adj,visited,i,-1))
				return 1;
		}
	}
	return 0;
}
int main(){
	int V=6;
	vector<int> adj[V+1];
	addedge(adj,1,2);
	addedge(adj,1,3);
	addedge(adj,2,4);
	addedge(adj,2,5);
	addedge(adj,3,4);
	if(detectcycle(adj,V)){
		cout<<"Cycle detected"<<endl;
	}
	else{
		cout<<"Cycle not detected"<<endl;
	}
	return 0;
}