			/* DFS:undirected Graph*/
#include <bits/stdc++.h>
using namespace std;

void bfs(int root, vector<int>adjList[], int n, bool visited[]){
	if(n==0) return;
	
	queue<int>q;	//1
	q.push(root); //2
	
	while(!q.empty()){
		
		int curr= q.front(); //3
		q.pop();
		
		if(!visited[curr]){ 
			
			visited[curr]=true; //4
			
			cout<<curr<<" ";
			
			for(auto neighbours:adjList[curr]) //5
			{
				if(!visited[neighbours]) q.push(neighbours);					
			}
		}
		
	}
	
}


int main() {
	
	int nodes, edges;
	cin>>nodes>>edges;
	
	vector<int>adjList[nodes+1];
	bool visited[nodes+1];
	
	int u,v;
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	
	memset(visited,false, sizeof(bool)*(nodes+1));

	int root= 1;
	bfs(root,adjList,nodes, visited);
	
	return 0;
}

/*
	DFS/BFS:Algo->

1. Choose proper ds (ie dfs->stack and bfs->queue)
2. Add starting node to the ds
3. Pull a node (take top element and pop it)
4. Process it if not seen
5. Add unseen childrens

T: O(n), n: no of nodes: as all the nodes are visited ones

*/

