//FACTORIAL : (100! :158 digits, 1000! :2568 digits )
// https://www.geeksforgeeks.org/factorial-large-number/
//to store product in vector<int>(maxNoofOpdigits), (storing digits in reverse order: so as for easy multplication and updation)
// 5 - 120
// 10 - 3628800
vector<int>res(3000);//no of digits in 1000! is 2568
int multiply(int x, int resSize)
{
    int carry =0;
    for(int i=0;i<resSize;i++)
    {
        int prod = x*res[i]+carry; //4*3=12 (=>2,1)
        res[i] = prod%10;
        carry = prod/10;
    }
    
    while(carry)
    {
        res[resSize] = carry%10;
        carry /= 10;
        resSize++;
    }
    return resSize;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t ;cin>>t;
    while(t--)
    {   
        res.clear();
        int n; cin>>n;
        
        int resSize = 1;
        res[0]=1;
        
        for(int i=2;i<=n;i++) //calculating factorial
            resSize = multiply(i,resSize); //(2,1){res[0]=2}->(3,1){res[0]=2*3}->(4,1){4*6=> res[0]=2,res[1]=1 & resSize=2->...}
        
        for(int i=resSize-1;i>=0; i--) //prod store in res[] in reversed order
            cout<<res[i];
        cout<<endl;
    }
	return 0;
}


