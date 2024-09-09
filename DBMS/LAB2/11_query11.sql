-- Find salesmen with more than one customer
SELECT s.NAME, COUNT(c.CUSTOMER_ID) AS Customer_Count
FROM SALESMAN s
JOIN CUSTOMER1 c ON s.SALESMAN_ID = c.SALESMAN_ID
GROUP BY s.SALESMAN_ID
HAVING COUNT(c.CUSTOMER_ID) > 1;

-- Find salesmen who have customers in their city
SELECT DISTINCT s.NAME
FROM SALESMAN s
JOIN CUSTOMER1 c ON s.SALESMAN_ID = c.SALESMAN_ID AND s.CITY = c.CITY;

-- Find all salesmen with and without customers in their city
SELECT s.NAME, 
       CASE 
           WHEN EXISTS (SELECT 1 
                        FROM CUSTOMER1 c 
                        WHERE s.SALESMAN_ID = c.SALESMAN_ID 
                          AND s.CITY = c.CITY) 
           THEN 'Has Customers in City'
           ELSE 'No Customers in City'
       END AS Customer_Status
FROM SALESMAN s;
