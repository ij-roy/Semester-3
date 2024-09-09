-- Select ord_no and purchase_amt for orders placed between Feb 2024 and Apr 2024
SELECT ORD_NO, PURCHASE_AMT
FROM ORDERS
WHERE ORD_DATE BETWEEN '2024-02-01' AND '2024-04-30';