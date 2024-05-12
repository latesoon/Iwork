create table branchoffice(
officeID int primary key,
officename char(20),
officelocation char(200) );
create table employee(
employeeID int primary key,
pwd char(20), 
  employname char(20) not null,
  enrollmentdate char(20),
  salary float,
  job char(40),
  sex bit,
  departmentID int);   
create table department(
  departmentID int primary key,
  departname char(40),
officeID int,
employeeID int,
foreign key (employeeID) references employee(employeeID) on update cascade on delete cascade);
create table joinn(
  employeeID int,
  projectID int,
primary key (employeeID,projectID),
foreign key (employeeID) references employee(employeeID) on update cascade on delete cascade);
create table technicist(
  techlevel smallint,
  category char(20),
employeeID int primary key,
foreign key (employeeID) references employee(employeeID) on update cascade on delete cascade);
create table management(
  employeeID int primary key,
  managelevel smallint,
  boss integer,
  foreign key (boss) references department(departmentID) on update cascade on delete cascade,
  foreign key (employeeID) references employee(employeeID) on update cascade on delete cascade);
create table project(
  projectID int primary key,
  resoffice int,
  principle int,
  projectname char(40),
  budget int,
  estimatedrevenue int,
  startdate char(20),
  enddate char(20),
  foreign key (resoffice) references branchoffice(officeID) on update cascade on delete cascade,
  foreign key(principle) references employee(employeeID) on update cascade on delete cascade);
alter table employee add foreign key(departmentID) references department(departmentID) on update cascade on delete cascade;
alter table department add foreign key(officeID) references branchoffice(officeID) on update cascade on delete cascade;
alter table joinn add foreign key(projectID) references project(projectID) on update cascade on delete cascade;