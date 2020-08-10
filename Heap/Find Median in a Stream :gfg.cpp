#include <bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
int main() {
    int n; cin>>n;
    
    //max-heap
    priority_queue<double> leftHalf;
    //min-heap
    priority_queue<double, vector<double>, greater<double>> rightHalf;
    
    double prevMed = 0;
    double currMed;
    for(int i = 0; i < n; i++)
    {
        int newElement; cin>>newElement;
        
        if(leftHalf.size() > rightHalf.size())
        {
            if(newElement > prevMed)
                rightHalf.push(newElement);
            else    //newElement will go in left half which is already larger in size => max of left is shifted into right and newElement is added into left inorder to balance both halves
            {
                rightHalf.push(leftHalf.top());
                leftHalf.pop();
                leftHalf.push(newElement);
            }
            
            currMed = floor((leftHalf.top() + rightHalf.top())/2);
        }
        else if(rightHalf.size() > leftHalf.size())
        {
            if(newElement < prevMed)
                leftHalf.push(newElement);
            else
            {
                leftHalf.push(rightHalf.top());
                rightHalf.pop();
                rightHalf.push(newElement);
            }
            
            currMed = floor((leftHalf.top() + rightHalf.top())/2);
        }
        else
        {
            if(newElement < prevMed)
            {
                leftHalf.push(newElement);
                currMed = leftHalf.top();
            }
            else{
                rightHalf.push(newElement);
                currMed = rightHalf.top();
            }
        }
        
        cout<<currMed<<endl;
        prevMed = currMed;
    }
    
	return 0;
}

/*
    T: O(nlogn), S: O(n)
    
ip- 5 15 1 4
op- 5 10 5 4
idea-
-as median means the middle val of the sorted elements
so the idea is to maintain rigth and left halves of the stream and get median 
-max-heap to store left half and min-heap to store right half (initialize med = 0)

-For every newly read element, insert it into either max heap or min-heap and calculate the median based on the following conditions:
    - if maxheap.size < minheap.size {=> after adding new element size of both heaps must be equal and med = avg of top of both heaps(as this condn=>even no. of elements)}
        if newElement > prev median {=> new element will go in right half(min-heap) and as its size is already more than max heap=>}
            pop top of min-heap(as its val will be less than or atmost equal to new element, since we know new element is > prev med)
            and insert it into max heap, and insert new element into min-heap
        else 
            insert new element in maxheap
        new median = avg of both heap's top
        
    -else if maxheap.size > minheap.size 
        if newElement > prev median {=> newElement will go in right half}
            insert newElement into minheap
        else                        {=> newElement is smaller than med and so it'll be atmost equal to top of lefthalf}
            pop top of maxheap, push it into meanheap
            insert newelement into maxheap
        new median = avg of both heap's top
    -else {same size => new element will make size of stream odd=> mid of the stream will be media}
        if newElement > prev median
            insert it into minheap(right half)
            med = top of minheap
        else insert it into maxheap
            med = top of maxheap
    
*/
