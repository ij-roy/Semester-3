-- Find the total sales made in the last 7 days
SELECT SUM(PURCHASE_AMT) AS Total_Sales
FROM ORDERS
WHERE ORD_DATE >= CURDATE() - INTERVAL 7 DAY;
