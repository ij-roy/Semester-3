-- Create a view for the salesman who has the customer with the highest order of a day
CREATE VIEW Salesman_With_Highest_Order AS
SELECT s.NAME AS Salesman_Name, 
       c.CUST_NAME AS Customer_Name, 
       o.ORD_NO, 
       o.PURCHASE_AMT, 
       o.ORD_DATE
FROM SALESMAN s
JOIN ORDERS o ON s.SALESMAN_ID = o.SALESMAN_ID
JOIN CUSTOMER1 c ON o.CUSTOMER_ID = c.CUSTOMER_ID
WHERE o.PURCHASE_AMT = (SELECT MAX(PURCHASE_AMT) FROM ORDERS WHERE ORD_DATE = o.ORD_DATE);

-- Query the view to see the results
SELECT * FROM Salesman_With_Highest_Order;