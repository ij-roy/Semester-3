/*
In the student table :
a. Change the name of columÖ to "full _ name".
b. Delete all the students who scored marks less than 80.
c. Delete the column for grades.
*/
CREATE DATABASE IF NOT EXISTS college;
USE college;
CREATE TABLE IF NOT EXISTS student (
rollno INT PRIMARY KEY,
name VARCHAR(50),
marks INT NOT NULL,
grade VARCHAR(1),
city VARCHAR(20)
);
INSERT INTO student
( rollno, name, marks, grade, city)
VALUES
(101,"anil",78,"C","Pune"),
(102,"bhumika",93,"A","Mumbai"),
(103,"chetan",85,"B","Mumbai"),
(104,"dhruv",96,"A","Delhi"),
(105,"emanuel",12,"F","Delhi"),
(106,"Farah",82,"B","Delhi");
-- A part
ALTER TABLE student 
CHANGE COLUMN name full_name VARCHAR(50);
-- B part
SET SQL_SAFE_UPDATES = 0;
DELETE FROM student
WHERE marks < 80;
-- C part
ALTER TABLE student
DROP COLUMN grade;
SELECT * FROM student;