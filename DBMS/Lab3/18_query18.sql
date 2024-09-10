-- Find the customer and salesman names who placed orders in the year 2024
SELECT c.CUST_NAME AS Customer_Name, s.NAME AS Salesman_Name
FROM ORDERS o
JOIN CUSTOMER1 c ON o.CUSTOMER_ID = c.CUSTOMER_ID
JOIN SALESMAN s ON o.SALESMAN_ID = s.SALESMAN_ID
WHERE YEAR(o.ORD_DATE) = 2024;
