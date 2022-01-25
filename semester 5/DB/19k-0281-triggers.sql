create table Person(id int not null,
                    name varchar(50) not null, 
                    previousname varchar(50) null, 
                    Samecount int null, 
                    constraint pk_Person primary key(id));
--Trigger1: For Insertion and Deletion
create or replace trigger P_trg1
after insert or delete
on Person
begin
    update Person p
    set Samecount = (select count(*) from Person where name = p.name);
end;
--Trgger2: For Updation of Name
create or replace trigger trg_Person_b
after update of name on Person
begin
    update Person p
    set Samecount = (Select count(*) from Person where name = p.name);
end;
--Values Inserted where name Anusha repeated twice
INSERT INTO Person (id, name) values (10, 'saman');
INSERT INTO Person (id, name) values (20, 'hermain');
INSERT INTO Person (id, name) values (30, 'Ahmed');
INSERT INTO Person (id, name) values (40, 'Areeb');
select * from Person;
--Trigger3 
create or replace trigger trg_Person_c
before update
on Person
for each row when (NEW.name is not null and NEW.name != OLD.name)
begin
    :NEW.Previousname := :OLD.name;
end;
--Updating Name
update Person set name = 'Saad' where ID = 3;
select * from Person;