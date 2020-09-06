
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        int total= n+m;
        
    	int i=0;
    	int j=0;
    	int prev=0;
    	int current=0;
        //1 2
        //3 4
    	for (int k=0; k<1+(n+m)/2; k++) {
			
            prev = current; //@fOc

    		if (i<n && (j>=m || m==0 || nums1[i] <= nums2[j])) {
    			current = nums1[i];
    			i++;
    		} else {
    			current = nums2[j];
    			j++;
    		}
    	}

    	if (total%2 == 1) {
    		return current;
    	} else {
    		return (current+prev)/2.0;
    	}

 
    }
};

//O(log(m+n)) soln: idea-> binary  search
//code-credit @Tushar Roy
// https://github.com/mission-peace/interview/blob/master/src/com/interview/binarysearch/MedianOfTwoSortedArrayOfDifferentLength.java


/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 * Solution
 * Take minimum size of two array. Possible number of partitions are from 0 to m in m size array.
 * Try every cut in binary search way. When you cut first array at i then you cut second array at (m + n + 1)/2 - i
 * Now try to find the i where a[i-1] <= b[j] and b[j-1] <= a[i]. So this i is partition around which lies the median.
 *
 * Time complexity is O(log(min(x,y))
 * Space complexity is O(1)
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 * https://discuss.leetcode.com/topic/4996/share-my-o-log-min-m-n-solution-with-explanation/4
 */

// 1 2 4
//-1 2 3 4 5
public class MedianOfTwoSortedArrayOfDifferentLength {

    public double findMedianSortedArrays(int input1[], int input2[]) {
        //if input1 length is greater than switch them so that input1 is smaller than input2.
        if (input1.length > input2.length) {
            return findMedianSortedArrays(input2, input1);
        }
        int x = input1.length;
        int y = input2.length;

        int low = 0;
        int high = x;
        while (low <= high) {
            int partitionX = (low + high)/2; //starting partitioning from mid of nums1
            int partitionY = (x + y + 1)/2 - partitionX; //as partX+partY must sum up to mid(ie x+y+1)/2

            //if partitionX is 0 it means nothing is there on left side. Use -INF for maxLeftX
            //if partitionX is length of input then there is nothing on right side. Use +INF for minRightX
            int maxLeftX = (partitionX == 0) ? Integer.MIN_VALUE : input1[partitionX - 1]; //as comp b/w maxLeftY and minRightY will be done. => if there's ntg in left of x(nums1) then it maxLeftX < minRightY should return true;
            int minRightX = (partitionX == x) ? Integer.MAX_VALUE : input1[partitionX];

            int maxLeftY = (partitionY == 0) ? Integer.MIN_VALUE : input2[partitionY - 1];
            int minRightY = (partitionY == y) ? Integer.MAX_VALUE : input2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                //We have partitioned array at correct place
                // Now get max of left elements and min of right elements to get the median in case of even length combined array size
                // or get max of left for odd length combined array size.
                if ((x + y) % 2 == 0) {
                    return ((double)Math.max(maxLeftX, maxLeftY) + Math.min(minRightX, minRightY))/2;
                } else {
                    return (double)Math.max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) { //we are too far on right side for partitionX. Go on left side.
                high = partitionX - 1;
            } else { //we are too far on left side for partitionX. Go on right side.
                low = partitionX + 1;
            }
        }

        //Only we we can come here is if input arrays were not sorted. Throw in that scenario.
        throw new IllegalArgumentException();
    }

    public static void main(String[] args) {
        int[] x = {1, 3, 8, 9, 15};
        int[] y = {7, 11, 19, 21, 18, 25};

        MedianOfTwoSortedArrayOfDifferentLength mm = new MedianOfTwoSortedArrayOfDifferentLength();
        mm.findMedianSortedArrays(x, y);
    }
}


//// check***dry run: WA {3 fkng HOURS!!}
class Solution {
public:
    // wa
    // [1,2,3,4,6]
    // [5]      
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int x = nums1.size();  //3
        int  y = nums2.size(); //4
        int total = x+y;
        if(x>y)
            findMedianSortedArrays(nums2,nums1);
        
        int n1=x,n2=y,midInd = (total-1)/2;
        if(n1==0 && n2==0)
            return 0;
        if(n1==0)
        {
            
            if(n2%2)
                return (double)(nums2[midInd]);
            else 
                return (((double)(nums2[midInd])+(double)(nums2[midInd+1]))/2);
        }
        else if(n2==0)
        {
            
            if(n1%2)
                return (double)(nums1[midInd]);
            else 
                return (((double)(nums1[midInd])+(double)(nums1[midInd+1]))/2);
        }        
        
        
        //as x possible partitions
        int low = 0, high = x;//(0,3)
        
        while(low<=high)
        {
            int partX = (low+high)/2; //(0+5),(3+5)
            //leftPartition of nums1 belongs to->[0,partX)
            int partY = (x+y+1)/2 - partX; //as partX+partY must == (x+y+1)/2: {+1 cuz there'll be extra element on left side if total lenght is odd}
            
            int maxLeftX = (partX <= 0) ? INT_MIN : nums1[partX-1]; //2
            int minRightX = (partX >= x) ? INT_MAX : nums1[partX]; //3
            
            int maxLeftY = (partY<=0)? INT_MIN: nums2[partY-1]; //4
            if(partY == -1)
                partY++;
            int minRightY = (partY>=y)?INT_MAX: nums2[partY]; //max
            
            if(maxLeftX<= minRightY && maxLeftY<= minRightX)
            {
                if(total%2) //if odd length => last element of left half is median
                    return max(maxLeftY,maxLeftX)/1.0;
                else{
                   return ((max(maxLeftY,maxLeftX))+min(minRightX,minRightY))/2.0;
                }
            }
            else if(maxLeftY > minRightX)
                low = partX+1; //2+1
            else 
                high= partX -1;;
                
        }
        
        return -1;
    }
};