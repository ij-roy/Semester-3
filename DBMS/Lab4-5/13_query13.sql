/*
13. Calculate Percentage of Total Students Enrolled in Each Course:
Question: Calculate the percentage of total students enrolled in each course.
*/

SELECT c.course_name, 
       (COUNT(e.student_id) * 100.0 / (SELECT COUNT(*) FROM Students)) AS percentage_of_students
FROM Courses c
JOIN Enrollments e ON c.course_id = e.course_id
GROUP BY c.course_name;