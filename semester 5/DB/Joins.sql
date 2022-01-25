--19k-0281 ANUSHA SAAD SECTION:H
select * from departments;
1.Write a query to list the name, job name, department name, salary of the employees according to the department in ascending order.
select first_name , job_title, department_name, salary from (employees natural join departments) natural join jobs order by department_id asc;

2. Write a query to list the department where at least two employees areworking.
select department_id,count(employee_id) from departments natural join employees group by department_id having count(employee_id)>2;

3.Fetch all the records where salary of employee is less than the lower salary.
select * from jobs natural join employees where min_salary > all(select salary from employees); 

4.Write a query to list the name, job name, annual salary, department id, department name and city who earn 60000 in a year or not working as an ANALYST.
select first_name , job_title, salary, department_id from (employees natural join jobs) natural join departments where salary = 60000 or job_title <> 'Analyst';

5.Write a query to print details of the employees who are also Managers.
SELECT e.first_name,e.employee_id, e.manager_id, m.first_name FROM employees e join employees m  ON (e.manager_id = m.employee_id);

6.List department number, Department name for all the departments in which there are no employees in the department.
SELECT D.department_id, D.department_name FROM DEPARTMENTS D INNER JOIN EMPLOYEES E ON D.DEPARTMENT_ID=E.DEPARTMENT_ID WHERE E.DEPARTMENT_ID=NULL;

7.Display employee name, salary, department name where all employees has matching department as well as employee does not have any departments.
SELECT E.first_name||' '||E.last_name as "name", E.SALARY, D.DEPARTMENT_NAME FROM EMPLOYEES E LEFT JOIN DEPARTMENTS D ON E.EMPLOYEE_ID=D.DEPARTMENT_ID;

8.Display name, job ID, department name, street address and city of the employee in which there is no state province.
SELECT E.first_name||' '||E.last_name as "name", DEPARTMENT_NAME, STREET_ADDRESS, CITY, L.STATE_PROVINCE FROM EMPLOYEES E JOIN DEPARTMENTS D ON E.DEPARTMENT_ID=D.DEPARTMENT_ID JOIN LOCATIONS L ON D.LOCATION_ID=L.LOCATION_ID WHERE L.STATE_PROVINCE IS NULL;

9.Write an SQL query to show records from one table that another table does not have.
SELECT employee_id, JOB_ID FROM EMPLOYEES MINUS SELECT EMPLOYEE_ID,JOB_ID FROM JOB_HISTORY;

10.Display all employees who belong to country US but not belongs to state province Washington.
SELECT E.* FROM EMPLOYEES E INNER JOIN DEPARTMENTS D ON E.DEPARTMENT_ID=D.DEPARTMENT_ID INNER JOIN LOCATIONS L ON L.LOCATION_ID=D.LOCATION_ID INNER JOIN COUNTRIES C ON l.country_id =C.COUNTRY_ID WHERE   L.STATE_PROVINCE! ='WASHINGTON' AND C.COUNTRY_NAME= 'United States of America';  
