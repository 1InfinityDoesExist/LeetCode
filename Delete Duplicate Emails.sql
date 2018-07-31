# Write your MySQL query statement below
delete x
from Person x, Person y
where x.email = y.email
and x.Id > y.Id;
