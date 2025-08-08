# Write your MySQL query statement below
SELECT v.student_id,v.student_name,p.subject_name,COUNT(e.subject_name) AS attended_exams FROM Students v CROSS JOIN 
Subjects p LEFT JOIN 
Examinations e 
ON v.student_id = e.student_id AND p.subject_name = e.subject_name 
GROUP BY 
v.student_id,v.student_name,p.subject_name 
ORDER BY 
v.student_id ,p.subject_name ; 
