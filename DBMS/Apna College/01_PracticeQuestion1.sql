/*
Question 1. Create a database for your company named XYZ.
	Stepl : create a table inside this DB to store employee info (id, name and salary).
    Step2 : Add following information in the DB
			1, "adam", 25000
			2, "bob", 30000
			3, "casey", 40000
	Step3 : Select & view all your table data.
*/

CREATE DATABASE IF NOT EXISTS XYZ;
USE XYZ;
CREATE TABLE Employee(
	id INT PRIMARY KEY,
    name VARCHAR(50),
    salary INT NOT NULL
);
INSERT INTO Employee
	(id,name,salary)
    VALUES
    (1,"Adam",25000),
    (2,"Bob",30000),
    (3,"Casey",40000);
SELECT * FROM Employee;