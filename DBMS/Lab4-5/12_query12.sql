/*
12. Find Courses with Maximum Enrollments:
Question: Find the course(s) with the maximum number of enrollments.
*/
SELECT c.course_name, COUNT(e.student_id) AS enrollments
FROM Courses c
JOIN Enrollments e ON c.course_id = e.course_id
GROUP BY c.course_name
HAVING COUNT(e.student_id) = (
    SELECT MAX(course_enrollments) 
    FROM (SELECT COUNT(student_id) AS course_enrollments
          FROM Enrollments
          GROUP BY course_id) AS subquery
);
