#include<bits/stdc++.h>
using namespace std;
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS(vector<int> adj[],int V){
	bool visited[V+1];
	int i;
	for(i=0;i<=V;i++){
		visited[i]=false;
	}
	queue<int>q;
	int s=1;
	visited[s]=true;
	q.push(s);
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
	BFS(adj,V);
	return 0;
}