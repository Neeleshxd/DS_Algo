# Write your MySQL query statement below
SELECT v.name,p.bonus FROM 
Employee v LEFT JOIN 
Bonus p ON v.empID = p.empID
WHERE p.bonus < 1000 OR p.bonus IS NULL; 