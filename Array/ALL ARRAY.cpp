// ios_base::sync_with_stdio(false);
// cin.tie(NULL);
**********************************************************

// NO. OF PAIRS (x, y) in an array such that x^y > y^x : O(mLogm + nLogm)
// https://www.geeksforgeeks.org/find-number-pairs-xy-yx/
// ip : x={2 1 6},y={1 5}
// op : 3
//if (y>x)=> x^y > y^x with few execptions
// exceptions-> (x,y) :  ({0,1},anything),(1,0),(2,{3,4}),(3,2),(4,2)
int search(int key,vector<int>y, vector<int>noOfY)
{
    int count =0;
    if(key == 0)
        return 0;
    else if(key == 1)
        return noOfY[0];
    else {
        auto idx = upper_bound(y.begin(), y.end(), key);
        count = y.end() - idx;
        count += noOfY[1] + noOfY[0]; //since x>1 => all (x,1) & (x,0) pairs must also be added though (1,0)<x but-> x^1>1^x and x^0>0^x
    }
    if(key == 2) // as for x=2,y=3 or 4: x^y !> y^x
    {
        count -= noOfY[4];
        count -= noOfY[3];
    }
    else if(key == 3) //as for x=3 and y =2: x>y but still x^y > y^x
        count += noOfY[2]; 
        
    return count;
}

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n,m; cin>>n>>m;
        
        vector<int> x(n),y(m);
        for(int i=0;i<n;i++)
            cin>>x[i];
        
        vector<int>noOfY(5,0); //to keep track or no of 0,1,2,3,4 in y : to maintain exceptions
        for(int i=0;i<m;i++)
        {
            cin>>y[i];
            if(y[i] < 5)
                noOfY[y[i]]++;
        }       
        sort(y.begin(), y.end());
        int count =0;
        for(int i =0; i <n;i++)
        {
            count += search(x[i], y, noOfY); //to search smallest y greater than x
        }
        
        cout<<count<<endl;
       
    }
	return 0;
}
//  O(mLogm + nLogm), where n and m are the sizes of arrays X[] and Y[] respectively. The sort step takes O(mLogm) time. 
//  Then every element of X[] is searched in Y[] using binary search. This step takes O(nLogm) time.



// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/



//REARRANGE ARRAY WITHOUT USING EXTRA SPACE
// https://www.geeksforgeeks.org/rearrange-array-maximum-minimum-form-set-2-o1-extra-space/
// 1 2 3 4 5 6
// 6 1 5 2 4 3
// 10 20 30 40 50 60 70 80 90 100 110
// 110 10 100 20 90 30 80 40 70 50 60

// “arr[i] += arr[max_index] % max_element * max_element”{as max_element > greatest value in array}
//=>  arr[i]%max_element = Original_arr[i] & arr[i]/max_element = arr[max_index]
int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<long long> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        
        long long mxEle = v[n-1]+1;
        
        int mnIdx =0, mxIdx = n-1;
        for(int i=0; i<n;i++)
        {
            if(i%2 == 0) //to store maximum elements at even pos
            {
                v[i] +=  (v[mxIdx]%mxEle)*mxEle; //v[mxInd]%mxEle cuz v[mxInd] may have been modified earlier, so to ensure we get the originam v[mxIdx] ele % it with mxEle  
                mxIdx--;
            }
            else{
                v[i] += (v[mnIdx]%mxEle)*mxEle;
                mnIdx++;
            }
        }
        //extracting the original values after rearrangement
        for(int i=0;i<n;i++)
            cout<<(v[i]/mxEle)<<" ";
        cout<<endl;
    }
	return 0;
}


//SORTING 0,1,2s
vector<int>v(n);
    int f =0,l=n-1;    
        for(int i=0;i<n;i++)
        {
            if(v[i] == 0)
            {
                swap(v[i],v[f]);
                f++;
            }
            while(v[l] == 2) //to ensure l points to the index where next 2 can be placed
                l--;
            if(i <= l && v[i] == 2)
            {
                swap(v[i],v[l]);
                l--;
                if(v[i] == 0)
                {
                    swap(v[i],v[f]); //to ensure if v[l] was 0 then it must be at v[f] and next 0s place must be updated by f++
                    f++;
                }
            }
            
        }


//EQUILLIBRIUM POINT
//https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
// {-7, 1, 5, 2, -4, 3, 0} :ans - 3
int equilibrium(int arr[], int n) 
{ 
	int sum = 0; 
	int leftsum = 0;  

	for (int i = 0; i < n; ++i) 
		sum += arr[i]; 

	for (int i = 0; i < n; ++i) 
	{ 
		sum -= arr[i]; // sum is now right sum for index i 

		if (leftsum == sum) 
			return i; 

		leftsum += arr[i]; 
	} 
	return -1; 
} 

// LEADERS IN ARRAY --WA???
// https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int currMax = INT_MIN;
        // 7 7 3
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i] >= currMax)
            {
                cout<<arr[i]<<" ";
                currMax = arr[i];
            }
            
        }
        cout<<endl;
    }
	return 0;
}

//*IMPORTANT : sweeping line algo(check it!)
//MIN NO. OF PLATFORMS needed st no train needs to wait -- discuss??? (question clarify)
//https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
// https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station-set-2-map-based-approach/
//arrival time:   0900  0940 0950  1100 1500 1800 (time format 0-24 hr, 0-59mn: HHMM)
//departure time: 0910 1200 1120 1130 1900 2000
// ans : 3

//when range of time is not very large then other method then this(see gfg) can be used
    vector<string> a(n); //arrival time
    vector<string> d(n); //departure time
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>d[i];
        
    sort(a.begin(), a.end());
    sort(d.begin(), d.end());
        
    int ans =1, platNeed = 1;
    int j =0,i=1;
    while(i<n && j<n)
    {
        if(a[i] <= d[j])
        {
            platNeed++;
            i++;
        }
        else 
        {
            platNeed--;
            j++;
        }
            
        if(platNeed>ans)
            ans = platNeed;
    }
    cout<<ans<<endl;


//TRAPPING RAIN WATER : T & S: O(n)
// https://practice.geeksforgeeks.org/problems/trapping-rain-water/0/
// 7 4 0 9 : ans 10
// 6 9 9   : ans 0
        int n; cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int>lmx(n); //to get maximum height at left of arr[i] in O(1)
        vector<int>rmx(n);////to get maximum height at right of arr[i] in O(1)
        int lm = -1, rm = -1;
        for(int i = n-1;i>=0;i--)
        {
            if(arr[i] > rm)
            {
                rm = arr[i];
            }
            rmx[i] = rm;
        }
        for(int i = 0;i<n;i++)
        {
            if(arr[i] > lm)
            {
                lm = arr[i];
            }
            lmx[i] = lm;
        }
        
        int ans = 0;
        for(int i =1;i<n-1;i++)
        {
            
            ans += (min(lmx[i],rmx[i]) - arr[i])>=0 ? (min(lmx[i],rmx[i]) - arr[i]) : 0;
        }
        cout<<ans<<endl;




//STOCK BUY AND SELL
// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0
// 100 180 260 310 40 535 695 :(0 3) (4 6)
// 100 50 30 20: No Profit
// 23 13 25 29 33 19 34 45 65 67 : (1 4) (5 9)
        vector<int>arr(n); //input array
        vector<pair<int,int>> res;
        
        int i=n-1; 
        while(i>0) 
        {
            int k = i;
            while(k>0 && arr[k] > arr[k-1])
                k--;
            if(k >= 0 && i!=k)
                res.push_back({k,i});
            if(k==0) break;
            i = k-1;
        }

        reverse(res.begin(), res.end()); //so as to get correct order of days as we started from end order stored is reversed
        if(res.size() == 0)
            cout<<"No Profit";
        else
        for(int i=0;i<res.size();i++)
            cout<<"("<<res[i].first<<" "<<res[i].second<<") ";
        cout<<endl;

// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array/0