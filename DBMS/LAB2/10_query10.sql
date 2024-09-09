-- Get the average grade for customers in Bangalore
SET @avg_grade := (SELECT AVG(GRADE) FROM CUSTOMER1 WHERE CITY = 'BANGALORE');

-- Count the customers with grades above this average
SELECT COUNT(*)
FROM CUSTOMER1
WHERE GRADE > @avg_grade;
