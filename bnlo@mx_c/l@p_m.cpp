
// SIEVE OF ERATOSTHENES : to find all prime numbers upto n : T:->@dis
// https://practice.geeksforgeeks.org/problems/sieve-of-eratosthenes/0

// ip: 35, op: 2 3 5 7 11 13 17 19 23 29 31
vector<bool> a(n+1,true);       
for(int i=2;i*i<=n;i++)
{
    for(int j = i*i;j<=n;j+=i)
    {
        a[j] = false;   
    }
}
for(int i =2;i<=n;i++)
    if(a[i] == true)
        cout<<i<<" ";
cout<<endl;





// 24sept
// https://www.geeksforgeeks.org/maq-software-interview-experience-set-20-on-campus-for-fte/?ref=lbp
// https://www.geeksforgeeks.org/prime-factorization-using-sieve-olog-n-multiple-queries/
// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
// https://www.geeksforgeeks.org/maq-software-on-campus-for-full-time-software-engineer/














