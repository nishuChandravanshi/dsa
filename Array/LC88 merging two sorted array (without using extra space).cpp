class Solution {
public:
              
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {     
        
        int n1Last = m-1;
        int n2Last = n-1;
        
        for(int i = m+n-1; i >= 0; i--){    //initially i pointing to the last index of merged array 
            
            if(n2Last<0)
                break;
            
            if(n1Last >= 0 and nums1[n1Last] >= nums2[n2Last])
            {
                nums1[i] = nums1[n1Last];
                n1Last--;
            }
            else {
                nums1[i] = nums2[n2Last];
                n2Last--;
            }
        }
        
    }
};

// merging nums2 into nums1 without using extra space for new merged array.
//two ptr approach: as we know the max(lastIndexes) will be the max of merged array
//T: O(m+n)
