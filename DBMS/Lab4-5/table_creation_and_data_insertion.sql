CREATE DATABASE IF NOT EXISTS COLLEGE;
USE COLLEGE;
CREATE TABLE Students (
    student_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    grade CHAR(1),
    enrollment_date DATE
);

CREATE TABLE Courses (
    course_id INT PRIMARY KEY,
    course_name VARCHAR(50),
    instructor_id INT,
    credits INT
);

CREATE TABLE Enrollments (
    enrollment_id INT PRIMARY KEY,
    student_id INT,
    course_id INT,
    enrollment_date DATE,
    FOREIGN KEY (student_id) REFERENCES Students(student_id),
    FOREIGN KEY (course_id) REFERENCES Courses(course_id)
);

CREATE TABLE Instructors (
    instructor_id INT PRIMARY KEY,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    department VARCHAR(50)
);

INSERT INTO Students (student_id, first_name, last_name, grade, enrollment_date)
VALUES 
(1, 'Alice', 'Johnson', 'A', '2023-01-15'),
(2, 'Bob', 'Smith', 'B', '2023-02-20'),
(3, 'Carol', 'White', 'A', '2023-03-10'),
(4, 'David', 'Brown', 'C', '2023-04-05'),
(5, 'Eve', 'Davis', 'B', '2023-05-22');

INSERT INTO Courses (course_id, course_name, instructor_id, credits)
VALUES
(101, 'Mathematics', 1001, 3),
(102, 'Physics', 1002, 4),
(103, 'Chemistry', 1003, 3),
(104, 'Biology', 1004, 2),
(105, 'History', 1005, 3);

INSERT INTO Instructors (instructor_id, first_name, last_name, department)
VALUES
(1001, 'John', 'Allen', 'Mathematics'),
(1002, 'Jane', 'Baker', 'Physics'),
(1003, 'Sarah', 'Clark', 'Chemistry'),
(1004, 'Michael', 'Davis', 'Biology'),
(1005, 'Emily', 'Evans', 'History');

INSERT INTO Enrollments (enrollment_id, student_id, course_id, enrollment_date)
VALUES
(1001, 1, 101, '2023-01-16'),
(1002, 2, 102, '2023-02-21'),
(1003, 3, 103, '2023-03-11'),
(1004, 4, 104, '2023-04-06'),
(1005, 5, 105, '2023-05-23'),
(1006, 1, 102, '2023-01-16'),
(1007, 3, 101, '2023-03-11'),
(1008, 4, 103, '2023-04-06');
