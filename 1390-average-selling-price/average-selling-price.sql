# Write your MySQL query statement below
select t1.product_id,round((sum(t2.units*t1.price))/(sum(t2.units)),2) as average_price from Prices t1 inner join UnitsSold t2 on t1.product_id=t2.product_id where t2.purchase_date>=t1.start_date and t2.purchase_date<=t1.end_date group by product_id