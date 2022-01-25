LAB 01 Practice Query 
1.Write a SQL statement to display all the information of table Jobs.
SELECT * FROM JOBS

2.Write a SQL query to find min and max salary of the Job table with Job title ‘President’ from Jobs table.
SELECT * FROM JOBS WHERE JOB_TITLE = 'President'

3.Write a SQL query to find those employees whose Salaries is 20000 from Employees table.
SELECT * FROM EMPLOYEES WHERE SALARY = 20000

4.Write a SQL query to find the Jobs whose salary are higher than or equal to $15000 from Employees table.
SELECT * FROM EMPLOYEES WHERE SALARY >= 15000

5.Write a SQL query to find the details of employees whose last name is 'King'. Return emp_idno, emp_fname, emp_lname, and emp_dept.
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, DEPARTMENT_ID FROM EMPLOYEES WHERE LAST_NAME = 'King';

6.Write a SQL query to find the details of the employees who work in the department 50. Return emp_idno, emp_fname, emp_lname and emp_dept.
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, DEPARTMENT_ID FROM EMPLOYEES WHERE DEPARTMENT_ID = 50;

7.Write a query to find the PHONE_NUMBER of the DEPARTMENT_ID=80 and MANAGER_ID=100 of Employees table.
SELECT PHONE_NUMBER FROM EMPLOYEES WHERE DEPARTMENT_ID = 80 AND MANAGER_ID = 100;

8.write a SQL query to find the Employees with the First name “John” “NEENA” and “Lency”
SELECT * FROM EMPLOYEES WHERE FIRST_NAME like 'John' or  FIRST_NAME like 'Neena' or FIRST_NAME like 'Lency';

9.Write a query to find the list of cities with country ID ‘IT’ from locations table.
SELECT * FROM LOCATIONS WHERE COUNTRY_ID = 'IT';

10.Write a query to find the list of city except country ID ‘IN’ and ‘CH’ from locations table.
SELECT * FROM LOCATIONS WHERE COUNTRY_ID != 'IN' AND COUNTRY_ID != 'CH'

11.Write a query to find the list of jobs whose min salary is greater than 8000 and less than 15,000 from job table.
SELECT * FROM JOBS WHERE MIN_SALARY < 15000 AND MIN_SALARY > 8000;

12.Write a query to find list of phone with DEPARTMENT_ID ‘90’ but not with job_id ‘IT_PROG’ from Employees table.
SELECT PHONE_NUMBER,JOB_ID,DEPARTMENT_ID FROM EMPLOYEES WHERE DEPARTMENT_ID = 90 AND JOB_ID != 'IT_PROG' 

13.Write a query to find the list of employees who are hired after '12-Dec-07' from employee table.
SELECT * FROM EMPLOYEES WHERE HIRE_DATE > '12-Dec-07';

14.Write a query to find the list of employees who are hired after 12-Dec-07 in Department with DEPARTMENT_ID=100 from employee table.
SELECT * FROM EMPLOYEES WHERE HIRE_DATE > '12-Dec-07' AND DEPARTMENT_ID = 100;

15.Write a query to find the list of employees who are hired after 12-Dec-07 but not in Department with DEPARTMENT_ID=100 from employee table.
SELECT * FROM EMPLOYEES WHERE HIRE_DATE > '12-Dec-07' AND DEPARTMENT_ID != 100; 