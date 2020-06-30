			/* DFS:undirected Graph*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int root, vector<int>adjList[], int n, bool visited[]){
	if(n==0) return;
	
	stack<int>st;	//1
	st.push(root); //2
	
	while(!st.empty()){
		
		int curr= st.top(); //3
		st.pop();
		
		if(!visited[curr]){ 
			
			visited[curr]=true; //4
			
			cout<<curr<<" ";
			
			for(auto neighbours:adjList[curr]) //5
			{
				if(!visited[neighbours]) st.push(neighbours);					
			}
		}
		
	}
	
	
}

int main() {
	
	int nodes, edges;
	cin>>nodes>>edges;
	
	vector<int>adjList[nodes+1]; //to store edges
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
	dfs(root,adjList,nodes, visited);
	
	return 0;
}

/*
	DFS/BFS:Algo->

1. Choose proper ds (ie dfs->stack and bfs->queue)
2. Add starting node to the ds
3. Pull a node (take top element and pop it)
4. Process it if not seen
5. Add unseen childrens

*/

