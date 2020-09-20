/*
-- SQL - structured query language
-- MySql- open source SQL database manangement system
--https://dev.mysql.com/doc/refman/8.0/en/features.html


//
MySQL is a database management system
-A database is a structured collection of data
(from a simple shopping list to a picture gallery or the vast amounts of information in a corporate network)
-To add, access, and process data stored in a computer database, 
you need a database management system such as MySQL Server

MySQL databases are relational
-relational databases stores data in separate tables rather than putting all the data in one big storeroom.
- You set up rules governing the relationships between different data fields,
 such as one-to-one, one-to-many, unique, required or optional, 
 and “pointers” between different tables. The database enforces these rules, 
 so that with a well-designed database, your application 
 never sees inconsistent, duplicate, orphan, out-of-date, or missing data.
Open source

DDL : Data Definition Languagea
    Allows the specification of:
        -The schema for each relation, including attribute types.
        -Integrity constraints (ie not null,primary key)
        -Authorization information for each relation.
        -Non-standard SQL extensions also allow specification of
        -The set of indices to be maintained for each relations.
        -The physical storage structure of each relation on disk.

#primary key declaration on an attribute automatically ensures not null in SQL-92 onwards, needs to be explicitly stated in SQL-89


************************************************************

(keyword used to display)
database(use)->tables(show)->different columns(describe)


mysql -u root -p
pwd-
show databases;     {classmodels(sample db which i downloaded),mysql,etcetc}
use dbName;         {classmodels}
show tables;         {list the tables from above used database, cutomers,offices etc}
describe tableContent; {describe cutomers-> cutomer Name,id,no.,etc description of field & their types}
//tableContent- tc

select * from tc; {shows all details of selected tableContent}

select a,b from tc order by b (required column name by which we want to order lets say b here)

select a,b from tc order by b desc, c asc; (shows a,b in descending order of b and if same b then orders in ascending order of a)

select a from tc where creditLimit = 2323232; (where to specify condn)

select a from tc where creditLimit in (12232,1213,323) {in () refers as list of values(creditLimit here) passed in condn}


//select customerName from customers where creditLimit = 0 and customerName like 'A%'; 
//'A%'- selects all starting with A, 'A_bcs' => selects all customer named A_bcs with '_' can be replaced with any other char 

*/

-- #relation = table

-- ORDER OF EXECUTION
    SELECT DISTINCT column, AGG_FUNC(column_or_expression), …
    FROM mytable
    JOIN another_table
      ON mytable.column = another_table.column
    WHERE constraint_expression
    GROUP BY column
    HAVING constraint_expression
    ORDER BY column ASC/DESC
    LIMIT count OFFSET COUNT;


-- The select clause list the attributes desired in the result of a query
-- The where clause specifies conditions that the result must satisfy
-- The from clause lists the relations involved in the query


*************************************
-- Statments- to query data
--https://www.mysqltutorial.org/basic-mysql-tutorial.aspx

SELECT
    -stmt to query data from single table

*************************************
ORDER BY
    SELECT 
        select_list
    FROM 
        table_name
    ORDER BY 
        column1 [ASC|DESC], 
        column2 [ASC|DESC],

    --specify the one or more columns which you want to sort 
    --after the ORDER BY clause   ...;
    --by default order by sorts in ascending order
    
    --eg
    --1. ORDER BY clause to sort values in one column
    SELECT
        contactLastname,
        contactFirstname
    FROM
        customers
    ORDER BY
        contactLastname DESC,
        contactFirstname ASC;

    --here order by will sort result set in desc order of the last name,
    -- and then sorts(those with same order order last name) the sorted result in asc order of first name.

    --2. ORDER BY to sort a result set by an expression 
    SELECT 
        orderNumber,
        orderLineNumber,
        quantityOrdered * priceEach AS subtotal     --not necessary  to put AS (will work anyway)
    FROM
        orderdetails
    ORDER BY subtotal DESC;     --subtoal is used as alias of quantityOrdered*priceEach 
    
    --result set will contain three columns orderNumber, orderLineNumber and subtotal arranged in desc order by subtotal  

    --3. ORDER BY to sort data using a custom list
        --using FIELD() function
    SELECT 
        orderNumber, 
        status
    FROM
        orders
    ORDER BY 
        FIELD(status,
            'In Process', --specifying the order of status we want to print
            'On Hold',
            'Cancelled',
            'Resolved',
            'Disputed',
            'Shipped');

    --result list will contain orderNumber and status columns ordered by the status specified in field
    --FIELD(status, 'In Process', 'On Hold', 'Cancelled', 'Resolved', 'Disputed', 'Shipped');->
    --returns the index of the status in the list 'In Process', 'On Hold', 'Cancelled', 'Resolved', 'Disputed', 'Shipped'.
    --For example, if the status is In Process, the function will return 1. If the status is On Hold, the function will return 2, and so on.

--eg with group by clause
-- List the number of customers in each country, ordered by the country with the most customers first.
    SELECT 
        COUNT
        (CustomerID),
        Country
    FROM Customers
    GROUP BY Country
    ORDER BY 
        COUNT(CustomerID) DESC; --ordering by highest number of customers first


***********************

WHERE
--WHERE clause in the SELECT statement to filter rows from the result set
--operators that can be used to form expr in WHERE clause for specifying conditions->
-- =, OR, AND, >, <, <=,>=, <> or !=, IN, BETWEEN,LIKE
--(and ORDER BY can be used to specify order)
    SELECT 
        select_list
    FROM
        table_name
    WHERE
        search_condition;

    --eg
    --To check if a value is NULL or not, you use the IS NULL operator, not the equal operator (=).
    --The IS NULL operator returns TRUE if a value is NULL.
    --value IS NULL
    --1.
    SELECT 
        lastName, 
        firstName, 
        reportsTo
    FROM
        employees
    WHERE
        reportsTo IS NULL;

    --2.
    SELECT 
        firstName, 
        lastName, 
        officeCode
    FROM
        employees
    WHERE
        officeCode BETWEEN 1 AND 3
    ORDER BY officeCode;

    --3.
        SELECT 
        firstName, 
        lastName
    FROM
        employees
    WHERE
        lastName LIKE '%son' --return lastname ending with son
    ORDER BY firstName;
    
***********************************
/*
SQL includes a string-matching operator for comparisons on character strings.  
The operator “like” uses patterns that are described using two special characters:
    percent (%).  The % character matches any substring.
    underscore (_).  The _ character matches any character.

SQL supports a variety of string operations such as
    concatenation (using “||”)
    converting from upper to lower case (and vice versa)
    finding string length, extracting substrings, etc.

*/

LIKE
    --LIKE: operator used in a WHERE clause to search for a specific pattern in a column
    % (percent sign) is a wildcard character that represents zero, one, or multiple characters
    _ (underscore) is a wildcard character that represents a single character
    SELECT column_names FROM table_name WHERE column_name LIKE pattern;
    LIKE ‘a%’ (find any values that start with “a”)
    LIKE ‘%a’ (find any values that end with “a”)
    LIKE ‘%or%’ (find any values that have “or” in any position)
    LIKE ‘_r%’ (find any values that have “r” in the second position)
    LIKE ‘a_%_%’ (find any values that start with “a” and are at least 3 characters in length)
    LIKE ‘[a-c]%’ (find any values starting with “a”, “b”, or “c”
    NOT LIKE 'a%' (find those values which are not starting with 'a')
    --goodOne!!->s
    LIKE '[^acf]%' (first is NOT an "a" or a "c" or an "f")
        
        --eg Select all records where the first letter of the City is NOT an "a" or a "c" or an "f".
        SELECT * FROM Customers
        WHERE City LIKE '[^acf]%';



-- Select all records where the value of the City column does NOT start with the letter "a".
    SELECT * FROM Customers
    WHERE City NOT LIKE 'a%';

--Select all records where the first letter of the City is an "a" or a "c" or an "s".

    SELECT * FROM Customers
    WHERE City LIKE '[acs]%'; --(cities with 'a' or 'c' or 's' as starting char)


NOT 
    SELECT * FROM Customers
    WHERE NOT City= 'Berlin'; --> observe pos of NOT --?? shouldnt it be -> where city NOT LIKE 'Berlin'
-- this will return all details from customers table whose city is not berlin


LENGTH 
-- List the Enames those are having five characters in their Names.
    select ename from emp where length (ename) = 5

-- List the Enames those are starting with ‘S’ and with five characters.
    select ename from emp where ename like ‘S%’ and length (ename) = 5;


--#
-- #refere sqlquerieswithanswers pdf for tables

-- List the emps who are joined in the month of Aug 1980.
    select * from emp where hiredate between ’01-aug-80’ and ’31-aug-80’; 
    -- or->
    select * from emp where to_char(hiredate,’mon-yyyy’) ='aug-1980';

-- List the emps who joined in January.
    select * from emp where to_char (hiredate,’mon’) = ‘jan’;

--List all the emps who joined in the month of which second character is ‘a’.
    select * from emp where to_char(hiredate,’mon’) like ‘_a_’;
--or->
    select * from emp where to_char(hiredate,’mon’) like ‘_a%’ --depends on the format on which date is mentioned in table

-- List the emps whose Sal is four digit number ending with Zero.
    select * from emp where length (sal) = 4 and sal like ‘%0’;

-- List the emps who are working under ‘MGR’. #refere sqlquerieswithanswers pdf for tables
    select e.ename || ‘ works for ‘ || m.ename from emp e ,emp m where e.mgr = m.empno ;
--  or->
    select e.ename || ‘ has an employee ‘|| m.ename from emp e , emp m where e.empno = m.mgr;
-- || used for concatenation


**************************

SELECT DISTINCT
--When querying data from a table, you may get duplicate rows
--In order to remove these duplicate rows, you use the DISTINCT clause in the SELECT statement.
    
    SELECT DISTINCT
        select_list
    FROM
        table_name;
    
    --eg
    --1.
    SELECT 
        DISTINCT lastname
    FROM
        employees
    ORDER BY 
        lastname;


    --2. DISTINCT with multiple columns    
    --gives distinct combination of multiple colms
    --For example, to get a unique combination of city and state from the customers table,use the following query

    SELECT
        DISTINCT city, state
    FROM
        customers
    WHERE
        state IS NOT NULL
    ORDER BY
        state
    --withoud distinct result will contain duplicate combinations of city and state

    --3. DISTINCT and aggregate functions
    --You can use the DISTINCT clause with an aggregate function e.g., SUM, AVG, and COUNT,
    --to remove duplicate rows before the aggregate functions are applied to the result set.
    
    SELECT 
        COUNT(DISTINCT state)
    FROM
        customers
    --results count of distinct states, if distinct aint used then itll return total no of states in customers table


    --4. DISTINCT with LIMIT clause
    SELECT DISTINCT
        state
    FROM
        customers
    WHERE
        state IS NOT NULL
    LIMIT 5;
    --results five distinct state from customers
    --due to limit->mysql immediately stops searching when it reaches the no of rows set in limit

--Generally, the DISTINCT clause is a special case of the GROUP BY clause
--The difference between DISTINCT clause and GROUP BY clause is that the GROUP BY clause sorts the result set whereas the DISTINCT clause does not.


*************


AND
OR
IN

BETWEEN
-- select all the records where the value of the Price column is between 10 and 20
    SELECT * FROM Products
    WHERE Price 
    BETWEEN 10 AND 20;

-- to select all the records where the value of the Price column is NOT between 10 and 20.
    SELECT * FROM Products
    WHERE Price 
    NOT BETWEEN 10 AND 20; --NOT is used

LIMIT
IS NULL
*************************
Table & column alias
--AS keyword is optional so you can omit it
--The table aliases are often used in the statement that contains INNER JOIN, LEFT JOIN, RIGHT JOIN clauses and in subqueries.

--alia for columns->    
    SELECT 
        [column_1 | expression] AS descriptive_name
    FROM table_name;
--eg
--1.CONCAT_WS used to join  
    SELECT
        CONCAT_WS(', ', lastName, firstname) AS `Full name` --inorder to write space separated title(alias) use '', other wise not required
    FROM
        employees;
    --result will be list of firstName,lastName with table name  Full Name(if alias(here AS used ) wouldnt have been used then table name wd be -> concat)



--alias for tables->
    table_name AS table_alias


******************
JOIN
--A relational database consists of multiple related tables linking together
-- using common columns which are known as foreign key columns
--The join clause is used in the SELECT statement appeared after the FROM clause.

INNER JOIN --left intersecion right
--The inner join clause joins two tables based on a condition which is known as a join predicate.
--The inner join clause compares each row from the first table with every row from the second table.
-- If values in both rows cause the join condition evaluates to true, 
--the inner join clause creates a new row whose column contains all columns of the two rows from both tables and include this new row in the final result set. 
--=>the inner join clause includes only rows whose values match(as per the condition mentioned after ON)

    SELECT
        customerName,
        COUNT(o.orderNumber) total
    FROM
        customers c
    INNER JOIN orders o ON c.customerNumber = o.customerNumber 
    --same as- inner join  orders o USING (customerName)
    GROUP BY
        customerName
    ORDER BY
        total DESC;
--The query above selects customer name and the number of orders from the customers and orders tables

LEFT JOIN --all rows of left column with NULL on right column rows whose values are not present
--if the values in the two rows are not matched,
--the left join clause still creates a new row whose columns contain columns of the row in the left table and NULL for columns of the row in the right table.
--left join selects data starting from the left table. For each row in the left table, the left join compares with every row in the right table->
--If the values in the two rows cause the join condition evaluates to true, the left join creates a new row whose columns contain all columns of the rows in both tables and includes this row in the result set.
 
    SELECT column_list 
    FROM table_1 
    LEFT JOIN table_2 USING (column_name);


RIGHT JOIN
Self Join
CROSS JOIN


****************************
GROUP BY
--aggregate_functions -
--used after the FROM, WHERE and SELECT clauses and before the HAVING , ORDER BY and LIMIT clauses
    SELECT 
        c1, c2,..., cn, aggregate_function(ci)
    FROM
        table
    WHERE
        where_conditions
    GROUP BY c1 , c2,...,cn;

--The aggregate functions allow you to perform the calculation of a set of rows and return a single value. 
--The GROUP BY clause is often used with an aggregate function to perform calculation and return a single value for each subgroup.
    --eg1.
    SELECT 
        status, COUNT(*)
    FROM
        orders
    GROUP BY status;
    --return number of orders in each status corresponding to status

    --2.to get the total amount of all orders by status,join the orders table with the orderdetails table and use the SUM function to calculate the total amount.
    SELECT 
        status,
        SUM(quantityOrdered*priceEach)
    FROM
        orders
    INNER JOIN
        orderdetails 
    USING (orderNumber)
    GROUP BY status;
    

    --3.GROUP BY with expression
    SELECT 
        YEAR(orderDate) AS year,
        SUM(quantityOrdered * priceEach) AS total
    FROM
        orders
    INNER JOIN orderdetails 
        USING (orderNumber)
    WHERE
        status = 'Shipped'
    GROUP BY 
        YEAR(orderDate) -- must have same expr as in select 
    HAVING
        year >=3 --use of HAVE clause!!, will print those with yr>=3



*****************************
HAVING
    SELECT 
        select_list
    FROM 
        table_name
    WHERE 
        search_condition
    GROUP BY 
        group_by_expression
    HAVING 
        group_condition;

--The HAVING clause constraints are written the same way as the WHERE clause constraints, and are applied to the grouped rows
--If you aren't using the `GROUP BY` clause, a simple `WHERE` clause will suffice.
--HAVING clause is only useful when you use it with the GROUP BY clause-
-- to generate the output of the high-level reports. for eg, you can use the HAVING clause to answer questions like finding the number orders this month, this quarter, 
--or this year that have total sales greater than 10K.
--*but having clause can be used without group by clause as wee=ll, as with aggregate functions
--If we use a HAVING clause without a GROUP BY clause, the HAVING condition applies to all rows that satisfy the search condition
-- In other words, all rows that satisfy the search condition make up a single group.



*****************************
ROLLUP
*****************************
Subquery
--subquery is called an inner query while the query that contains the subquery is called an outer query
-- subquery can be used anywhere that expression is used and must be closed in parentheses


    -- eg1.
    --following query returns employees who work in offices located in the USA
    SELECT 
        lastName, firstName
    FROM
        employees
    WHERE
        officeCode IN (SELECT 
                            officeCode
                        FROM
                            offices
                        WHERE
                            country = 'USA'); --AS usaOfficeCode; --usaOfficeCode => officeCodes which corresponds to USAs
                                    --?? error while using alia usaOfficeCode for table. How to name tables??

    -- 2. customers whose payments are greater than the average payment using a subquery
    SELECT 
        customerNumber, 
        checkNumber, 
        amount
    FROM
        payments
    WHERE
        amount > (SELECT 
                AVG(amount)
            FROM
                payments);
-- ?? whats error in below code --> AVG(amount) has no significance, amount must be described FROM which table it is belonging to, and select return the avg amount. so only avg(amt), has no significance
    SELECT 
        customerNumber, 
        amount
    FROM
        payments
    WHERE 
        customerNumber IN (SELECT customerNumber FROM payments WHERE amount > AVG(amount)); -- avg cant be used with comperator?


***********************************
ALL & ANY
--The ANY operator returns true if any of the subquery values meet the condition.
--The ALL operator returns true if all of the subquery values meet the condition.

--eg
    Table A
    Id   Name    Age
    ----------------
    12   Arun    60
    15   Shreya  24
    99   Rohit   11

    Table B
    Id   Name   Age
    ----------------
    15   Shreya  24
    25   Hari    40
    98   Rohit   20
    99   Rohit   11


    SELECT A.id 
    FROM   A 
    WHERE  A.age > ALL (SELECT B.age 
                        FROM   B 
                        WHERE  B. name = "arun") 
-- return all id's in A
--The meaning of “ALL” is the A.Age should be greater than all the values returned by the subquery. 
--There is no entry with name “arun” in table B. So the subquery will return NULL. If a subquery returns NULL, then the condition becomes true for all rows of A (See this for details). So all rows of table A are selected

******************************
Derived Tables
EXISTS


************************************
/*
SET OPERATIONS
    The set operations union, intersect, and except operate on relations and correspond to the relational algebra operations 
    #Each of the above operations automatically eliminates duplicates; 
    to retain all duplicates use the corresponding multiset versions union all, intersect all and except all.
        -suppose a tuple occurs m times in r and n times in s, then, it occurs:
            m  + n times in r union all s
            min(m,n) times in r intersect all s
            max(0, m – n) times in r except all s
*/

UNION
--on same type of data like -> same attributes

-- Find all customers who have a loan, an account, or both:
    (select customer_name from depositor)
    union
    (select customer_name from borrower)

INTERSECT
--   Find all customers who have both a loan and an account.
    (select customer_name from depositor)
    intersect
    (select customer_name from borrower)

EXCEPT
--   Find all customers who have an account but no loan.	
    (select customer_name from depositor)
    except
    (select customer_name from borrower)


MINUS

AGGREGATE FUNCTION
-- These functions operate on the multiset of values of a column of a relation, and return a value
	avg -- average value
	min -- minimum value
	max --  maximum value
	sum -- sum of values
	count --  number of values

AVG
--Find the average account balance at the Perryridge branch.
    select avg (balance)
	from account
	where branch_name = 'Perryridge' 

COUNT 
--Find the number of tuples in the customer relation.
    select count (*)
	from customer

-- Find the number of depositors in the bank.
    select count (distinct customer_name)
	from depositor


-- Q. Find the names of all branches where the average account balance is more than $1,200.
        select branch_name, avg (balance)
        from account
        group by branch_name
        having avg (balance) > 1200

-- Note:  predicates in the having clause are applied after the 
--     formation of groups whereas predicates in the where 
--     clause are applied before forming groups


********************************
INSERT
    
    INSERT INTO -->
        Customers -- table name
        (           --attributes
        CustomerName, 
        Address, 
        City, 
        PostalCode,
        Country
        )
    VALUES --> values to be inserted
        (
        'Hekkan Burger',
        'Gateveien 15',
        'Sandnes',
        '4306',
        'Norway'
        )
        ;

Insert Data Only in Specified Columns
-- It is also possible to only insert data in specific columns.
-- The following SQL statement will insert a new record, but only insert data in the "CustomerName", "City", and "Country" columns (CustomerID will be updated automatically):
    INSERT INTO Customers (CustomerName, City, Country)
    VALUES ('Cardinal', 'Stavanger', 'Norway');

-- after this the columns in which ntg has been inserted will be null, but customer id will be autmatically updated
--as customerID ==> auto increment field

Insert Multiple Rows
INSERT INTO SELECT
Insert On Duplicate Key Update
INSERT IGNORE

*******************************
--Be careful when updating records. If you omit the WHERE clause, ALL records will be updated!
UPDATE
    UPDATE table_name
    SET column1 = value1, column2 = value2, ...
    WHERE condition;

--eg
-- Set the value of the City columns to 'Oslo', but only the ones where the Country column has the value "Norway".
    UPDATE
        Customers
    SET
        City = 'Oslo'
    WHERE               --without where all the cities will be changed to oslo
        Country = 'Norway';

UPDATE JOIN


********************************
--The DELETE statement is used to delete existing records in a table
-- DROP and TRUNCATE : DDL commands,(data definition command)
--whereas DELETE : DML command (data manipulation command)
-- DELETE operations can be rolled back (undone), while DROP and TRUNCATE operations cannot be rolled back

DELETE
    DELETE FROM mytable
    WHERE condition;          

--Delete All Records
-- It is possible to delete all rows in a table without deleting the table. 
-- This means that the table structure, attributes, and indexes will be intact(undamaged):

    DELETE FROM table_name;
--eg
    DELETE FROM Customers;
--this deletes all all rows in the customers tables without deleting the table

DELETE JOIN
ON DELETE CASCADE


********************************
REPLACE
Report Ad
MYSQL DATA DEFINITION
Selecting Database

*******************************
CREATE DATABASE
    CREATE TABLE IF NOT EXISTS mytable (
    column DataType TableConstraint DEFAULT default_value,
    another_column DataType TableConstraint DEFAULT default_value,
    …
    );
--eg     Movies table schema
    CREATE TABLE movies (
        id INTEGER PRIMARY KEY,
        title TEXT,
        director TEXT,
        year INTEGER, 
        length_minutes INTEGER
    );

***********************
DROP DATABASE
--sql statement to create a db named testDB
    CREATE DATABASE testDB
-- Write the correct SQL statement to delete a database named testDB.
    DROP DATABASE testDB;


***********************
Managing Databases
Storage Engines
Data Types
CREATE TABLE
Primary Key
Foreign Key
UNIQUE Constraint
CHECK Constraint
NOT NULL
Sequence

****************************
ALTER TABLE
--Altering table to add new column(s)
    ALTER TABLE mytable
        ADD column DataType OptionalTableConstraint 
        DEFAULT default_value;


RENAME TABLE    
--Altering table name
    ALTER TABLE mytable
        RENAME TO new_table_name;

--Altering table to remove column(s)
    ALTER TABLE mytable
        DROP column_to_be_deleted;


ADD COLUMN
-- Add a column of type DATE called Birthday.
    ALTER TABLE 
        Persons --table name : Persons 
    ADD 
        Birthday DATE; --date: type, column created Birthday


DROP COLUMN
    -- Delete the column Birthday from the Persons table
    ALTER TABLE 
        Persons
    DROP COLUMN
        Birthday;
    

*************************************
DROP TABLE --ddl cmd, cant be rolled back ones deleted using drop cmd
    --To remove an entire table including all of its data and metadata, 
    --and to do so, you can use the DROP TABLE statement, 
    --which differs from the DELETE statement in that it also removes the table schema from the database entirely.
    DROP TABLE IF EXISTS mytable;

**************************************
Temporary Tables
TRUNCATE TABLE

Report Ad
MYSQL DATA TYPES
BIT
BOOLEAN
CHAR
DATE
DATETIME
DECIMAL
ENUM
INT
JSON
TIME
TIMESTAMP
VARCHAR
MYSQL GLOBALIZATION
MySQL Character Set
MySQL Collation
