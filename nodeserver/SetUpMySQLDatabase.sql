DROP DATABASE Runtime;
DROP DATABASE Library;

CREATE DATABASE if not exists Runtime;
USE Runtime;
/*
create runtime tables
*/

CREATE DATABASE if not exists Library;
USE Library;
CREATE TABLE if not exists cuFFT
(
 Id int auto_increment primary key not null,
 Casename varchar(1024) not null,
 Time bigint,
 Result ENUM("PASSED", "FAILED", "WAIVED","ERROR"),
 Duration1 int,
 Duration2 int,
 DriverVersion int,
 CL int,
 Log varchar(4096)
);

CREATE TABLE if not exists cuRAND
(
 Id int auto_increment primary key not null,
 Casename varchar(1024) not null,
 Time bigint,
 Result ENUM("PASSED", "FAILED", "WAIVED","ERROR"),
 Duration1 int,
 Duration2 int,
 DriverVersion int,
 CL int,
 Log varchar(4096)
);


