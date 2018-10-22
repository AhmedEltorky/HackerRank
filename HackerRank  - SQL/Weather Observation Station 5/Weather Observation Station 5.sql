/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/

SELECT top(1) CITY, len(CITY)
FROM STATION
order by len(CITY), CITY;
SELECT top(1) CITY, len(CITY)
FROM STATION
order by len(CITY) desc, CITY desc;