# Write your MySQL query statement below
select t2.unique_id,t1.name from Employees t1 left join EmployeeUNI t2 on t2.id=t1.id