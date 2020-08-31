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

//IMPLEMENTATION

//USING LINKEDLIST : Insertion & Deletion in : O(1)
//insertion and deletion from the head always!
struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};
class MyStack {
  private:
    StackNode *top; //reference to StackNode 

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

void MyStack ::push(int x) {
    if(top == NULL)
        top = new StackNode(x);
    else 
    {
        StackNode* tp = new StackNode(x);
        tp->next = top;
        top = tp;
    }
}
int MyStack ::pop() {
    if(top == NULL)
        return -1;
    int t = top->data;
    top = top->next;
    return t;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}


//INFIX TO POSTFIX CONVERSION
//https://practice.geeksforgeeks.org/problems/infix-to-postfix/0
//infix-> a+b*(c^d-e)^(f+g*h)-i : postfix-> abcd^e-fgh*+^*+i-
int prec(char c)
{
    switch(c)
    {
        case '^':
            return 3;
        case '/':
            return 2;
        case '*':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
    
        default :
            return -1;
    }
}
int main() {
    int t; cin>>t;
    while(t--)
    {
        string s; cin>>s;
        int l = s.length();

        stack<char>st;
        string postfix ="";
        for(int i=0;i<l;i++)  // a+b*(c^d-e)^(f+g*h)-i
        {
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
                postfix += s[i];
            else if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                while(!st.empty() && st.top()!= '(')
                {
                    char c = st.top();
                    st.pop();
                    postfix +=c;
                }
                if(!st.empty() && st.top() == '(')
                    st.pop();
            }
            else 
            {   //a+b*(c^d-e)^(f+g*h)-i
                while(!st.empty() && prec(s[i])<=prec(st.top()))
                {
                    char c = st.top();
                    postfix += c;
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            postfix += st.top();
            st.pop();
        }        
        cout<<postfix<<endl;
    }
	return 0;
}


