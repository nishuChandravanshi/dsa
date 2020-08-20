0 1 0 0 1    Rooms: 5
1 0 0 0 1
0 1 1 1 1
1 0 0 1 0

void countRoomsHelper(int i, int j, vector<vector<int>> &v)
{
    if(i >= v.size() or j >= v[0].size() or i < 0 or j < 0)
        return ;
    if(v[i][j] == 1)
        return;
    if(v[i][j] == 0)
    {
        v[i][j] = 1;
        countRoomsHelper(i+1, j, v);
        countRoomsHelper(i-1, j, v);
        countRoomsHelper(i, j+1, v);
        countRoomsHelper(i, j-1, v);
    }
 
}

int countRooms(vector<vector<int>> &v)
{
    int n = v.size();
    if(n == 0) return 0;
    int m = v[0].size();

    int rooms = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            if(v[i][j] == 0){
                countRoomsHelper(0, 0, v);
                rooms++;
            }
    }
    
    return rooms;
}

//
A B 1.2   1 A = 1.2 B  => A/b = 1.2
B C 4.2
D E 8

Q queries:
A B 10 => 10 coins of A:: B?  10/1.2

float dfs(int src,int dest, vector<pair<int, float>> g[n], vector<bool> &visited, float factor)
{
    visited[src] = true;
    
    if(src == dest)
        return factor;
    
    for(auto to : g[src])
    {
        if(!visited[to.first])
        {
            int child = to.first;
            float childFact = to.second;

            return dfs(child,dest, g, visited, factor*(1/childFact));
        }

    }

}

vector<float> conversion(vector<pair<pair<char, char>, int>> &v, vector<pair<pair<char, char>, int>> &queries)
{
    
    vector<pair<int, float>> g[n];
    
    for(int i = 0; i < v.size(); i++)
    {
        g[v[i].first.first - 'A'].push_back({v[i].first.second, v[i].second});
        g[v[i].first.second - 'A'].push_back({v[i].first.first, 1/v[i].second});
    }

    vector<float>res;
    for(int i = 0; i < queries.size(); i++)
    {
        int src = queries[i].first.first;
        int dest = queries[i].first.seccond;
        int coins = queries[i].second;
        vector<bool> visited(n,0);
        float factor = dfs(src,dest, g, visited,1);

        res.push_back(factor);
    }
    
    
    return res;
    
}

//merge,quick->ll

vector<int> kthMax(vector<int> v,int k)
{
    if(k == 1)
        return v;
    
    vector<int>res;
    
    priority_queue<pair<int,int>> pq;
    for(int i = 0; i<k; i++)
        pq.push({v[i],i});

    res.push_back(pq.top().first);
    int start = 1;
    for(int i = k; i < v.size(); i++)
    {
        while(!pq.empty() && pq.top().second < start)
            pq.pop();

        pq.push({v[i],i});

        res.push_back(pq.top().first);
        start++;
    }
    return res;

}

//
vector<int> kthMax(vector<int> v,int k)
{
    if(k == 1) return v;

    vector<int> res;
    dequeue<int> dq;
    for(int i = 0; i<v.size(); i++)
    {
        if(!dq.empty())
            dq.push_back(i);
        else if(v[i] <= v[dq.back()])
            dq.push_back(i);
        else 
        {
            while(!dp.empty() && v[i] > v[dq.back()])
                dq.pop_back();
            dq.push_back(i);

        }
        while(!dq.empty() && dp.front() < i-k+1)
            dq.pop_front();

        if(i >= k-1)
            res.push_back(v[dq.front()]);
    }     

}
//


node* first = NULL;
node* lca(node* root, node* a, node* b)
{
    if(root == NULL) return NULL;

    if(root == a)
        return a;
    if(root == b)
        return b;
    
    node* left = lca(root->left, a, b);
    node* right = lca(root->right, a, b);

    if(left && right) return root;
    
    return  left ? left : right;
}

bool cInPath(node* l, node* c, node* a, node* b)
{
    if(l == NULL)
        return false;

    if(l == a)
        first = a;
    else if(l == b)
        first = b;
    if( l == c)
    {
        if(first == NULL) first = c;
        return true;
    }
        
    
    bool left = cInPath(l->left, c, a, b);
    bool right = cInPath(l->right, c, a, b);

    return left || right;
}


node* deleteNode(node* root, node* a, node* b, node* c)
{
    node* l0 = lca(root, a, b);

    bool cInPath = inPath(l0, c, a, b);
    if(cInPath == false)
        return l0;
    else{
        return first; 
    }

}
