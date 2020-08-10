class Solution {
public:
        //  T:O(nlogk) -minHeap of size k is maintained first then top of heap is checked with remaing n-k elements and updated accordingly.
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n= nums.size();
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0;i<k;i++)
            pq.push(nums[i]);
        
        for(int i=k;i<n;i++){
            
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
            
        }
        
        return pq.top();
    }
};
