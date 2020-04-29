#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void BFS(vector<int> adj[],int V){
	int s=1;
	queue<int>q;
	q.push(s);
	bool visited[V+1];
	for(int i=1;i<=V;i++){
		visited[i]=false;
	}
	visited[s]=true;
	while(!q.empty()){
		int root=q.front();
		q.pop();
		cout<<root<<" ";
		for(auto x:adj[root]){
			if(visited[x]==false){
				q.push(x);
				visited[x]=true;	
			}
		}
	}
}
void dfsloop(vector<int> adj[],bool visited[],int i){
	visited[i]=true;
	cout<<i<<" ";
	for(auto x:adj[i])
	{
		if(visited[x]==false){
			dfsloop(adj,visited,x);
		}
	}
}

void DFS(vector<int> adj[],int V){
	bool visited[V+1];
	for(int i=1;i<=V;i++){
		visited[i]=false;
	}
	for(int i=1;i<=V;i++){
		if(visited[i]==false){
			dfsloop(adj,visited,i);
		}
	}
}

int main(){
	int V=6;
	vector<int> adj[V+1];
	addedge(adj,1,2);
	addedge(adj,1,3);
	addedge(adj,2,4);
	addedge(adj,2,5);
	addedge(adj,3,5);
	addedge(adj,4,5);
	addedge(adj,4,6);
	addedge(adj,5,6);
	cout<<"BFS of a graph: ";
	BFS(adj,V);
	cout<<"\nDFS of a graph: ";
	DFS(adj,V);
	return 0;
}