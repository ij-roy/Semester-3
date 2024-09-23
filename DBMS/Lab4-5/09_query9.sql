/*
9. Find Courses Without Enrollments:
Question: Identify courses that currently have no students enrolled
*/

SELECT c.course_id, c.course_name
FROM Courses c
LEFT JOIN Enrollments e ON c.course_id = e.course_id
WHERE e.course_id IS NULL;