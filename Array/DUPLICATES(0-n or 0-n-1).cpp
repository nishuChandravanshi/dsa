
//Find Missing And Repeating (range 1 to n, one no missing and one repeating)
//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating/0
// S:O(1), T:O(n)
//ip-1 3 3 : op-3,2(repeating,missing)
int i=0;
while(i<n)
{
    if(a[i] != i+1 && a[a[i]-1]!= a[i])
        swap(a[i], a[a[i]-1]);
    else{
        i++;    
    }
}
for(int i=0;i<n;i++)
{
    if(a[i]!=i+1)
   {
        cout<<a[i]<<" "<<i+1<<endl;
        break;
    }
}


//FIND DUPLICATES range of values [0 ,(n-1)] in array of size n
//https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1
//S:O(1), T:O(n)
//    {2,3,1,2,3,2} : op- 2 3
//ind: 0 1 2 3 4 5
vector<int> duplicates(int a[], int n) {
    vector<int> res;
    if(n ==1)
        return {-1};
    for(int i=0;i<n;i++)
    {   
        int ind = a[i]%n; // increamenting value at index a[i] (ie a[a[i]]) by n : so as to mark presence of a[i]
        a[ind] += n;   //(at max n-1) + n --> if a[i]/n > 1 --> i is being repeated  
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]/n > 1) //value at index i has been incremented by n more than once => i is repeated 
            res.push_back(i);
    }
    if(res.empty())
        return {-1};
    return res;
}
