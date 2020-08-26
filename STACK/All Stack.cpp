//SPECIAL STACK- 5 OPERATIONS IN O(1)
// https://practice.geeksforgeeks.org/problems/special-stack/1
stack<int> actual, aux;

void push(int a)
{
    actual.push(a);
    if(!aux.empty())
    {
        if(aux.top() < a)
            return;
        else aux.push(a);
    }
    else aux.push(a);
    
}

bool isFull(int n)
{
     if(actual.size() > n)
        return false;
        
    return true;
}

bool isEmpty()
{
    if(actual.empty())
        return true;
    
    return false;
}

int pop()
{   
    int t = actual.top();
    if(aux.top() == actual.top())
    {
        aux.pop();
        actual.pop();
    }
    else 
        actual.pop();
    
    return t;
    
}

int getMin()
{
    int t;
    if(!aux.empty())
        t= aux.top();

    return t; 
    
}

