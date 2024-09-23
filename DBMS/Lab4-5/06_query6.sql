/*
6. Calculate Total Credits per Student:
Question: Calculate the total number of credits each student is enrolled in.
*/

SELECT s.student_id, s.first_name, s.last_name, SUM(c.credits) AS total_credits
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id
GROUP BY s.student_id, s.first_name, s.last_name;
