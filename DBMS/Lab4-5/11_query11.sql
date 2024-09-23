/*
11. Calculate Average Grade per Course:
Question: Write a query to calculate the average grade for each course.
*/

SELECT c.course_name, AVG(
    CASE s.grade
        WHEN 'A' THEN 4
        WHEN 'B' THEN 3
        WHEN 'C' THEN 2
        ELSE 0
    END
) AS average_grade
FROM Courses c
JOIN Enrollments e ON c.course_id = e.course_id
JOIN Students s ON e.student_id = s.student_id
GROUP BY c.course_name;