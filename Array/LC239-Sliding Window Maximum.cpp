class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
        int n = nums.size();
        if(n == 1) return {nums[0]};
        
        if(k == 1) return nums;
        
        vector<int> res;
        deque<int> d;
          
        for(int i = 0; i < n; i++)
        {
            while(!d.empty() and d.front() < i-k+1) //removing out of window
                d.pop_front();
            
            while(!d.empty() and nums[d.back()] < nums[i]) //1
                d.pop_back();
          
            d.push_back(i);
           
            if(i >= k-1)
            res.push_back(nums[d.front()]);
        }
        
       return res;
    }
};

/*
        T: O(n) S: O(window-size)
Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 

idea- 
-maintaining front of deque as maximum of window
-//1 => removing the elements in window which are less than new element encoutered
as those elements wont be useful anymore as the newer will be there as (as its max) for further windows 
*/
