show databases;
drop database demo1;
create database demo;
use demo;
show tables;
describe students;
alter table students drop column age;
describe students;
truncate table students;
drop table students;
describe students;



insert into student values(17,'Diksha','pune','2005-08-16');
update student set roll_no=15 where name='Apurva';
delete from student where roll_no=20;


// practical2
// primary key

show databases;
create database score;
use score;
create table student(Roll_No int not null primary key, name varchar(50), address varchar(50));
describe student;

// alter
alter table student add age int;
alter table student drop age;
alter table student modify name varchar(100);
alter table student drop primary key;
alter table student add primary key(name);


// foreign key
create table TG(TG_ID int not null primary key, subject varchar(50), Roll_No int, foreign key(Roll_No) references student(Roll_No));
describe TG;


// drop
rename table TG to teacher;
insert into student value(1,'komal','pune');
select*from student;
truncate table student;
drop table student;
delete from student where Roll_No > 1;