class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return {nums[0]}; 
        
        int count1 = 0, count2 = 0;
        int first = INT_MAX, second = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(first == nums[i])
                count1++;
            else if(second == nums[i])
                count2++;
            else if(count1 == 0)
            {
                first = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                second = nums[i];
                count2++;
            }
            else{
                count1--;
                count2--;
            }
                
        }
        
        count1 = 0;
        count2 = 0;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == first)
                count1++;
            if(nums[i] == second)
                count2++;
            
        }
         if(count1 > nums.size()/3)
                res.push_back(first);
        if(count2 > nums.size()/3)
                res.push_back(second);
        
        return res;
    }
};


/*  T: O(n), S: O(1)
ip:[10, 10, 20, 30, 10, 10]
Op : 10
ip : [3,2,3]
Op: [3]
idea- Moore's Voting algo
*/
