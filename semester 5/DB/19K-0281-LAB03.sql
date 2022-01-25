1. Create table Jobs and job_History (ignore foreign keys relations) same fields as given in HR Schema in which job_ID is considered as primary key in jobs table.
create table Jobs (
    JOB_ID varchar(10) PRIMARY KEY,
    JOB_TITLE varchar2(35) NOT NULL,
    MIN_SALARY number(6) NOT NULL,
    MAX_SALARY number(6) NOT NULL
    );
create table JOB_HISTORY(
    EMPLOYEE_ID number(6) NOT NULL,
    START_DATE date NOT NULL,
    END_DATE date NOT NULL, 
    JOB_ID varchar2(10) NOT NULL, 
    DEPARTMENT_ID number(4)
    );

2. Change the data type of ‘job_ID’ from character to numeric in Jobs table.(Like IT_Prog-&gt;101).
alter table Jobs MODIFY JOB_ID number(6);
alter table JOB_HISTORY MODIFY JOB_ID number(6);

3. Write a SQL statement to add job_id column in job_history table as foreign key referencing to the primary key job_id of jobs table.
alter table JOB_HISTORY ADD FOREIGN KEY (JOB_ID) REFERENCES Jobs(JOB_ID);

4.Insert a new row in jobs table having all the attributes and the job_ID should update in job_History table as well.
Insert into JOBS VALUES(101, 'Sales Manager', 5000, 25000);
Insert into JOB_HISTORY VALUES (55,'16-Jun-00', '20-Sep-20', 101, 90);

5. Add Column Job_Nature in Jobs table.
alter table JOBS ADD (JOB_NATURE varchar2 (25));

6. Create replica of employee table.
create table Employees as (
    select * from hr.Employees
    );

7. Write a SQL statement to add employee_id column in job_history table as foreign key referencing to the primary key employee_id of employees table.
alter table Employees ADD primary key(EMPLOYEE_ID);
delete from employees;
delete from JOB_HISTORY where EMPLOYEE_ID=55;
alter table JOB_HISTORY ADD FOREIGN KEY(EMPLOYEE_ID) REFERENCES EMPLOYEES(EMPLOYEE_ID);

8. Drop column Job_Nature.
alter table Jobs DROP COLUMN JOB_NATURE;

9. ALTER table EMPLOYEE created in question 5 and apply the constraint CHECK on First_Name attribute such that ENAME should always be inserted in capital letters.
alter table EMPLOYEES ADD Check (FIRST_NAME=INITCAP(FIRST_NAME));

10. ALTER table EMPLOYEE created in question 5 and apply the constraint on SALary attribute such that no two salaries of the employees should be similar.(Hint Unique)
alter table EMPLOYEES ADD UNIQUE(salary);

11. ALTER table Employee created in question 5 and apply constraint on Phone_No such that Phone_No should not be entered empty (Hint modify).
desc EMPLOYEES;
alter table EMPLOYEES modify PHONE_NUBMER varchar2(20)NOT NULL;

12. Write a SQL statement to insert one row into the table employees.
insert into EMPLOYEES VALUES(98, 'Hermain', 'Qadir', 'hermainqadir', '090078601', '13-Mar-23', 54, 80000, 0.5, 45, 34);

13. Write a SQL statement to change the salary of employee to 8000 who’s ID is 105, if the existing salary is less than 1+000.
update EMPLOYEES SET salary=8000 where SALARY<1000;

14. Write a SQL statement to add a primary key for a combination of columns employee_id and job_id in employees table, give the reason why this command is showing error.
    query: alter table EMPLOYEES add primary key(EMPLOYEE_ID, JOB_ID)
    because a table cannot have two primary keys. A table will have ONLY one primary key, not more than that.

15. Write a SQL statement to add an index named indx_job_id on job_id column in the table job_history.
create unique index index_job_id on job_history(JOB_ID);

16. Write a SQL statement to remove employees table.
drop table EMPLOYEES cascade constraints; 
