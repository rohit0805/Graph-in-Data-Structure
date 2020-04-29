#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
}
int cycleloop(vector<int> adj[],bool visited[],bool stack[],int i){
	visited[i]=true;
	stack[i]=true;
	for(auto x:adj[i]){
		if(visited[x]==false){
			if(cycleloop(adj,visited,stack,x))
				return 1;
		}
		else if(stack[x]==true){
			return 1;
		}
	}
	stack[i]=false;
	return 0;
}

int detectcycle(vector<int> adj[],int V){
	bool visited[V+1],stack[V+1];
	for(int i=0;i<=V;i++){
		visited[i]=stack[i]=false;
	}
	for(int i=0;i<=V;i++){
		if(cycleloop(adj,visited,stack,i))
			return 1;
	}
	return 0;
}

int main(){
	int V=6;
	vector<int> adj[V+1];
	addedge(adj,0,1);
	addedge(adj,1,2);
	addedge(adj,2,3);
	addedge(adj,3,4);
	addedge(adj,4,5);
	addedge(adj,2,5);
	//addedge(adj,5,3);
	if(detectcycle(adj,V))
		cout<<"Cycle detected"<<endl;
	else
		cout<<"Cycle not detected"<<endl;
	return 0;
}