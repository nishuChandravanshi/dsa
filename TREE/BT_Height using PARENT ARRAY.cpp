#include <bits/stdc++.h>
using namespace std;

void findDepth(int parent[], int i, int depth[])
{
	if(depth[i])
		return;
	if(parent[i] == -1)
	{
		depth[i] = 1;	//depth of parent node = 1
		return;
	}
	if(depth[parent[i]] == 0)
		findDepth(parent, parent[i],  depth);
		
	depth[i] = 1 + depth[parent[i]];
	
}

int findHeight(int parent[], int n)
{
	int depth[n];
	memset(depth, 0, sizeof(depth));

	for(int i = 0; i < n; i++)
		findDepth(parent, i, depth);
	
	return *max_element(depth + 0, depth + n);
}

int main() {
	
	// int n; cin>>n; 
	// int parent[n];
	
	// for(int i = 0; i < n; i++)
	// 	cin>>parent[i];
	
	int parent[] = {-1, 0, 0, 1, 1, 3, 5};	
	int n = sizeof(parent)/sizeof(parent[0]);
	cout<<findHeight(parent, n)<<endl;
	
	return 0;
}
/* T: O(n)
ip-parent[] = {-1, 0, 0, 1, 1, 3, 5};
op- 5 (no of nodes from root to deepest leaf)

	 0
       /   \
      1     2
     / \
    3   4
   /
  5 
 /
6
*/
