void diagonalPrint(Node* root, int d, map<int, vector<int> > diagonalPrint)
{
     if(!root) return;
     
     diagonalPrint[d].push_back(root->data);
     
     diagonalPrint(root->right, d, diagonalPrint);
     diagonalPrint(root->left, d+1, diagonalPrint);
	
}

void diagonalPrint(Node* root) 
{ 
    // create a map of vectors to store Diagonal elements 
    map<int, vector<int> > diagonalPrint; 
    
    diagonalPrint(root, 0, diagonalPrint); 
  
    cout << "Diagonal Traversal of binary tree : n"; 
    for (auto it = diagonalPrint.begin(); 
         it != diagonalPrint.end(); ++it) 
    { 
        for (auto itr = it->second.begin(); 
             itr != it->second.end(); ++itr) 
            cout << *itr  << ' '; 
  
        cout << 'n'; 
    } 
}

/*
idea-
-d-> diagonal distance
-map<->diagonalPrint-> store all the elements at same diagonal distance in a vector(ie with d as key)
-diagonal distance of right child of a node is same as its parent and that of left child is +1 (therefore d+1 in recursive call) of its parent
*/
