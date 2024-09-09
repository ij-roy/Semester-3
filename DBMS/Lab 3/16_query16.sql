-- Display total orders for each month
SELECT YEAR(ORD_DATE) AS Year,
       MONTH(ORD_DATE) AS Month,
       COUNT(*) AS Total_Orders
FROM ORDERS
GROUP BY YEAR(ORD_DATE), MONTH(ORD_DATE)
ORDER BY Year, Month;
