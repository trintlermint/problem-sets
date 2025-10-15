-- #Accepted 8 / 8 testcases passed N. Adhikary submitted at Oct 16, 2025 00:37 Runtime 413ms Beats37.48%

SELECT 
    p.firstName, 
    p.lastName, 
    a.city, 
    a.state
FROM 
    Person p
LEFT JOIN 
    Address a
ON 
    p.personId = a.personId;
