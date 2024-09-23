/*
5. Find Students Enrolled in Courses with More than 3 Credits:
Question: Find all students enrolled in courses that offer more than 3 credits.
*/

SELECT s.student_id, s.first_name, s.last_name, c.course_name, c.credits 
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id
WHERE c.credits > 3 ;
