# Write your MySQL query statement below
SELECT s.unique_id  ,e.name FROM 
Employees e LEFT JOIN EmployeeUNI s 
ON e.id = s.id ; 
