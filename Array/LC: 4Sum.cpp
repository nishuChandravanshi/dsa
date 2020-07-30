class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        map<int, int> sums;
        
        
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                int sum = A[i] + B[j];
                
                sums[sum]++;    
            }
        }
        
        int tupleCount = 0;
        for(int i = 0; i < C.size(); i++){
            for(int j = 0; j < D.size(); j++){
                int neg_sum = -(C[i] + D[j]);
                
                if(sums.find(neg_sum) != sums.end())
                     tupleCount += sums[neg_sum];
            
            }
        }
        
        return tupleCount;        
    }
};

/*
    T: O(n^2) S: O(n^2)
idea-
- to store all possibles sums taking one element from each A and B vect 
-checking if eqv -sum is possible with pairs of C and D 
    
*/
