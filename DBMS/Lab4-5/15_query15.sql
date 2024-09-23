/*
15. Find the Highest Enrollment Course:
Question: Find the course with the highest number of enrollments.
*/

SELECT c.course_name, COUNT(e.student_id) AS enrollments
FROM Courses c
JOIN Enrollments e ON c.course_id = e.course_id
GROUP BY c.course_name
ORDER BY enrollments DESC
LIMIT 1;
