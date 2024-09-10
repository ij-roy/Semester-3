-- Identify duplicate records based on order_date and customer_id
SELECT ORD_DATE, CUSTOMER_ID, COUNT(*) AS Duplicate_Count
FROM ORDERS
GROUP BY ORD_DATE, CUSTOMER_ID
HAVING COUNT(*) > 1;

-- Get the actual duplicate records
SELECT o.*
FROM ORDERS o
JOIN (
    SELECT ORD_DATE, CUSTOMER_ID
    FROM ORDERS
    GROUP BY ORD_DATE, CUSTOMER_ID
    HAVING COUNT(*) > 1
) dup
ON o.ORD_DATE = dup.ORD_DATE
   AND o.CUSTOMER_ID = dup.CUSTOMER_ID;