mysql> show database;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'database' at line 1
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
+--------------------+
3 rows in set (0.01 sec)

mysql> create database score;
Query OK, 1 row affected (0.02 sec)

mysql> use score;
Database changed
mysql> create table student(Roll_No int not null primary key, name varchar(50), address varchar(50));
Query OK, 0 rows affected (0.07 sec)

mysql> describe student;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| Roll_No | int         | NO   | PRI | NULL    |       |
| name    | varchar(50) | YES  |     | NULL    |       |
| address | varchar(50) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.01 sec)

mysql> alter table student add age int;
Query OK, 0 rows affected (0.10 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| Roll_No | int         | NO   | PRI | NULL    |       |
| name    | varchar(50) | YES  |     | NULL    |       |
| address | varchar(50) | YES  |     | NULL    |       |
| age     | int         | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> alter table student drop age;
Query OK, 0 rows affected (0.10 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| Roll_No | int         | NO   | PRI | NULL    |       |
| name    | varchar(50) | YES  |     | NULL    |       |
| address | varchar(50) | YES  |     | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table student modify name varchar(100);
Query OK, 0 rows affected (0.14 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
+---------+--------------+------+-----+---------+-------+
| Field   | Type         | Null | Key | Default | Extra |
+---------+--------------+------+-----+---------+-------+
| Roll_No | int          | NO   | PRI | NULL    |       |
| name    | varchar(100) | YES  |     | NULL    |       |
| address | varchar(50)  | YES  |     | NULL    |       |
+---------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table student drop primary key;
Query OK, 0 rows affected (0.13 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
+---------+--------------+------+-----+---------+-------+
| Field   | Type         | Null | Key | Default | Extra |
+---------+--------------+------+-----+---------+-------+
| Roll_No | int          | NO   |     | NULL    |       |
| name    | varchar(100) | YES  |     | NULL    |       |
| address | varchar(50)  | YES  |     | NULL    |       |
+---------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table student add primary key(name);
Query OK, 0 rows affected (0.10 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
+---------+--------------+------+-----+---------+-------+
| Field   | Type         | Null | Key | Default | Extra |
+---------+--------------+------+-----+---------+-------+
| Roll_No | int          | NO   |     | NULL    |       |
| name    | varchar(100) | NO   | PRI | NULL    |       |
| address | varchar(50)  | YES  |     | NULL    |       |
+---------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table student drop primary key;
Query OK, 0 rows affected (0.23 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> alter table student add primary key(Roll_No);
Query OK, 0 rows affected (0.10 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe student;
+---------+--------------+------+-----+---------+-------+
| Field   | Type         | Null | Key | Default | Extra |
+---------+--------------+------+-----+---------+-------+
| Roll_No | int          | NO   | PRI | NULL    |       |
| name    | varchar(100) | NO   |     | NULL    |       |
| address | varchar(50)  | YES  |     | NULL    |       |
+---------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> create table TG(TG_ID int not null primary key, subject varchar(50), Roll_No int, foreign key(Roll_No) references student(Roll_No);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 1
mysql> create table TG(TG_ID int not null primary key, subject varchar(50), Roll_No int, foreign key(Roll_No) references student(Roll_No));
Query OK, 0 rows affected (0.10 sec)

mysql> describe teacher;
ERROR 1146 (42S02): Table 'score.teacher' doesn't exist
mysql> describe TG;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| TG_ID   | int         | NO   | PRI | NULL    |       |
| subject | varchar(50) | YES  |     | NULL    |       |
| Roll_No | int         | YES  | MUL | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table TG drop foreign key(Roll_No);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '(Roll_No)' at line 1
mysql> ALTER TABLE TG DROP FOREIGN KEY tg_ibfk_1;
Query OK, 0 rows affected (0.03 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe TG;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| TG_ID   | int         | NO   | PRI | NULL    |       |
| subject | varchar(50) | YES  |     | NULL    |       |
| Roll_No | int         | YES  | MUL | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> describe TG;
+---------+-------------+------+-----+---------+-------+
| Field   | Type        | Null | Key | Default | Extra |
+---------+-------------+------+-----+---------+-------+
| TG_ID   | int         | NO   | PRI | NULL    |       |
| subject | varchar(50) | YES  |     | NULL    |       |
| Roll_No | int         | YES  | MUL | NULL    |       |
+---------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> alter table TG add foreign key(addres) references TG(TG_ID);
ERROR 1072 (42000): Key column 'addres' doesn't exist in table
mysql> alter table TG add foreign key(subject) references TG(TG_ID);
ERROR 3780 (HY000): Referencing column 'subject' and referenced column 'TG_ID' in foreign key constraint 'tg_ibfk_1' are incompatible.
mysql> ALTER TABLE TG MODIFY subject INT;
Query OK, 0 rows affected (0.16 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> ALTER TABLE TG ADD FOREIGN KEY (subject) REFERENCES TG(TG_ID);
Query OK, 0 rows affected (0.17 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> describe TG;
+---------+------+------+-----+---------+-------+
| Field   | Type | Null | Key | Default | Extra |
+---------+------+------+-----+---------+-------+
| TG_ID   | int  | NO   | PRI | NULL    |       |
| subject | int  | YES  | MUL | NULL    |       |
| Roll_No | int  | YES  | MUL | NULL    |       |
+---------+------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> rename table TG to teacher;
Query OK, 0 rows affected (0.05 sec)

mysql> describe TG;
ERROR 1146 (42S02): Table 'score.tg' doesn't exist
mysql> describe teacher;
+---------+------+------+-----+---------+-------+
| Field   | Type | Null | Key | Default | Extra |
+---------+------+------+-----+---------+-------+
| TG_ID   | int  | NO   | PRI | NULL    |       |
| subject | int  | YES  | MUL | NULL    |       |
| Roll_No | int  | YES  | MUL | NULL    |       |
+---------+------+------+-----+---------+-------+
3 rows in set (0.01 sec)

mysql> insert into student value(1,'komal','pune');
Query OK, 1 row affected (0.01 sec)

mysql> insert into student value(2,'tanishka','kharadi');
Query OK, 1 row affected (0.01 sec)

mysql> insert into student value(1,'riya','hostel'),
    -> (11,'radha','hostel'),
    -> (15,'sushma','hostel'),
    -> (10,'sus','hostel');
ERROR 1062 (23000): Duplicate entry '1' for key 'student.PRIMARY'
mysql> insert into student value(2,'tanishka','kharadi');
ERROR 1062 (23000): Duplicate entry '2' for key 'student.PRIMARY'
mysql> insert into student value(9,'riya','hostel'),
    -> (10,'sus','hostel');
Query OK, 2 rows affected (0.01 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select*from student;
+---------+----------+---------+
| Roll_No | name     | address |
+---------+----------+---------+
|       1 | komal    | pune    |
|       2 | tanishka | kharadi |
|       9 | riya     | hostel  |
|      10 | sus      | hostel  |
+---------+----------+---------+
4 rows in set (0.00 sec)

mysql> truncate table student;
Query OK, 0 rows affected (0.08 sec)

mysql> select*from student;
Empty set (0.00 sec)

mysql> drop table student;
Query OK, 0 rows affected (0.04 sec)

mysql> describe student;
ERROR 1146 (42S02): Table 'score.student' doesn't exist
mysql>