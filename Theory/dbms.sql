-- https://www.studytonight.com/dbms/overview-of-dbms.php
--javatpoint->

-- MySQL is a database management system
-- -A database is a structured collection of data
-- (from a simple shopping list to a picture gallery or the vast amounts of information in a corporate network)
-- -To add, access, and process data stored in a computer database, 
-- you need a database management system such as MySQL Server



--entitity == table
--attribute == column & tuples == rows
--a+ => closure of (a)

FUNCTIONAL DEPENDENCIES
    The functional dependency is a relationship that exists between two attributes. It typically exists between the primary key and non-key attribute within a table.
    
    X   →   Y  
    
    The left(X) side of FD is known as a determinant, the right side(Y) of the production is known as a dependent.
    TYPES
        Trivial
            A → B has trivial functional dependency if B is a subset of A.
            The following dependencies are also trivial like: A → A, B → B
        Non Trivial 
            A → B has a non-trivial functional dependency if B is not a subset of A.
            When A intersection B is NULL, then A → B is called as complete non-trivial.



REDUNDENCY
-- https://www.geeksforgeeks.org/the-problem-of-redundancy-in-database/#:~:text=Redundancy%20means%20having%20multiple%20copies,%2C%20college%20rank%2C%20course%20opted.
    Redundancy means having multiple copies of same data in the database.
    This problem arises when a database is not normalized

Problems caused due to redundancy are: 
    Insertion anomaly: This problem happens when the insertion of a data record is not possible without adding some additional unrelated data to the record
    Deletion anomaly: This anomaly happens when deletion of a data record results in losing some unrelated information that was stored as part of the record that was deleted from a table
    Updation anomaly: Suppose if the rank of the college changes then changes will have to be all over the database which will be time-consuming and computationally costly.
                      If updation do not occur at all places then database will be in inconsistent state.



KEYS
    -It is(that value of attribute(ie columns)) used to uniquely identify any record or row of data from the table. It is also used to establish and identify relationships between tables.
    -closure(key) = R (ie entire relational table/ can say all the attributes are present in closure of key)
types
    SUPER KEY
        -The set of attributes which can uniquely identify a tuple is known as Super Key. For Example, STUD_NO, (STUD_NO, STUD_NAME) etc
        -A candidate key is a super key but vice versa is not true.
        -Adding zero or more attributes to candidate key generates super key.

    CANDIDATE
        -minimal super key or 
        -that super key whose proper subset is not a super key or
        -The minimal set of attribute(columns) which can uniquely identify a tuple(row) is known as candidate key. 
        eg
            R(abcd) : a,b,c,d are attributes of relational table
            given functional dependencies
            abc->d  => abc+ = abcd = R  : ie abc is a super key
            ab->cd  => ab+ = abcd = R : ie ab is also a super key
            a->bcd  => a+ = abcd = R : ie a is also a super key
            
            super key = {abc, ab, a}
            candidate key = a
            {as theres no proper subset of a which is a super key. 
            on the other hand if we consider 'abc' then its subset 'ab' and 'a' are also super keys }

        For Example, STUD_NO in STUDENT relation
        -The value of Candidate Key is unique and non-null for every tuple
        -There can be more than one candidate key in a relation
        -The candidate key can be simple (having only one attribute) or composite as well. For Example, {STUD_NO, COURSE_NO} is a composite candidate key for relation STUDENT_COURSE.    

    PRIMARY KEY
        -any one of the candidate key can be chosen as a primary key
        -ie There can be more than one candidate key in relation out of which one can be chosen as the primary key. 
        For Example, STUD_NO, as well as STUD_PHONE both, are candidate keys for relation STUDENT but STUD_NO can be chosen as the primary key (only one out of many candidate keys).
   
    
    FOREIGN KEY
        -A Foreign Key creates a link between tables. It references the primary key in another table and links it.

For example, the DeptID in the Employee table is a foreign key −
<Employee>
    EmpID       EmpName     EmpAge      DeptID

<Department>
    DeptID      DeptName    DeptZone

The DeptID in the Department table is a Primary Key in the Department Table.
The DeptID in the Employee table is a Foreign Key in the Employee Table.







-- https://www.javatpoint.com/dbms-first-normal-form
--prime attribute - tose attributes which are part of any of the candidate keys
--non prime attributes - other than prime
NORMALIZATION
    -Redundancy in relation may cause insertion, deletion and updation anomalies
     Normalization is the process of minimizing redundancy from a relation or set of relation
    -it is the process of organizing the data in the database by dividing the larger table into the smaller table and links them using relationship.
    -The normal form is used to reduce redundancy from the database table.
-- eg
--##imp- https://www.geeksforgeeks.org/normal-forms-in-dbms/#:~:text=Normalization%20is%20the%20process%20of,reduce%20redundancy%20in%20database%20tables.

different typs of Normal form->
    1NF:	
        A relation is in 1NF if it contains an atomic value, and it must follow INTEGRITY Constraints(like if attribute is defined integer than all values in that attribute must be integer)
        It states that an attribute of a table cannot hold multiple values. It must hold only single-valued attribute.
        First normal form disallows the multi-valued attribute, composite attribute, and their combinations.
        Example: Relation EMPLOYEE is not in 1NF because of multi-valued attribute EMP_PHONE
        --to make it in 1nf for multiple phn no, new rows are being made 

    2NF: must not hold => prime->non prime ie partial dep	
        eg (i) R(abcd)
        ab->d
        b->c
        => candidate key ={ab} => primary key = ab
        here, b->c {c(non prime attribute) is dependent on b(prime attribute(partial cuz ab is complete cand key))}
        -->this type of p->np (is np dependent partially on p) is k/as partial dependency. which is removed in 2nf form
        converting (i) it in 2nf -> by removing partial dependency
        --make separate table for partial dependent attributes and for complete cand key
        ab->d => table1 : R1(abd) (table1 must hold complete candidate keys )
        b->c => table2 : R2(bc)

        -A relation will be in 2NF if it is in 1NF and all non-key attributes are fully functional dependent on the primary key.
        -ie for a table to be in 2nf it must be -
        1. in 1nf
        2. there should not be any paritial dependency
                                        
    
    
    3NF: np->np, removes transitive dependencies(by making separate tables)
        A relation will be in 3NF if it is in 2NF and no transition dependency exists.
        a->b
        b->c : np->np
        c->d  
        
        tables -> ab, bc, cd 
        candidateKey- {a} 

        here b->d transitive dependency : here b is not a prime key but still its determining d => violation

        A relation is in 3NF if at least one of the following condition holds in every non-trivial function dependency X –> Y
            1. X is a super key.
            2. Y is a prime attribute (each element of Y is part of some candidate key).

	
    BCNF: prime ->prime
        -A relation R is in BCNF if R is in Third Normal Form and for every FD, LHS is super key
        -A relation is in BCNF iff in every non-trivial functional dependency X –> Y, X is a super key.

    4NF:	A relation will be in 4NF if it is in Boyce Codd normal form and has no multi-valued dependency.
    






SCHEMA
    -logical representation of db.

ER- Diagram
-- https://www.tutorialspoint.com/dbms/er_model_basic_concepts.htm
entity-(table name)
    An entity can be a real-world object, either animate or inanimate, that can be easily identifiable.
    For example, in a school database, students, teachers, classes, and courses offered can be considered as entities. 
    All these entities have some attributes or properties that give them their identity

attributes-(column name)
    -properties of entities
    - All attributes have values. 
    For example, a student entity may have name, class, and age as attributes.
    
    types-
    -simple- atomic (eg students phone number is an atomic value of 10 digits.)
    -composite- eg name(firstName,midName,lastName)
    -derived- (eg avg salary,age)
    -single valued - (eg social_security_no)
    -multivalued- (eg emailId, phnNo : one person can have more than one phn no or emailId)
    
Entity set & keys
    - entity set is  collection of similar types of entities

key -
    Key is an attribute or collection of attributes that uniquely identifies an entity among entity set.

    For example, the roll_number of a student makes him/her identifiable among students.
    Super Key − A set of attributes (one or more) that collectively identifies an entity in an entity set.
    Candidate Key − A minimal super key is called a candidate key. An entity set may have more than one candidate key.
    Primary Key − A primary key is one of the candidate keys chosen by the database designer to uniquely identify the entity set.


Relationship
    The association among entities is called a relationship. 
    For example, an employee works_at a department, a student enrolls in a course. Here, Works_at and Enrolls are called relationships.

Relationship Set
    A set of relationships of similar type is called a relationship set. Like entities, a relationship too can have attributes. These attributes are called descriptive attributes.

Degree of Relationship
    The "number of participating entities" in a relationship.
    -Binary = degree 2
    -Ternary = degree 3
    -n-ary = degree

Mapping Cardinalities
    -Cardinality defines the number of entities in one entity set, 
    which can be associated with the number of entities of other set via relationship set.
    types-
    -One to One(1:1)
    -one to many(1:N)
    -many to one (N:1)
    -many to many(N:N)

Participation Constraints
    Total Participation − Each entity is involved in the relationship. 
    Total participation is represented by double lines(=).

    Partial participation − Not all entities are involved in the relationship. 
    Partial participation is represented by single lines.




INDEXING
    -Indexing is a way to optimize the performance of a database by minimizing the number of disk accesses required when a query is processed.
    It is a data structure technique which is used to quickly locate and access the data in a database.

    -Indexing is a data structure technique to efficiently retrieve records from the database files 
    based on some attributes on which the indexing has been done.
    -Indexing in database systems is similar to what we see in books.


