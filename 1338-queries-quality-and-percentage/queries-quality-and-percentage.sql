# Write your MySQL query statement below
select q2.query_name,round((sum((q2.rating/q2.position))/count(q2.query_name)),2) as quality,round(((select count(q1.rating) from Queries q1 where rating<3 and q1.query_name=q2.query_name)/count(query_name)*100),2) as poor_query_percentage
from Queries q2
group by query_name