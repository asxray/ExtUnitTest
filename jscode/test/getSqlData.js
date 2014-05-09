var sys = require('sys');
var aSql = require('mysql');
var express = require("express");
var app = express();

app.use(express.static('public'));

function getSQL(databasename,tablename,callback){
    var client = aSql.createConnection({
	host: "10.19.192.51",
	user: "root",
	password: "1",
    });
    client.query("USE " + databasename);
    var query="SELECT Casename,Time,Duration1 FROM "+tablename +" AS t1 WHERE t1.Time in (SELECT  Time from (SELECT DISTINCT Time from "+ tablename +" ORDER BY Time DESC LIMIT 0,5) as t2) ORDER BY Casename,Time";
  console.log(query);
 client.query(query, function (err, result){
callback(err,result);	

});
    
       
    //client.query("SELECT * from " + tablename , function(err, result){
    //	callback(err, result);
    //});
    client.end();
}

app.get('/',function(req,res){
res.redirect(index.html);
});

app.get('/data',function(req,res){
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
	console.log("sent.");
	console.log(JSON.stringify(result));
    };
    getSQL(req.param('database'),req.param('table'),writeResp);

})
app.listen(8888);
console.log("Server has started.");
