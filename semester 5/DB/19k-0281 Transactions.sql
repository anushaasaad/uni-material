--19k-0281 Anusha Saad
1.
create table Persons (PersonID varchar2(10) PRIMARY KEY, first_name varchar2(25), last_name varchar2(25), city varchar2(25), age number(10));
insert into Persons values (01, 'Anusha', 'Saad' , 'Karachi', 20) ;
insert into Persons values (02, 'Alishba', 'Ahmed' , 'Islamabad', 16) ;
insert into Persons values (03, 'Saman', 'Khan' , 'Mansera', 21) ;
insert into Persons values (04, 'Hadiqa', 'Khan' , 'Quetta', 20) ;
insert into Persons values (05, 'Hermain', 'Qadir' , 'Lahore', 22) ;
savepoint sp; 
select * from Persons; 
insert into Persons values (06, 'Areeb', 'Aqeel' , 'Karachi', 23) ;
insert into Persons values (07, 'Ahmed', 'Raza' , 'Rawalpindi', 21) ;
insert into Persons values (08, 'Sharjeel', 'Khan' , 'Faisalabad', 20) ;
insert into Persons values (09, 'Mubeen', 'Zaheer' , 'Sukkur', 21) ;
insert into Persons values (10, 'Salaar', 'Sikandir' , 'Multan', 22) ;
select * from Persons; 
update Persons SET first_name='Farjad' where PersonID=06 and first_name='Areeb';
select * from Persons; 
rollback to savepoint sp; 
select * from Persons;

2.

update Persons SET age=19 where PersonID=02;
select * from Persons; 
select * from Persons; 
-- the update here hasn't been committed so other sessions cannot access the database. The db is locked for other sessions.