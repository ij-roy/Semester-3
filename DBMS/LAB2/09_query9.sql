-- Display the names of salesmen who did not receive any orders
SELECT s.NAME
FROM SALESMAN s
LEFT JOIN ORDERS o ON s.SALESMAN_ID = o.SALESMAN_ID
WHERE o.SALESMAN_ID IS NULL;
