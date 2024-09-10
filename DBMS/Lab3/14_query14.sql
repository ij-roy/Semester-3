-- Calculate the total sales for each salesman
SELECT s.NAME AS Salesman_Name, 
       SUM(o.PURCHASE_AMT) AS Total_Sales
FROM ORDERS o
JOIN SALESMAN s ON o.SALESMAN_ID = s.SALESMAN_ID
GROUP BY s.NAME;
