# Write your MySQL query statement below
select 
t1.name 
from 
Employee t1 
cross join 
Employee t2 
where t1.id=t2.managerId
group by t1.id,t1.name
having 
count(t1.name)>=5
order by t1.id,t2.id

