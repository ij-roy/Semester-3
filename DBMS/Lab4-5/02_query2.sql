/*
2. Count Students Enrolled in Each Course:
Question: Find the number of students enrolled in each course.
*/

SELECT c.course_name, COUNT(e.student_id) AS student_count
FROM Courses c
JOIN Enrollments e ON c.course_id = e.course_id
GROUP BY c.course_name;