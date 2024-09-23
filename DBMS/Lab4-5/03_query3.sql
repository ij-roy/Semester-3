/*
3. List Courses Taught by Each Instructor:
Question: List all instructors along with the courses they teach.
*/

SELECT i.first_name, i.last_name, c.course_name
FROM Instructors i
JOIN Courses c ON i.instructor_id = c.instructor_id;