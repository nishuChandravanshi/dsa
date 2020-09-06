
// Search in a Rotated Array
// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array/0
// SINGLE PASS,T:O(logn), S:O(1){only recursive stack used}

// 5 6 7 8 9 10 1 2 3, key=10 : op-> 5
// 3 1 2, key = 1: op-> 1
// 3 5 1 2, key = 6: op-> -1

int search(int l, int h, int key, vector<int>&a)
{
    if(l>h)
        return -1;
        
    // 5 6 7 8 9 10 1 2 3
    int mid = (l+h)/2;
    if(a[mid] == key)
        return mid;
    else if(a[l] <= a[mid]) // =>left half sorted
    {
        if(key>=a[l] && key<=a[mid])
            return search(l,mid-1,key,a);
        
        return search(mid+1,h,key,a);
    }
    else //if left half aint sorted => right must be sorted! 
    {
        if(key >= a[mid] && key<=a[h])
            return search(mid+1,h,key,a);
        
        return search(l,mid-1,key,a);
    }
    
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t; 
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n);
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        int key; cin>>key;
        
        cout<<search(0,n-1,key,a)<<endl;
    }
	return 0;
}

//one more apprch is to first find the pivot(the point of distortion of two sorted array), then binary search key in one of the sorted array in which it lies.
//but then this wont be single pass