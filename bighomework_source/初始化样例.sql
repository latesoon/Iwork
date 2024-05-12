INSERT INTO employee (employeeID, employname, sex,pwd)
VALUES
    (10001, 'bob', true,'10001'),
    (10002, 'cathy', false, '10002'),
    (10003, 'mike', true,'10003');
INSERT INTO department(departmentID,departname)
VALUES(1001,"网络部");
INSERT INTO employee (employeeID, employname,enrollmentdate,salary,job,sex,departmentID,pwd)
VALUES
    (10004, 'nike', "2004/04/26",8000,"运营",true,1001,'0');
INSERT INTO management(employeeID,managelevel)
VALUES
	(10004,5);
INSERT INTO technicist(employeeID,techlevel)
VALUES
	(10004,3);