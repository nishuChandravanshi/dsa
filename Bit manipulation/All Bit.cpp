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

************
//0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
// 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.


// Swap all odd and even bits
unsigned int swapBits(unsigned int x) 
{ 
	// Get all even bits of x 
	unsigned int even_bits = x & 0xAAAAAAAA; 

	// Get all odd bits of x 
	unsigned int odd_bits = x & 0x55555555; 

	even_bits >>= 1; // Right shift even bits 
	odd_bits <<= 1; // Left shift odd bits 

	return (even_bits | odd_bits); 
} 



