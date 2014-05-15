var sys = require('sys');
var aSql = require('mysql');
var express = require("express");
var app = express();
app.use(express.compress());
app.use(express.static('public'));
function getSQL(databasename,tablename,callback){
console.log("getSQL");
    var client = aSql.createConnection({
	host: "127.0.0.1",
	user: "root",
	password: "1",
    });
    var query="SELECT Casename,Time,Duration1,DriverVersion,CL FROM "+tablename +" AS t1 WHERE t1.Result=\"PASSED\" and  t1.Time in (SELECT  Time from (SELECT DISTINCT Time FROM "+ tablename +" ORDER BY Time DESC LIMIT 0,10) as t2) ORDER BY Casename,Time;";
  console.log(query);
 client.query("USE "+databasename);
 client.query(query, function (err, result){
console.log("error:"+err);
callback(err,result);	
});
    
       
    //client.query("SELECT * from " + tablename , function(err, result){
    //	callback(err, result);
    //});
    client.end();
}

app.get('/',function(req,res){
console.log("request /");
res.redirect(index.html);
});

app.get('/data',function(req,res){
console.log("request /data");
    if(0 == req.param('database').length || 0 == req.param('table').length){
	console.log("empty database or table");
	return;
    }

    var writeResp = function (err, result){
	res.set('Content-Type', 'text/plain');
	if(err){
	    res.send(err);
	}
	else{
	    res.send(200,JSON.stringify(result));
	};
	res.end();
	console.log("sent.");
    };
    getSQL(req.param('database'),req.param('table'),writeResp);

})
app.listen(8888);
console.log("Server has started.");
