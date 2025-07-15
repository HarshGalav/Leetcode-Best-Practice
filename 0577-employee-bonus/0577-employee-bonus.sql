# Write your MySQL query statement below
select name, bonus from Employee e left join Bonus b on e.empId=b.empId where b.bonus <1000 OR b.bonus is NULL;