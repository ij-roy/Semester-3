/*
7. List Students Who Enrolled in All Courses:
Question: Find students who are enrolled in every available course.
*/

SELECT s.student_id, s.first_name, s.last_name
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
GROUP BY s.student_id, s.first_name, s.last_name
HAVING COUNT(DISTINCT e.course_id) = (SELECT COUNT(*) FROM Courses);