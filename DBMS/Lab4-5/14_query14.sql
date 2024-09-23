/*
14. List of Courses Taught by Each Instructor and Total Number of Courses:
Question: Create a list of courses each instructor teaches, along with the total number of
courses they are responsible for.
*/

SELECT i.instructor_id, i.first_name, i.last_name, COUNT(c.course_id) AS total_courses
FROM Instructors i
JOIN Courses c ON i.instructor_id = c.instructor_id
GROUP BY i.instructor_id, i.first_name, i.last_name;