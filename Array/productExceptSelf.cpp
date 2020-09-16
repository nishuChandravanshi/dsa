
// T:O(n) S:O(n)
// https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/827/

class Solution {
public:
//      Input:  [1,2,3,4]
//      Output: [24,12,8,6]
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size() <=1)
            return {};
        int n= nums.size();
        
        int pre=nums[0];
        vector<int> suff(nums.size(),1);
        
        suff[n-1] = nums[n-1];
        for(int  i=n-2;i>=0;i--)
            suff[i] = nums[i]*suff[i+1];

        nums[0] = suff[1];
        for(int i=1;i<nums.size()-1;i++)
        {
            int t =nums[i];
            nums[i] = pre* suff[i+1];
            pre *= t;
        }
        nums[n-1] = pre;
        
        return nums;
    }  
};
