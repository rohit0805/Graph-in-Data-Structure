#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void shortestpath(vector<int> adj[],int source,int dest,int V){
	int arr[V],i;
	bool visited[V];
	for(i=0;i<V;i++){
		arr[i]=INT_MAX;
		visited[i]=false;
	}
	queue<int>q;
	arr[source]=0;
	q.push(source);
	visited[source]=true;
	while(!q.empty()){
		int root=q.front();
		q.pop();
		for(auto x:adj[root]){
			if(visited[x]==false){
				if(arr[x]>arr[root]+1){
					visited[x]=true;
					q.push(x);
					arr[x]=arr[root]+1;
				}
			}
		}
	}
	for(i=0;i<V;i++){
		cout<<i<<" : "<<arr[i]<<endl;
	}
	cout<<"Shortest path from "<<source<<" to "<<dest<<" is "<<arr[dest];
}
int main(){
	int V=8;
	vector<int>adj[V];
	addedge(adj,0,1);
	addedge(adj,0,3);
	addedge(adj,1,2);
	addedge(adj,3,4);
	addedge(adj,3,7);
	addedge(adj,4,5);
	addedge(adj,4,6);
	addedge(adj,4,7);
	addedge(adj,5,6);
	addedge(adj,6,7);
	int source=0,dest=7;
	shortestpath(adj,source,dest,V);
	return 0;
}