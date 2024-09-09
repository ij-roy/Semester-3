-- Display the name of the salesman who received the highest commission
SELECT NAME
FROM SALESMAN
ORDER BY CAST(SUBSTRING(COMMISSION, 1, LENGTH(COMMISSION) - 1) AS UNSIGNED) DESC
LIMIT 1;
