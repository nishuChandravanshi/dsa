int Solution::largestRectangleArea(vector<int> &A) {
    
    int n=A.size();
    if(n==1) return A[0];
    
    stack<int>st;
    int maxAr=0;
    int areaWithTop=0;//ie area with st.top as the smallest bar
    
    int i=0;
    while(i<n){
        
        if(st.empty() or A[i]>A[st.top()])
            st.push(i++);
        else{
            int top=st.top();
            st.pop();
            
            //st.top will contain ind of left bar smaller than top and i is the right bar smaller than top
            areaWithTop=A[top]*(st.empty()?i:(i-st.top()-1));
            maxAr=max(maxAr,areaWithTop);
        }
    }
        while(!st.empty()){
            
            int top=st.top();
            st.pop();
            
            areaWithTop=A[top]*(st.empty()?i:(i-st.top()-1));
            maxAr=max(maxAr,areaWithTop);
        }
        
        return maxAr;
    }


