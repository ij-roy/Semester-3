/*
Consider the following schema for Order Database:
SALESMAN (Salesman_id, Name, City, Commission)
CUSTOMER (Customer_id, Cust_Name, City, Grade, Salesman_id)
ORDERS (Ord_No, Purchase_Amt, Ord_Date, Customer_id, Salesman_id) .
*/

CREATE DATABASE IF NOT EXISTS LABS;
USE LABS;
CREATE TABLE SALESMAN (
	SALESMAN_ID INT (4), 
    NAME VARCHAR (20),
    CITY VARCHAR (20),
	COMMISSION VARCHAR (20), 
    PRIMARY KEY(SALESMAN_ID));
CREATE TABLE CUSTOMER1 (
	CUSTOMER_ID INT (4),
	CUST_NAME VARCHAR (20),
	CITY VARCHAR (20),
	GRADE INT (3),
    SALESMAN_ID INT(4),
	PRIMARY KEY (CUSTOMER_ID),
	FOREIGN KEY (SALESMAN_ID) REFERENCES SALESMAN (SALESMAN_ID));
CREATE TABLE ORDERS (
	ORD_NO INT (5),
	PURCHASE_AMT DECIMAL (10, 2),
	ORD_DATE DATE,
    CUSTOMER_ID INT(4),
    SALESMAN_ID INT(4),
	PRIMARY KEY (ORD_NO),
	FOREIGN KEY (CUSTOMER_ID) REFERENCES CUSTOMER1 (CUSTOMER_ID) ,
	FOREIGN KEY (SALESMAN_ID) REFERENCES SALESMAN (SALESMAN_ID));
INSERT INTO SALESMAN (SALESMAN_ID,NAME,CITY,COMMISSION)
VALUES
	(1000,"JOHN","BANGALORE","25%"),
	(2000,"RAVI","BANGALORE","20%"),
	(3000,"KUMAR","MYSORE","15%"),
	(4000,"SMITH","DELHI","30%"),
	(5000,"HARSHA","HYDERABAD","15%");
INSERT INTO CUSTOMER1 (CUSTOMER_ID, CUST_NAME, CITY, GRADE, SALESMAN_ID)
VALUES
    (10, "PREETHI", "BANGALORE", 100, 1000),
    (11, "VIVEK", "MANGALORE", 300, 1000),
    (12, "BHASKAR", "CHENNAI", 400, 2000),
    (13, "CHETAN", "BANGALORE", 200, 2000),
    (14, "MAMATHA", "BANGALORE", 400, 3000);
INSERT INTO ORDERS (ORD_NO,PURCHASE_AMT,ORD_DATE,CUSTOMER_ID,SALESMAN_ID)
VALUES
	(50,5000,'2024-05-04',10,1000),
	(51,450,'2024-01-20',10,2000),
	(52,1000,'2024-02-24',13,2000),
	(53,3500,'2024-04-13',14,3000),
	(54,350,'2024-03-09',12,2000);
SELECT * FROM SALESMAN;
SELECT * FROM CUSTOMER1;
SELECT * FROM ORDERS;
