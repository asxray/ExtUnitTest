var sys = require('sys');
var aSql = require('mysql');
var express = require("express");
var app = express();

function getSQL(databasename,tablename,callback){
    var client = aSql.createConnection({
	host: "10.19.192.13",
	user: "root",
	password: "1",
    });
    client.query("USE " + databasename);
    client.query("SELECT * from " + tablename , function(err, result){
	callback(err, result);
    });
    client.end();
}

app.get('/',function(req,res){
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
    };
    getSQL(req.param('database'),req.param('table'),writeResp);

})
app.listen(8888);
console.log("Server has started.");
