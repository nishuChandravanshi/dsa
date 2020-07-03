class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        
        int maxSum = nums[0];
        for(int i=1 ; i<n ; i++)
        {
            if(nums[i-1] > 0)
                nums[i] += nums[i-1];
            maxSum = max(maxSum, nums[i]);
        }
        
        
        
        return maxSum;        
    }
};

/* Kadane's algorithm - T: O(n), S:O(1)
The main ideas are:
Use the input vector nums to store the candidate subarrays sum (i.e. the greatest contiguous sum so far).
Ignore cumulative negatives, as they don't contribute positively to the sum.*/
