/*
4. Find Students Enrolled in More than One Course:
Question: Write a query to find students who are enrolled in more than one course.
*/

SELECT s.student_id, s.first_name, s.last_name, COUNT(e.course_id) AS course_count
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
GROUP BY s.student_id, s.first_name, s.last_name
HAVING COUNT(e.course_id) > 1;