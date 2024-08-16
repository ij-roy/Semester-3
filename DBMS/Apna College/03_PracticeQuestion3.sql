/*
For the given table, find the total payment according to each payment method.
*/
CREATE DATABASE IF NOT EXISTS XYZ;
USE XYZ;
CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    customer VARCHAR(100),
    mode VARCHAR(50),
    city VARCHAR(50)
);
INSERT INTO customers
  (customer_id, customer, mode, city)
VALUES
  (101, 'Olivia Barrett', 'Netbanking', 'Portland'),
  (102, 'Ethan Sinclair', 'Credit Card', 'Miami'),
  (103, 'Maya Hernandez', 'Credit Card', 'Seattle'),
  (104, 'Liam Donovan', 'Netbanking', 'Denver'),
  (105, 'Sophia Nguyen', 'Credit Card', 'New Orleans'),
  (106, 'Caleb Foster', 'Debit Card', 'Minneapolis'),
  (107, 'Ava Patel', 'Debit Card', 'Phoenix'),
  (108, 'Lucas Carter', 'Netbanking', 'Boston'),
  (109, 'Isabella Martinez', 'Netbanking', 'Nashville'),
  (110, 'Jackson Brooks', 'Credit Card', 'Boston'); 
SELECT mode , count(customer_id)
FROM customers
GROUP BY mode;