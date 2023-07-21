# Write your MySQL query statement below
select salary as SecondHighestSalary
from Employee union (select null)
order by SecondHighestSalary desc
limit 1
offset 1