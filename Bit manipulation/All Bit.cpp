//no. of set bits :O(logn)
int fastSetBits(int n){
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    } 
   return count;
//O(n)
// while(n)
// {
//     count += n&1;
//     n = n>>1;
// }
}