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


*************************************
-- Statments- to query data
--https://www.mysqltutorial.org/basic-mysql-tutorial.aspx

SELECT
    -stmt to query data from single table

*******
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

******************

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


*************

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
LIKE
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
-- ????????? whats error in below code
    SELECT 
        customerNumber, 
        amount
    FROM
        payments
    WHERE
        customerNumber IN (SELECT customerNumber FROM payments WHERE amount > AVG(amount)); -- avg cant be used with comperator?


******************************
Derived Tables
EXISTS
UNION
MINUS
INTERSECT
INSERT
Insert Multiple Rows
INSERT INTO SELECT
Insert On Duplicate Key Update
INSERT IGNORE

UPDATE


UPDATE JOIN

DELETE
    DELETE FROM mytable
    WHERE condition;          

DELETE JOIN
ON DELETE CASCADE
REPLACE
Report Ad
MYSQL DATA DEFINITION
Selecting Database

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

DROP DATABASE
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

ALTER TABLE
--Altering table to add new column(s)
    ALTER TABLE mytable
        ADD column DataType OptionalTableConstraint 
        DEFAULT default_value;
        
--Altering table name
    ALTER TABLE mytable
        RENAME TO new_table_name;
--Altering table to remove column(s)
    ALTER TABLE mytable
        DROP column_to_be_deleted;


ADD COLUMN
DROP COLUMN
RENAME TABLE

DROP TABLE
    --o remove an entire table including all of its data and metadata, 
    --and to do so, you can use the DROP TABLE statement, 
    --which differs from the DELETE statement in that it also removes the table schema from the database entirely.
    DROP TABLE IF EXISTS mytable;

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
