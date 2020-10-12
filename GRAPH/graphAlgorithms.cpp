//directed
void dfs(int node) {
    //process

    for(auto child: graph[node]) {
        if(!vis[child])
            dfs(child)
    } 
}

//undirected
void dfs(int node, int par) {
    //process

    for(auto child: graph[node]) {
        if(child!=par)
            dfs(child, node)
    } 
}


//cycle in undirected graph 
bool dfs(int src, int par) {  //returns true if cycle is present
    vis[src] = true;
    bool cycle = false;
    for(auto to: adj[src]) {
        if(!vis[to]) {
            cycle |= dfs(to, src);
        
        }
        else if(to!=par)
            return true;
    }
    return cycle;
}
bool isCyclic(vector<int> g[], int V)
{
    vector<bool>visited(V,0);
    for(int i = 0; i < V; i++)  //gotta dfs for each node as there can be disconnected graphs
        if(!visited[i] and dfs(i,-1 ,g, visited))
            return true;
            
    return false;
}

//cycle in directed graph

//if above algo is used for directed graph then false loop may be detected, to 
//-avoid this condition we use below algo for detecting cycle in dag,

//col[node]: 0-> unprocessed, 1->in process(in stack), 2->processed(out of stack)
//if in recursion col[child] = 1 => cycle
//init col with 0
//initially set col[i] = 0 for all nodes  //run this dfs for all nodes whise col[i]=0;
bool dfs(int src) { //returns true if cycle is present
    
    bool cycle = 0; 
    col[src] = 1;
    for(auto to:adj[src]) {
        if(col[to]==1) {
            return true;
        }
        else if(col[to]==0){
            cycle |= dfs(to);
        }
    }

    col[src] = 2;
    return cycle;
}


//topological sort 1 using dfs
vector<int>order;
void dfs(int src) {
    vis[src] = true;

    for(auto to:adj[src]) {
        if(!vis[to])
            dfs(to);
    }

    order.push_back(src);
}
//order is reverse of topological sort
reverse(order.begin(), order.end());
return order;


//topological sort 2 using bfs and indegree

int indegree[n] // stores indegree of all nodes
bool vis[n]  //not really necessary if we dont have to worry about cycle
vector<int>order;
queue<int>q;

for(int i=0;i<n;i++) {
    if(indegree[i]==0)
        q.push(i); //push nodes having 0 indegree  
}

while(!q.empty()) {
    int curr = q.front();
    vis[curr] = true;
    q.pop();

    order.push_back(curr); //push node with indegree 0, and remove it from the graph => indegree[child]--
    for(auto to: adj[curr]) {
        indegree[to]-;
        if(indegree[to]==0)
            q.push(to);
    }
}
return order;  //this stores in correct order
//if(order.size()<n) //cycle present
//if all nodes are not visited in vis[n] then the graph has a cycle 

//indegree calculations
vector<int> indegree(V,0);  //indegree[node]
for(int u = 0; u < V; u++)  //u->v => indegree[u] = 0, indegree[v] = 1
{
    for(auto v: adj[u])
        indegree[v]++;
}

#################################################################################

//bipartite checking

//https://leetcode.com/problems/is-graph-bipartite/
// its possible to have independent vertex as-
// eg- <vector<vector<int>>graph -> [[4],[],[4],[4],[0,2,3]] {independent node - 1} {ans: true}
bool dfs(int src, int col) {
    colour[src] = col;
    vis[src] = true;
    bool is_bip = true;

    for(auto to: adj[src]) {
        if(!vis[to]) {
            is_bip &= dfs(to, 1-col);
        }
        else if(col[to]==col[src])
            return false;
    }

    return is_bip;
}
//to keep track of disconnected components
for(int i=0;i<V;i++)
{
    if(color[i]==-1)
    {
        ans &= dfs(i,0,g,color);
    }
}
return ans; //correct ans for whole graph

###################################################################################

//dijkstra ->Single source shortest path (shortest distance to all nodes from single source) 
//does not necessarily work if graph has negative edges
//can work with cycle if no negative edge is there
//O((E+V)*log(V))  max size of heap is v so logV, E+V comes from bfs
// ==O(E * logV)

int dis[n];
for(int i=0;i<n;i++) {
    dis[i] = INT_MAX;
}
dis[src] = 0;
vector<int , vector<pair<int, int>>> adj; //adj[0] = [(2,15),(3,100),....]   (node,distance) //or vector<pair<int,int>> adj[]
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap 
pq.push(make_pair(0,src)) //distance, node

while(!pq.empty) {  

    pair<int, int> cp = pq.top();
    pq.pop();

    int currNode = cp.second;
    int currDis = cp.first;

    if(currDis>dis[currNode]) //this is not reqd ig as currDist is itself the dis[currNode], we set while adding it in pq previously
        continue;

    if(currDis==INT_MAX) {
        return;  //all nodes after this wil have infinity ditance, so all are unreachable
    }

    for(auto to: adj[currNode]) {
        if(currDis+to.second<dis[to.first]){
            dis[to.first] = currDis+to.second;
            pq.push(make_pair(currDis+dis[to.first],to.first));
        }
    }

}

//dijkstra gfg implementation
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// input g is a matrix => where g[i][j] = distance(weight) of i to j
// g[i][j] = 0 => there's no path from i to j (eg [0][0] = 0 to 0 (same node dist obv 0 lol))
vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    vector<pair<int,int>> adj[V];  //node, dist
    for(int i =0; i<V; i++)
    {
        for(int j =0; j<V; j++)
        {
            if(g[i][j] != 0)
                adj[i].push_back({j,g[i][j]});
        }
    }
    
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; //dist,node
    pq.push({dist[src], src});
    
    while(!pq.empty())
    {
        pair<int,int> cp = pq.top();
        pq.pop();
        
        int currNode = cp.second;
        int currDist = cp.first;
        
        if(currDist == INT_MAX)
            break;
        
        for(auto to : adj[currNode])
        {
            if(currDist+to.second < dist[to.first])
            {
                dist[to.first] = currDist+to.second;
                pq.push({dist[to.first], to.first});
            }
        }
    }
    return dist;
}

##############################################################################
//Minimum Spanning Tree
//Prim's algorithm && Kruskal


Prim’s algorithm assumes that all vertices are connected. 
But in a directed graph, every node is not reachable from every other node.
So, Prim’s algorithm fails due to this reason.

//Prim's algorithm for dense graph -> O(n^2)

void prim() {

    vector<pair<int, int>>min_e(n);  //stores minimum edge distance to ith selected vertice from unselected vertices -> dist, vertex
    for(int i=0;i<n;i++) {
        min_e[i] = make_pair(INT_MAX, -1);
    }

    int selected[n];
    memset(selected, 0, sizeof(selected));

    int tot_wt = 0; //store minimum cost

    vector<vector<pair<int, int>>>adj; //as above stores node, distance

    min_e[0].first = 0;  //since we will select first node, make it's dist 0

    for(int i=0; i<n; i++) { //keeps count of n nodes
        
        int v = -1;

        for(int j=0; j<n; j++) {
            if(!selected[j] && (v==-1 || min_e[v].first < min_e[j].first)) {
                v = j;
            }
        }

        if(min_e[v].first==INT_MAX) {
            return; //mst not possible  ---> doubt??
        }

        cout<<v<<" "; //node selected;
        selected[v] = true;
        tot_wt+=min_e[v].first;

        for(auto to: adj[v]) {
            if(to.second < min_e[to.first].first)  //if dist to v is less than current min_e for to's node
                min_e[to].first = to.second;
                min_e[to].second = v;
        }
    }



//Prims for sparse graph -> O(ElogV)
adj -> vector<vector<pair<int, int>>>  //node, dis
int selected[n]; --> initialize to 0
min_e ->vector<pair<int, int>> -> initialize to make_pair(INT_MAX, -1) -> dis, node


set<pair<int, int>>s; //store dis, node -> unselected

min_e[0].first = 0;
min_e[0].second = 0;
s.insert(make_pair(0,0));
int tot_wt = 0;

int i=0
while(i<n) {

    if(s.empty())
        return; //mst not possible

    pair<int, int> vpair = *s.begin();
    int v = vpair.second;
    int d = vpair.first;

    s.erase(s.begin());
    selected[v] = 1;

    tot_wt+=d;

    for(auto to: adj[v]) {
        if(to.second < min_e[to.first].first) {
            set<pair<int, int>> :: iterator it;
            it = s.find(make_pair(min_e[to.first].first, to.first));
            if(it!=s.end())
                s.erase(it);
            
            min_e[to.first] = make_pair(to.second, v);
            s.insert(make_pair(min_e[to.first].first, to.first)); //s stores dist and node to be added
        }
    }

}




########################################################

//Kruskal -> O(n^2)

in union find a false cycle is also detected, hence in dag Kruskal may fail

vector<int, pair<int, int>> edges; //dis, (u,v)
int treeId[n]; //stores parent like in dsu, to detect if edge is making a cycle

sort(edges.begin(), edges.end());
int tot_wt = 0;

for(auto edge: edges) {
    int d = edge.first;
    int u = edge.second.first;
    int v = edge.second.second;

    if(treeId[u]!=treeId[v]) { //include the edge in mst, you can do any related processing here
        tot_wt+=d; //adding cost

        //arbitrarily either change u to v or v to u--> here u is changed to v

        for(int i=0; i<n; i++) {
            if(treeId[i]==treeId[u])
                treeId[i] = treeId[v];
        }
    }
}


#################################################################

//DSU //using path compression-> ackerman's constant alpha for practical purpose <4  -->time=O(alpha * n) ===O(n) -> n is number of queries

int par[n];
memset(par, -1, sizeof par);

int ssize[n];
memset(ssize, 0, sizeof ssize);

voi makeSet(int u) {
    par[u] = u;
    ssize[u] = 1;
}

int findParent(int u) {
    if(par[u]==u)
        return u;

    par[u] = findParent(par[u]);
    return par[u];
}

void union(int u, int v) {  
    pu = findParent(u);
    pv = findParent(v);

    if(pu==pv) //already in same set
        return;
    
    if(ssize[pu]<ssize[pv]) {
        swap(pu, pv);
    }

    ssize[pu]+=ssize[pv];
    par[pv] = pu;

}



###############################################
//Kruskal using dsu -> MlogN sorting + N makeSet + M queries dsu

vector<int, pair<int, int>>edges; //dist, (u,v)

int par[n];
int ssize[n];

int tot_wt=0;

void makeSet(int u) {
    par[u] = u;
    ssize[u] = u;
}

int findParent(int u) {
    if(par[u]==u)
        return u;

    par[u] = findParent(par[u]);
    return par[u];
}

void mergeSets(int u, int v) {  //u and v are roots and u!=v
    if(ssize[a]<ssize[b])
        swap(a,b);

    ssize[a]+=ssize[b];
    par[b] = a;
}

for(int i=0;i<n;i++)
    makeSet(i);

for(auto edge: edges) {
    int d = edge.first;
    int u = edge.second.first;
    int v = edge.second.second;

    int a =findParent(u);
    int b =findParent(v);

    if(a!=b) {
        tot_wt+=d; //include edge in mst

        mergeSets(a,b);
    }
}




#############################################################
//Articulation Point -> O(E+V)
//tin -> entry time
//low -> lowest time for any node in it's subtree, if we get a backedge or crossedge we don't go beyond the cycle and compare with other lows

if low for a child is lesser than the entry time of parent then there's some other way of reaching it, hence
parent is not an Articulation Point

not applicable for root -> if root has more than 1 children it is Articulation Point

int low[n];
int tin[n];
int timer=0;
int vis[n];

void dfs(int v, int par=-1) {
    int children = 0;
    low[v]=tin[v]= ++timer;
    vis[v]=1;
    for(auto to: adj[v]) {
        if(to!=par) {
            if(vis[to]) {
                low[v] = min(low[v], tin[to]);  //backedge or crossedge, don't go beynd cycle, hnce cmp with tin because only that point is in the cycle 
            }
            else {
                dfs(to, v);
                low[v] = min(low[v], low[to]); //part of cycle cna cmp with low here

                if(low[to]>=tin[v] && p!=-1) { //root is not valid
                    cout<<u<<" is Articulation point";
                }
            }
            children++;
        }
    }

    if(p==-1 && children>1) {
        cout<<"root is Articulation point "<<v;
    }

}

##########################################################
//Bridge

void dfs(int v, int p=-1) {
    low[v] = tin[v] = ++timer;
    vis[v] = true;

    for(auto to: adj[v]) {
        if(to!=par) {
            if(vis[to]) {
                low[v] = min(low[v], tin[to]);
            }
            else {
                dfs(to,v);
                low[v] = min(low[v], low[to]);

                if(low[to]>=tin[v]) {
                    cout<<u<<" "<<v<<" Bridge"<<endl;
                }
            }
        }
    }

}



######################################################################################
SCC -> Tarjans algorithm : O(E+V)

int id[n]; //initialize to -1; will also be used as visited
bool onStack[n]; //initialize to false
int low[n];

stack<int>s;

int timer = 0;

void dfs(int v) {
    low[v] = id[v] = ++timer;
    s.push(v);
    onStack[v] = true;

    for(auto to: adj[v]) {
        if(id[to]==-1) {  //unvisited
            dfs(to);
        }
        if(onStack[to]) {
            low[v] = min(low[v], low[to]);
        }
        }
    }

    if(low[v]==id[v]) { //start of SCC

        while(s.top() != v) {
            int u = s.top();
            s.pop();
            onStack[u] = false;
            id[u] = id[v]; //these all will be in same SCC, you can also put them in a list over here
        }

    }
}

for(int i=0; i<n; i++) {
    if(id[i]==-1)
        dfs(i);
}

################################################

//Strongly Connected Components - Kosaraju O(N+M)
vector<int> adj[N];
vector<int> adjj[N];
bool vis[N];
vector<int> order, comp;

void dfs(int v){
    vis[v] = true;
    for(auto to : adj[v])
        if(!vis[to])
            dfs(to);
    order.push_back(v);
}

void dfs2(int v){
    vis[v] = true;
    comp.push_back(v);
    for(auto to ; adjj[v])
        if(!vis[to])
            dfs(to);
}

void scc(){
    for(int i=0;i<N;i++){
        for(auto to : adj[i])
            adjj[to].push_back(i);
    }
    
    for(int i=0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
       
    memset(vis, 0, sizeof vis);
    for(int i=n-1;i>=0;i--){
        int v = order[i];
        if(!vis[v]){
            dfs2(v);
            for(auto x : comp)cout<<x<<" ";
            cout<<endl;
            comp.clear();
        }
    }
}

//Floyd Warshall O(n^3)
for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][k] < INF && d[k][j] < INF)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
        }
    }
}





***********************************************************************************
// MINIMUM SWAPS TO SORT AN ARRAY
// https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
// ans += for all cycles(cycle Size -1)
// {4, 5, 2, 1, 3} ans 3 (cycle-> (5->3,3->2,2->5) :(3-1 = 2) + (4->1,1->4) : (2-1 =1) })
//edge from i->j => correct pos of i index is j. so connections are made acgly and cycle size is found
int minSwaps(vector<int> arr)
{
    int n = arr.size();
    
    pair<int,int> pos[n];
    for(int i=0;i<n;i++)
        pos.push_back({arr[i], i}); //val,index 

    sort(pos.begin(), pos.end()); //now pos[i] = {val, its original posn} => original pos -> i(correct pos)

    int ans = 0;
    vector<bool> vis(n,0);
    for(int i =0;i<n;i++)
    {   
        if(visited[i]) continue;
        
        int j = i;
        int cycleSize =0;

        while(!visited[j])
        {
            visited[j] = true;
            j = pos[j].second;
            cycleSize++;
        }

        if(cycleSize >0)
        ans += cycleSize -1;
    }
    return ans;
}

