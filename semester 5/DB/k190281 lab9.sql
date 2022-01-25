--lab-09 19k-0281
1.
SET SERVEROUTPUT ON;
DECLARE 
    SALARY HR.EMPLOYEES.SALARY%TYPE;
    BONUS FLOAT :=0;
BEGIN
    SELECT E.SALARY INTO SALARY FROM  EMPLOYEES E WHERE E.EMPLOYEE_ID=&value;
    IF SALARY<1000
        THEN BONUS:= (.1)*SALARY;
    ELSIF SALARY BETWEEN 1000 AND 15000
        THEN BONUS:=(.15)*SALARY;
    ELSIF SALARY>1500 
        THEN BONUS:=(.20)*SALARY;
    ELSIF SALARY=NULL
        THEN BONUS:=0;
    END IF;
   DBMS_OUTPUT.PUT_LINE('Bonus of the Employee is: '|| BONUS);
END;

2.Write a pl/sql block in sql that ask a user for employee id than it checks its commission if commission is null than it updates salary of that employee by adding commission into salary.
DECLARE 
    EMP_ID EMPLOYEES.EMPLOYEE_ID%TYPE;
    COMMISSION EMPLOYEES.COMMISSION_PCT%TYPE;
BEGIN
    SELECT E.COMMISSION_PCT INTO COMMISSION FROM EMPLOYEES E WHERE E.EMPLOYEE_ID=&EMP_ID;
    IF COMMISSION IS NOT NULL 
        THEN UPDATE HR.EMPLOYEES E SET E.SALARY= E.SALARY + COMMISSION WHERE E.EMPLOYEE_ID=EMP_ID;
    END IF;  
END;
/
3.Write a PL/SQL block to obtain the department name of the employee who works for deptno 30
DECLARE 
    DEP_NAME DEPARTMENTS.DEPARTMENT_NAME%TYPE;
BEGIN
    SELECT D.DEPARTMENT_NAME INTO DEP_NAME FROM HR.DEPARTMENTS D WHERE D.DEPARTMENT_ID=30;
    DBMS_OUTPUT.put_line('DEPARTMENT NAME= ' ||DEP_NAME);
END;
/
4.Write a PL /SQL block to find the nature of job of the employee whose deptno is 20(to be passed as an argument)
CREATE OR REPLACE PROCEDURE FIND_JOB_NATURE(DEPT_NO IN HR.DEPARTMENTS.DEPARTMENT_ID%TYPE)
AS  
BEGIN
   
    FOR REC IN (SELECT J.* FROM HR.EMPLOYEES E,HR.JOBS J WHERE E.DEPARTMENT_ID=DEPT_NO AND E.JOB_ID=J.JOB_ID) 
    LOOP
        DBMS_OUTPUT.PUT_LINE('JOB_ID: '||REC.JOB_ID);
        DBMS_OUTPUT.PUT_LINE('JOB_TITLE: '||REC.JOB_TITLE);
        DBMS_OUTPUT.PUT_LINE('MIN_SALARY: '||REC.MIN_SALARY);
        DBMS_OUTPUT.PUT_LINE('MAX_SALARY: '||REC.MAX_SALARY);
    END LOOP;
END;
/ 
BEGIN    
    FIND_JOB_NATURE(20);  
END;
/
5.Write a PL /SQL block to find the salary of the employee who is working in the deptno 20(to be passed as an argument).
CREATE OR REPLACE PROCEDURE FIND_SALARY(DEPT_NO IN HR.DEPARTMENTS.DEPARTMENT_ID%TYPE)
AS  
BEGIN
   
    FOR REC IN (SELECT E.SALARY FROM HR.EMPLOYEES E WHERE E.DEPARTMENT_ID=DEPT_NO) 
    LOOP
        DBMS_OUTPUT.PUT_LINE('SALARY: '||REC.SALARY);           
    END LOOP;
END;
/ 
BEGIN    
    FIND_SALARY(20);  
END;
/
6.Write a PL/SQL block to update the salary of the employee with a 10% increase whose empno is to be passed as an argument for the procedure
CREATE OR REPLACE PROCEDURE UPDATE_SALARY(E_ID IN HR.EMPLOYEES.EMPLOYEE_ID%TYPE)
AS  
BEGIN
    UPDATE HR.EMPLOYEES E SET E.SALARY= (E.SALARY * .1) + E.SALARY WHERE E.EMPLOYEE_ID=E_ID;   
END;
/ 
BEGIN    
    UPDATE_SALARY(&E_ID); 
END;
/
7.Write a procedure to add an amount of Rs.1000 for the employees whose salaries is greater than 5000 and who belongs to the deptno passed as an argument.
CREATE OR REPLACE PROCEDURE ADD_TO_SALARY(DEPT_NO IN HR.DEPARTMENTS.DEPARTMENT_ID%TYPE)
AS
BEGIN
   
    FOR REC IN (SELECT E.* FROM HR.EMPLOYEES E WHERE E.DEPARTMENT_ID=DEPT_NO) 
    LOOP
        IF(REC.SALARY>5000) THEN
            UPDATE HR.EMPLOYEES E SET E.SALARY = E.SALARY+1000 WHERE E.EMPLOYEE_ID=REC.EMPLOYEE_ID;
        END IF;    
    END LOOP;
END;
/ 
BEGIN    
     ADD_TO_SALARY(&DEP_ID);
END;
/
8.
CREATE OR REPLACE VIEW EMPOLYEES_IN_A_JOB
AS
    SELECT COUNT(E.EMPLOYEE_ID) AS NO_OF_EMPLOYEES,J.JOB_TITLE AS DESIGNATION 
    FROM HR.EMPLOYEES E,HR.JOBS J 
    WHERE E.JOB_ID=J.JOB_ID GROUP BY E.JOB_ID,J.JOB_TITLE;

SELECT * FROM EMPOLYEES_IN_A_JOB;
/    
CREATE OR REPLACE VIEW EMPOLYEES_INFO_EXCEPT_KING
AS
    SELECT  E.EMPLOYEE_ID  E_ID,(E.FIRST_NAME||E.LAST_NAME) E_NAME, D.DEPARTMENT_ID D_ID,D.DEPARTMENT_NAME D_NANE 
    FROM HR.EMPLOYEES E,HR.DEPARTMENTS D
    WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID AND (E.FIRST_NAME||E.LAST_NAME) NOT LIKE '%King%';

SELECT * FROM EMPOLYEES_INFO_EXCEPT_KING;
/
CREATE OR REPLACE VIEW EMPOLYEES_INFO
AS
    SELECT  E.EMPLOYEE_ID  E_ID,(E.FIRST_NAME||E.LAST_NAME) E_NAME, D.DEPARTMENT_ID D_ID,D.DEPARTMENT_NAME D_NANE 
    FROM HR.EMPLOYEES E,HR.DEPARTMENTS D
    WHERE E.DEPARTMENT_ID=D.DEPARTMENT_ID;

SELECT * FROM EMPOLYEES_INFO;
/
9.Write a PL/SQL code that takes two inputs from user, add them and store the sum in new
variable and show the output.
DECLARE 
    SUM_ NUMBER;
BEGIN
    SUM_:=&A+&B;
    DBMS_OUTPUT.PUT_LINE('SUM: '||SUM_);
END;
/
10.Write a PL/SQL code that takes two inputs, lower boundary and upper boundary, then print the sum of all the numbers between the boundaries INCLUSIVE.
DECLARE 
    SUM_NUMBER  NUMBER:=0;
    I  INTEGER:=0;
    L_BOUND  INTEGER:=&L_BOUND;
    U_BOUND  INTEGER:=&U_BOUND;
BEGIN
    FOR I IN L_BOUND .. U_BOUND 
    LOOP
    SUM_NUMBER :=SUM_NUMBER+I;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE('SUM OF N NUMBERS FROM LOWER TO UPPER BOUND: '||SUM_NUMBER);
END;
/
11.Write a PL/SQL code to retrieve the employee name, hiredate, and the department name in which he works, whose number is input by the user.
DECLARE
    E_NAME      HR.EMPLOYEES.FIRST_NAME%TYPE;
    E_HDATE     HR.EMPLOYEES.HIRE_DATE%TYPE;
    D_NAME      HR.DEPARTMENTS.DEPARTMENT_NAME%TYPE;
BEGIN
    SELECT (E.FIRST_NAME||' '||E.LAST_NAME),E.HIRE_DATE,D.DEPARTMENT_NAME INTO E_NAME,E_HDATE,D_NAME FROM HR.EMPLOYEES E,HR.DEPARTMENTS D WHERE E.EMPLOYEE_ID=&value AND E.DEPARTMENT_ID=D.DEPARTMENT_ID;  
    DBMS_OUTPUT.PUT_LINE('NAME: '|| E_NAME ||'  HIRE_DATE: '||E_HDATE||'    DEPARTMENT_NAME: '||D_NAME);
END;
/
12.Write a PL/SQL code to check whether the given number is palindrome or not.
DECLARE
    N1 INTEGER:=&N1;
    SUM_ INTEGER:=0;
    REMINDER  INTEGER;
    i  INTEGER:=0;
    TEMP INTEGER;
BEGIN
    TEMP:=N1;
    WHILE (N1>0)
    LOOP
        REMINDER:= N1 MOD 10;
        SUM_:= (SUM_ + (REMINDER*POWER(10,i)));
        i := i + 1;
        N1:=N1/10;
    END LOOP;
    IF SUM_=TEMP THEN
        DBMS_OUTPUT.PUT_LINE('NUMBER IS PALINDROME');
    ELSE
        DBMS_OUTPUT.PUT_LINE('NUMBER IS NOT PALINDROME');
    END IF;
END;    
/
13.Write a PL/SQL code that takes all the required inputs from the user for the Employee table and then insert it into the Employee and Department table in the database.
SET SERVEROUTPUT ON;
DECLARE

    EMP_ID          EMPLOYEES.EMPLOYEE_ID%TYPE :=&EMPLOYEE_ID;
    FIRST_NAME      EMPLOYEES.FIRST_NAME%TYPE:=&FIRST_NAME;
    LAST_NAME       EMPLOYEES.LAST_NAME%TYPE:=&LAST_NAME;
    EMAIL           EMPLOYEES.EMAIL%TYPE:=&EMAIL;
    PHONE_NUMBER    EMPLOYEES.PHONE_NUMBER%TYPE:=&PHONE_NUMBER;
    HIRE_DATE       EMPLOYEES.HIRE_DATE%TYPE:=&HIRE_DATE;
    JOB_ID          EMPLOYEES.JOB_ID%TYPE:=&JOB_ID;
    SALARY          EMPLOYEES.SALARY%TYPE:=&SALARY;
    COMMISSION_PCT  EMPLOYEES.COMMISSION%TYPE:=&COMMISSION_PCT;
    MANAGER_ID      EMPLOYEES.MANAGER_ID%TYPE:=&MANAGER_ID;
    DEPARTMENT_ID   EMPLOYEES.DEPARTMENT_ID%TYPE:=&DEPARTMENT_ID;
    D_ISPRESENT       BOOLEAN:=FALSE;
BEGIN
    
    FOR REC IN (SELECT D.DEPARTMENT_ID FROM HR.DEPARTMENTS D)
    LOOP
        IF DEPARTMENT_ID = REC.DEPARTMENT_ID
        THEN
            ISPRESENT:=TRUE;
        END IF;
   END LOOP;
   IF ISPRESENT=TRUE 
   THEN
    INSERT INTO HR.EMPLOYEES VALUES(EMP_ID, FIRST_NAME,LAST_NAME, EMAIL,PHONE_NUMBER,HIRE_DATE,JOB_ID,SALARY, COMMISSION_PCT,MANAGER_ID,DEPARTMENT_ID);   
   
   ELSE
    INSERT INTO HR.DEPARTMENTS VALUES(DEPARTMENT_ID,'ABC');
    INSERT INTO HR.EMPLOYEES VALUES(EMP_ID, FIRST_NAME,LAST_NAME, EMAIL,PHONE_NUMBER,HIRE_DATE,JOB_ID,SALARY, COMMISSION_PCT,MANAGER_ID,DEPARTMENT_ID);
   END IF; 
END;
/
14.Write a PL/SQL code to find the first employee who has a salary over $2500 and is higher in the chain of command than employee 7499. Note: For chain, use of LOOP is necessary.
SET SERVEROUTPUT ON;
DECLARE
   EMP_NAME       EMPLOYEES.FIRST_NAME%TYPE;
   EMP_ID         EMPLOYEES.EMPLOYEE_ID%TYPE := &E_ID;
   SALARY       EMPLOYEES.SALARY%TYPE := 0;
   MANAGER_ID   EMPLOYEES.MANAGER_ID%TYPE;
BEGIN
   SELECT E.MANAGER_ID INTO MANAGER_ID FROM EMPLOYEES E WHERE E.EMPLOYEE_ID=EMP_ID;
   WHILE SALARY <= 2500 
   LOOP
      SELECT E.SALARY, E.MANAGER_ID, (E.FIRST_NAME||E.LAST_NAME) INTO SALARY, MANAGER_ID ,EMP_NAME FROM HR.EMPLOYEES E WHERE  EMPLOYEE_ID= MANAGER_ID;
   END LOOP;
   IF(SALARY>2500)
   THEN 
   DBMS_OUTPUT.PUT_LINE('NAME: ' ||EMP_NAME);
   DBMS_OUTPUT.PUT_LINE('SALARY: ' ||SALARY);
   END IF;

EXCEPTION
    WHEN NO_DATA_FOUND THEN
    DBMS_OUTPUT.PUT_LINE('EMPLOYEE NOT FOUND');
END;
/
15.Write a PL/SQL code to print the sum of first 100 numbers.
SET SERVEROUTPUT ON;
DECLARE 
    SUM_numbers INTEGER:=0;
    i INTEGER;
BEGIN
    FOR i IN 1..100
    LOOP
        SUM_numbers := SUM_numbers+i;
    END LOOP;
     DBMS_OUTPUT.PUT_LINE('Sum of first 100 numbers: '||SUM_numbers);
END;
/


