# Write your MySQL query statement below
select t1.name,t2.bonus from Employee t1 left join Bonus t2 on t1.empId=t2.empId where t2.bonus<1000 or t2.bonus is null