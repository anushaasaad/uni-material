select * from departments;
select * from employees ;
select * from job_history;
select * from employees_BKP;
1.For each department, retrieve the department no, the number of employees in the department and their average salary.
select department_id,avg(salary) as "average_salary", count(department_id) from employees group by department_id;

2.Write a Query to display the number of employees with the same job.
select job_id, count(job_id)as "no_of_employees" from employees group by job_id;

3.Write a Query to select Firstname and Hiredate of Employees Hired right after the joining of employee_ID no 110.
select FIRST_NAME, HIRE_DATE FROM EMPLOYEES where hire_date > (select hire_date from employees where employee_id = '110');

4.Write a SQL query to select those departments where maximum salary is at least 15000.
SELECT DEPARTMENT_ID FROM EMPLOYEES GROUP BY DEPARTMENT_ID HAVING MAX(SALARY)>=15000;

5.Write a query to display the employee number, name (first name and last name) and job title for all employees whose salary is smaller than any salary of those employees whose job title is IT_PROG. 
SELECT FIRST_NAME || ' ' || LAST_NAME AS "Name", JOB_ID,SALARY FROM EMPLOYEES WHERE SALARY < ANY (SELECT SALARY FROM EMPLOYEES WHERE JOB_ID = 'IT_PROG');

6.Write a query in SQL to display all the information of those employees who did not have any job in the past.
select * from employees where employee_id not in (select employee_id from job_history);

7. Display the manager number and the salary of the lowest paid employee of that manager. Exclude anyone whose manager is not known. Exclude any groups where the minimum salary is 2000. Sort the output is descending order of the salary.
select manager_id, min(salary) as "lowest_paid_employee" from employees where manager_id is not null having min(salary) > 2000 group by manager_id 
order by min(salary);

8. Insert into employees_BKP as it should copy the record of the employee whose start date is ’13-JAN-01’ from job_History table.
create table employees_BKP as (select * from employees);
insert into employees_BKP select * from employees where employee_id in (select employee_id from job_history where start_date='13-JAN-01');

9.Update salary of employees by 20% increment having minimum salary of 6000.
update employees set salary= (1.2 * salary) where salary in (select salary from employees where salary <=6000);

10.Delete the record of employees from employees_BKP who are manager and belongs to the department Finance.
insert into employees_BKP select * from employees where employee_id in (select employee_id from job_history where start_date='13-JAN-01');
delete from employees_BKP where employee_id in (select manager_id from departments where department_name='Finance');

11.For each department that has more than five employees, retrieve the department number and the number of its employees who are making more than $20,000.
select department_id,count(employee_id) from employees where salary = any(select salary from employees where salary >20000) group by department_id having count(department_id)>5;