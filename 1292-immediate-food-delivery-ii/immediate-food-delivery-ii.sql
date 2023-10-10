SELECT 
    ROUND(
        SUM(
            CASE
                WHEN EXISTS (
                    SELECT 1 
                    FROM Delivery 
                    WHERE customer_id = t1.customer_id 
                    AND t1.order_date>order_date 
                ) 
                OR t1.order_date!=t1.customer_pref_delivery_date 
                THEN 0 
                ELSE 1
            END
        )/count(distinct(t1.customer_id))*100
    ,2) as immediate_percentage
FROM Delivery t1;
