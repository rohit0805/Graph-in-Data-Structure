#include<bits/stdc++.h>
using namespace std;
int indegree[10];
void addedge(vector<int> adj[],int u,int v){
	adj[u].push_back(v);
	indegree[v]++;
}
void topologicalsorting(vector<int> adj[],int V){
	int i;
	queue<int> q;
	for(i=0;i<V;i++){
		if(indegree[i]==0)
			q.push(i);
	}
	while(!q.empty()){
		int root=q.front();
		q.pop();
		cout<<root<<" ";
		for(auto x:adj[root]){
			if(indegree[x]>=1){
				indegree[x]--;
			}
			if(indegree[x]==0){
				q.push(x);
			}
		}
	}
}
void toploop(vector<int> adj[],bool visited[],int i,stack<int>&s){
	visited[i]=true;
	for(auto x:adj[i]){
		if(visited[x]==false){
			toploop(adj,visited,x,s);
		}
	}
	s.push(i);
}

void toposort(vector<int> adj[],int V){
	bool visited[V];
	int i;
	for(i=0;i<V;i++){
		visited[i]=false;
	}
	stack<int>s;
	for(i=0;i<V;i++){
		if(visited[i]==false)
			toploop(adj,visited,i,s);
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main(){
	int V=5;
	vector<int> adj[V];
	addedge(adj,0,2);
	addedge(adj,0,3);
	addedge(adj,1,3);
	addedge(adj,1,4);
	addedge(adj,2,3);
	cout<<"Topological sorting using BFS\n";
	topologicalsorting(adj,V);
	cout<<"\nTopological sorting using DFS\n";
	toposort(adj,V);
	return 0;
}