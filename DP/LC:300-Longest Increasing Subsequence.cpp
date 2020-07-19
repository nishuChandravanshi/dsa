class Solution {
public:
    int LIS(vector<int>& nums, vector<int>& lis){
        
        int n = nums.size();
        int ans = INT_MIN;
        
        for(int i =  1; i < n; i++){
            
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    lis[i] = max(lis[i], lis[j]+1);
            }
            
            ans = max(ans, lis[i]);
        }
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 1) return 0;
        if(n == 1) return 1;
        
        vector<int> lis(n,1);
        
        return LIS(nums, lis);
        
    }
};
/*
	T: O(n^2) S: O(n)
-lis(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
*/
