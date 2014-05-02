CREATE DATABASE if not exists Curand;
USE Curand;

CREATE TABLE if not exists test
(
 Id int auto_increment primary key not null,
 Casename varchar(1024) not null,
 Time varchar(30),
 Result varchar(30),
 Duration1 varchar(30),
 Duration2 varchar(30),
 Log varchar(4096)
);
