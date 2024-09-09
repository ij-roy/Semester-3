-- Display customer names who placed orders with salesmen in the same city as the customer
SELECT DISTINCT c.CUST_NAME
FROM CUSTOMER1 c
JOIN ORDERS o ON c.CUSTOMER_ID = o.CUSTOMER_ID
JOIN SALESMAN s ON o.SALESMAN_ID = s.SALESMAN_ID
WHERE c.CITY = s.CITY;