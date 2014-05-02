var http = require("http");
var sys = require('sys');
var aSql = require('mysql');
var url = require("url");

function getSQL(callback){
    var tablename = "test";
    var client = aSql.createConnection({
	host: "10.19.192.51",
	user: "root",
	password: "1",
	database : "CUFFT"
    });
    client.query("SELECT * from " + tablename , function(err, result){
	callback(err, result);
    });
    client.end();
}

function onRequest(request, response) {
    console.log("Request: " + request.url);
    var writeResp = function (err, result){
	response.writeHead(200, {"Content-Type": "text/plain"});
	if(err){
	    response.write(err);
	}
	else{
	    response.write(JSON.stringify(result));
	}
	response.end();
	console.log("sent.");
    };
    getSQL(writeResp);
}

http.createServer(onRequest).listen(8888);

console.log("Server has started.");
