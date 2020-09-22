    OOPS - Object Oriented Programming System

INTRO::
Oops-
-Object oriented programming system in which programs are treated
as a collection of objs.  
-it is the technique to write programs based on real world objects.
The states and behaviors of an obj are representd as the member variables 
and methods. 
-in oops programming programs are organized around objects and data
rather than actions and logics.

## C, PASCAL- STRUCTURED PROGRAMMING LANG.
## FORTRAN,COBOL - PROCEDURAL PROGRAMMING LANG
//
advantages-
-simplicity : as obj model real world objs,complexity reduced and clear prog structure
??-modularity : 
-modifiability : easy to make minor changes, changees inside class do not affect any other part of prog,since
the only public interfase that the external world has to a class is through the use of methods.
-extensibility : adding new features easily 
-maintainability : objs maintained separately->locating and fixinf problems easier
-reusability : same objs can be reused in diff programs


//
Difference btw Procedural programming and Oops
-procedural prog is based on functions, whilie oops based on real world objs
??-proce language gives imp on the seq of func execution 
but oo lang gives imp on states and behaviors of the objects
-proc exposes data to the entire prog, but OO lang encapsulates the data
??-proc follow TOP-DOWN paradigm, OO lang follows BOTTOM-UP
-less scope of code reuse in proc
-proc is complext in nature =>difficult to modify,extend and maintains

## runtime entities- ??discuss-
-things that exist only during prog execution somewhere in mem. they have
no life outside prog exec
-structures,objects basic types etc in c 

//In C++ all the uninitialized global variables are initialized to 0.
int x[100];
int main()
{
    cout << x[99] << endl;
}
// op- 0
*******

//object-
-entity that has state(data) and behavior(functionality) (eg. chair,pen,bike,keyboard etc)
-runtime entity (as it is assigned memory dynamically during runtime, although class is compiled during compile time)
-Creating obj-> of student class using s1 referenve variable

    Student s1; //Student is the type and s1 is the reference that refers to the instance of Student class
    


//class-
-collection of object
-a template from which objs are created
-can have fields, methods,constructors etc

    class Student
    {
        private:

        public:
        int id; //field / data member / instance variable
        float salary;
        string name; 
    };


//eg.
//Student class with 2 fields, creates instance of class, initializes obj and print obj val

    class Student{
        public:
            int id;
            string name;
    } 

    int main()
    {
        Student s1;
        s1.id = 1;
        s1.name = "nishu";

        cout<<s1.id<<" "<<s1.name<<endl;
        return 0;
    }


//initialize and display data through method
    class Student
    {
        public:
            int id;
            string name;
        
        void insert(int i, string n)
        {
            id = i;
            name = n;
        }

        void display()
        {
            cout<<id<<" "<<name<<endl;
        }

    };
    int main()
    {
        Student s1,s2;
        s1.insert(1,"nish");
        s2.insert(2,"roos");

        s1.display();
        s2.display();

        return 0;
    }

//Employee class
    class Employee
    {
        public:
            int id; 
            string name;
            float salary;
        
        void insert(int i, string s, float sal)
        {
            id = i; 
            name = s;
            salary = sal;
        }
        
        void display()
        {
            cout<<id<<" "<<name<<" "<<salary<<endl;
        }
    };
    int main()
    {
        Employee e1;
        e1.insert(1,"nish",1200000);
        e1.display();
        return 0;
    }


//constructor-
-special method(name same as class ) which is invoked automatically at the time of obj creation
-generally used to initialize data members of new object
-malloc doesnt call contructor, while new does!
*shallow copy :obj1=obj2 => obj2 will point to location of obj1
*deep copy :obj1=obj2 => obj2 will point to other memory location with obj1's values copied.


//1.Default constructor
-has no arguments, invoked at the time of creating obj

    class Employee
    {
        public:
            Employee()
            {
                cout<<"object created: default constructor invoked\n";
            }
    }
    int main()
    {
        Employee e1; //?? will this obj be assigned memory now?
        Employee e2;
        return 0;
    }
    //op- object created: default constructor invoked
    //    object created: default constructor invoked


// 2. Parameterized constructor
-constructors which has parameters
-param passed when obj is created- generally to initialize the data members of obj
    class Employee
    {
        public:
            int id;
            string name; 
            float salary;
        
        Employee(int i, string s, float sal)   //paramzd constrctr
        {
            id = i;
            name = s;
            salary = sal;
        }

        void display()
        {
            cout<<i<<" "<<name<<" "<<salary<<endl;
        }
    };
    int main()
    {
        Employee e1(1,"nish",5000000);
        Employee e1(2,"roos",5000000);

        e1.display();
        e2.display();
        return 0;
    }
    // op- 1,"nish",5000000
    //     2,"roos",5000000

//3.copy constructor
// imp--> 'const and &(ie arg passed by constant reference)' used while defining copy constructor.
 --ClassName (const ClassName &old_obj);

--# default contructor is by default called(by constructor) if no other costructor is declared exclusively in class,
else if any of the constructor is declared(either parameterized or copy) then default constructor is not called by the compiler.
--#copy constructor is by default created, even when we've exclusively  declared any other contructor
//eg 1
class Point
{
    int x, y;
public:
   Point(const Point &p) { x = p.x; y = p.y; } //copy constructor:exclusively declared
   int getX() { return x; }
   int getY() { return y; }
};
 
int main()
{
    Point p1; //error
    Point p2 = p1; //copy constructor called
    cout << "x = " << p2.getX() << " y = " << p2.getY();
    return 0;
}
// op: compiler error
// -There is compiler error in line "Point p1;".
// The class Point doesn't have a constructor without any parameter. 
// If we write any constructor, then compiler doesn't create the default constructor. 
// It is not true other way, i.e., if we write a default or parameterized constructor, then compiler creates a copy constructor. see below eg

//eg 2
class Point
{
    int x, y;
public:
   Point(int i = 0, int j = 0) { x = i; y = j; } //here we've default arguments(i==0,j==0)=> if no args passed(then will act similar to default contr) then obj will be initialized by default i=0,j=0 
   int getX() { return x; }
   int getY() { return y; }
};
 
int main()
{
    Point p1;
    Point p2 = p1;
    cout << "x = " << p2.getX() << " y = " << p2.getY();
    return 0;
}
//op: x=0,y=0
// --Compiler creates a copy constructor if we don't write our own.
// Compiler writes it even if we have written other constructors in class. 
// So the above program works fine. Since we have default arguments, the values assigned to x and y are 0 and 0.


//Destructor
-works oppo to constructor
-destructs the obj of class(when func terminates ie ends)
-can be defined only once in a class
-invoked automatically
-cant have parameters, modifiers cant be applied on destructors

    class Employee
    {
        public:
            Employee()
            {
                cout<<"def const\n";
            }
            ~Employee() //destructor
            {
                cout<<"destructor invoked\n";
            }
    };
    int man()
    {
        Employee e1,e2;
        return 0;
    }
    // op- def const
    //     def const
    //     destructor invoked
    //     destructor invoked
    

//REFERENCES

// eg 1
int &fun()
{
    static int x = 10; //observe #static used. 
    return x;
}
int main()
{
    fun() = 30; //here fun()->returned the reference of x. (ie fun is basically refering to a memory location and (=30) is the value assigned at that location)
    cout << fun();
    return 0;
}
// op - 30
// When a function returns by reference, it can be used as lvalue. Since x is a static variable,
//  it is shared among function calls and the initialization line "static int x = 10;" is executed only once. 
//  The function call fun() = 30, modifies x to 30.
//  The next call "cout << fun()" returns the modified value.
// ##L-value: l-value "refers to memory location" which identifies an object. l-value may appear as either left hand or right hand side of an assignment operator(=)
//  l-value often represents as identifier

//eg 2
int &fun()
{
    int x = 10; //## static not used => x is local variable ie x is pointing to local (func scoped) memo => as soon as func terminates there aint any existence of x=> so refering it (=30) will lead to runtime error
    return x;
}
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}
//op - runtime error
// Since we return reference to a local variable, 
// the memory location becomes invalid after function call is over. 
// Hence it may result in segmentation fault runtime error.




//STATIC 
-static is a keyword or modifier that belongs to the type(ie class) not instance(ie obj)
-instance(obj) not required to access the static members
-static can be field, method, constructor, class, properties, operator and event.
-memory efficient
-all static data initialized to ZERO when the first obj is created

-used to refer the commom properties of all objects such as -
-rateOfInterest in case of Account, companyName in case of Employee

// eg. Counting objects
    class Account
    {
        public:
            int accno;
            string name;

            static float rateOfInterest;
            static int count;   

        Account(int accno, string name)
        {
            this->accno = accno;
            this->name = name;
            count ++;
        }

        void display()
        {
            cout<<accno<<" "<<name<<" "<<rateOfInterest<<"\n";
        }
    };

    float Account:: rateOfInterest = 5.5; //static data member
    int main()
    {
        Account a1(100,"ab");
        Account a2(101,"bc");
        Account a3(102,"cd");
        
        a1.display();    
        a2.display();    
        a3.display();    
   
        cout<<"Total Objects are: "<<Account::count; 
        return 0;
    }

    // op- 
    // 100 ab
    // 101 bc
    // 102 cd
    // Total Objects are: 3




//this pointer
-this is a keyword that refers to the current instance of the class
- used to 
    pass current object as a parameter to another method.
    refer current class instance variable.
    declare indexers.

    class Employee
    {
        public:
            int id;
            string name; 
            float salary;
        
        Employee(int id, string name, float salary)   //paramzd constrctr
        {
            this->id = i;
            this->name = s;
            this->salary = sal;
        }

        void display()
        {
            cout<<i<<" "<<name<<" "<<salary<<endl;
        }
    };


//UNION
union A {
  int a;
  int b;
  A() { a = 10; }
  int getb() {return b;}
};
int main()
{
    A obj;
    cout << obj.getb();
    return 0;
}
// op- 10
// Like struct and class, union can have methods.
// Like struct and unlike class, members of union are public by default. 
// Since data members of union share memory, the value of b becomes same as a.


//Structs ??
-default access specifier- public
-default access specifie in class - private
//Enumeration ?



//Friend Fucntion (ff) ??benefits & uses?

-friend keyword used to define
-A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. 
Even though the prototypes for friend functions appear in the class definition, friends are not member functions.
- the protected and private data of a class
 can be accessed using the friend function.
-declaration should be inside body of class, starting with friend keyword
-can be declared either in private or public part
   
    Class className
    {
        friend dataType funcName(args); //ff syntax
    };

-not in scope of class to which it has been deeclared
    =>can not be called using objs
-can be invoked like normal func without using obj
-cannot access the member names directly
,has to use obj name and dot membership operator with the member name

eg-

    class Box
    {
        private: 
            int length;
            int width;
        public:
            Box(int length,int width)
            {
                this->length = length;
                this->width = width;
            }

        friend int Area(Box); //as cant ff cant access member name directly and uses obj name (so obj passed as arg)

    };

    int Area(Box b)
    {
        return b.length * b.width;
    }

    int main()
    {
        Box b(4,5);
        cout<<Area(b)<<endl;
    }
    //op - 20

//func friendly to two classes

    class A;
    class B
    {
        int val;
        friend int min(A,B); //can be declared in private also
       
        public:
            B(int v)
            {
                val = v;
            }
        
    };
    class A
    {
        int val;
        public:
            A(int v)
            {
                val = v;
            }
            friend int min(A,B);
    };

    int min(A a, B b)
    {
        return a.val < b.val ? a.val : b.val;
    }

    int main()
    {
        A a(2);
        B b(3);

        cout<<min(a,b)<<endl;
        return 0;
    }


//Friend Class
-a friend class can access both private and protected members 
of the class in which it has been declared as friend.

    class A
    {
        int x = 2;
        friend class B; //now class B can access all private and protected members of class A        
    };
    class B
    {
        public:
            display(A &a)
            {
                cout<<"val of x: "a.x<<endl;
            }
    };
    int main()
    {
        A a; B b;
        b.display(a);
        return 0;
    }
    //op- 2



*************************************************************************************************************************************************************************
CONCEPTS ::

// 1.Inheritance
-one obj acquires all the properties and behaviours of parent obj
-provides code reusability
-?? used to achieve runtime polymorphism

-class which inherits members of others- derived class
-class whose members are inherited - base class

## the private members of the base class are never inherited.

adv-
-code reusability: can reuse the  members of parent class=>no need to define member again

-derived class Syntax

    class derivedClassName :: visibility-mode baseClassName
    {



        //derived class body
    }

## visibility mode: specifies whether the features of the base class are publicly inherited or privately inherited.


types-
// Single Level Inheritance
    A->B :(base->derived)

   class A {  
        public:  
            float salary = 60000;

        void display()
    	{
    		cout<<"salary: "<<salary<<endl;
    	}   
    };  
    
   class B: public A //inheriting class A, =>B is derived class
   {  
         public:  
        	float bonus;
        
        B(float b, float a)
        {
        	bonus = b;
        	salary = a; //as B can access members of A
        }   
   };       
int main() {  
    B p1(4444,5555);    //field inheritence
    cout<<"Salary: "<<p1.salary<<endl;    
    cout<<"Bonus: "<<p1.bonus<<endl;    
    
    p1.display(); //called inherited method display
    return 0;  
}  
// op
// alary: 60000
// Bonus: 5000
// salary: 777

## private members are non-inheritable
-third visibility modifier, i.e., protected. 
The member which is declared as protected will be accessible
to all the member functions within the class as well as the class immediately derived from it


// multi level Inheritence
class D : visibility B-1, visibility B-2, ?  
{  
    // Body of the class;  
}   


//Aggregation -> has  a relation ship
//one class has objects of other class as its members

class Employee    
    {    
        private:  
        Address* address;  //Employee HAS-A Address   
        public:  
        int id;    
        string name;    
        Employee(int id, string name, Address* address)    
       {    
           this->id = id;    
           this->name = name;    
           this->address = address;    
       }    
     void display()    
       {    
           cout<<id <<" "<<name<< " "<<     
             address->addressLine<< " "<< address->city<< " "<<address->state<<endl;    
       }    
   };   
int main(void) {  
    Address a1= Address("C-146, Sec-15","Noida","UP");    
    Employee e1 = Employee(101,"Nakul",&a1);     //creating object with reference
            e1.display();   
   return 0;  
}  


//virtual void function & runtime polymorphism
#include<iostream>
using namespace std;
class B {
   public:
      virtual void s() = 0; // Pure Virtual Function
      //if we don't do =0 then we need to write funcn body
      //if a class has atleast 1 pure virtual func  it becomes an abstract class
      //abstract class -> no object only ptr is used 
};

class D:public B {
   public:
      void s() {
         cout << "Virtual Function in Derived class\n";
      }
};

int main() {
   B *b;
   D dobj;
   b = &dobj;
   b->s();
}


//compile time poly.. -> funcn overloading , operator overloading
//funcn overloading ->e.g constructor types, any function different parameter inputs
//fucnn overloading can have different return types 
//but it must have diff input args


//operator overloading

//operators that can't be overloaded
// Scope operator (::)
// Sizeof
// member selector(.)
// member pointer selector(*)
// ternary operator(?:)


#include <iostream>  
using namespace std;  
class A  
{  
    
    int x;  
      public:  
        A(){}  

    A(int i)  
    {  
       x=i;  
    }  
    void operator+(A);  
    void display();  
};  
  
void A :: operator+(A a)  
{  
     
    int m = x+a.x;  
    cout<<"The result of the addition of two objects is : "<<m;  
  
} 

int main()  
{  
    A a1(5);  
    A a2(4);  
    a1+a2;  
    return 0;  
}  


********
//

2.Abstraction -
3.Encapsulation -
4.Polymorphism -
4.Inheritance -
5.Composition
6.Association
7.Aggregation -

-

****************************************************************************************************************

// 4 5 palindorme even length ->nth return

// 1st->44
// 2->55
// 3->4444
// 4->4554
// 5->5445
// 5->5555
// 6->444444
// 445, 454, 455, 544, 545, 555

2, 4, 8, 16, 
2, 6, 7th 14, 30, ....
1

_ _ _|_ _ _

vector<string>s;
void generate(string s1, int n) {
    if(n==0)
        s.push_back(s1);
    
    generate(s1+'4', n-1);
    generate(s1+'5', n-1);
}

generate('', n);
sort(s.begin(), s.end());
return s[diff]+reverse 


//PROJECT
#model -> database schema
#views-> we write the api or fucn
#url wwhere map urlpattern wrt views

sms api->msg91

class Person(models.model):
    name = models.charfield(max_lenght=30)
    contact = models.charField...

def getPerson(request):
    persons = Person.objects.all()
    return JsonResponse({'success':True, 'data':persons})

urlpatterns = [
    url('getPerson/', views.getPerson)
]

cyberbullying-> tweets from twitter for a given subject 
tweepy with twitter api ->messages

ml model run -> 5 classes ->good, bad, threat

web dashboard->threat, abusive % of tweets bad

model-> some classifier

every 5 min me update


******************************



