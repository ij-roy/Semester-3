/*
8. Find Students Who Have Enrolled in Physics and Have an 'A' Grade:
Question: Find students who have enrolled in the Physics course and have an "A" grade.
*/

SELECT s.student_id, s.first_name, s.last_name
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id
WHERE c.course_name = 'Physics' AND s.grade = 'A';