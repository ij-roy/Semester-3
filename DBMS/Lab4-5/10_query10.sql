/*
10. Calculate Total Number of Students Each Instructor Is Teaching:
Question: Calculate the total number of students each instructor is teaching
*/

SELECT i.instructor_id, i.first_name, i.last_name, COUNT(DISTINCT e.student_id) AS total_students
FROM Instructors i
JOIN Courses c ON i.instructor_id = c.instructor_id
JOIN Enrollments e ON c.course_id = e.course_id
GROUP BY i.instructor_id, i.first_name, i.last_name;