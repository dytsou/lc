CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  IF N IS NULL OR N < 1 THEN
    RETURN QUERY (
      SELECT NULL::INT AS Salary
    );
    RETURN;
  END IF;

  RETURN QUERY (
    SELECT (
      SELECT DISTINCT e.salary
      FROM Employee e
      ORDER BY e.salary DESC
      LIMIT 1 OFFSET N-1
    ) AS Salary
  );
END;
$$ LANGUAGE plpgsql;
