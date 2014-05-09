function getData()
{
var xmlhttp;
xmlhttp=new XMLHttpRequest();
xmlhttp.onreadystatechange=function(){
if (xmlhttp.readyState==4 && xmlhttp.status==200)
{
document.getElementById("myDiv").innerHTML="";
 var record= JSON.parse(xmlhttp.responseText);
//var jsonHtmlTable = ConvertJsonToTable(record, 'jsonTable', null, 'Download');
var tab=new Array();
var idx=-1;
var lastcase="";
for (i=0;i<record.length;i++)
{
    if(record[i]["Casename"]!=lastcase)
    {
	idx++;
	tab[idx]=new Object();
	tab[idx]["Casename"]=record[i]["Casename"];
	tab[idx][record[i]["Time"]]=record[i]["Duration1"];
	i++;
	lastcase=tab[idx]["Casename"];
    };
    tab[idx][record[i]["Time"]]=record[i]["Duration1"];
};
	
var jsonHtmlTable = ConvertJsonToTable(tab, 'jsonTable', null, 'Download');

document.getElementById("myDiv").innerHTML=jsonHtmlTable ;


$( "#myChart").click(function() {
this.style.display="none";

});

$( "div >table > tbody >tr" ).click(function(event) {

    stringa = $(this).attr("value");
    record = JSON.parse(stringa);
    var data = {
	datasets : [
		{
			fillColor : "rgba(220,220,220,1)",
			strokeColor : "rgba(220,220,220,1)",
			pointColor : "rgba(220,220,220,1)",
			pointStrokeColor : "#fff",
		}
	]
};


    var d1=new Array();
    var l=new Array();
    var idx=0;
for (var i in record)
{
console.log(i+":"+record[i]);
 if (i != "Casename")
 {
  d1[idx]=record[i];
  l[idx]=i;
  idx++;
 }
};
 data["datasets"][0]["data"]=d1;
data["labels"]=l;
var ctx = document.getElementById("myChart").getContext("2d");
var myNewChart = new Chart(ctx).Line(data);
document.getElementById("myChart").style.top=(event.clientY+10)+"px";

document.getElementById("myChart").style.display="block";   
 

});
//return record;
}}
xmlhttp.open("GET","http://10.19.192.51:8888/data?database=Library&table=cuFFT",true);
xmlhttp.send(null)
};



function draw(point)
{
   var data = {
	datasets : [
		{
			fillColor : "rgba(220,220,220,0.5)",
			strokeColor : "rgba(220,220,220,1)",
			pointColor : "rgba(220,220,220,1)",
			pointStrokeColor : "#fff",
		},
		{
			fillColor : "rgba(151,187,205,0.5)",
			strokeColor : "rgba(151,187,205,1)",
			pointColor : "rgba(151,187,205,1)",
			pointStrokeColor : "#fff",
		}
	]
};
var d1=new Array();
var d2=new Array();
var l=new Array();
var idx=0;
for (var i in record)
{
  if (i != "Casename")
  {
  d1[idx]=record[i].Duration1;
  d2[idx]=record[i].Duration2;
  l[idx]=i;
  idx++;
  }
};

data["datasets"][0]["data"]=d1;
data["datasets"][1]["data"]=d2;
data["labels"]=l;
var ctx = document.getElementById("myChart").getContext("2d");
var myNewChart = new Chart(ctx).Line(data);
    
};


function show()
{
var xmlhttp;
xmlhttp=new XMLHttpRequest();
xmlhttp.onreadystatechange=function()
{
  if (xmlhttp.readyState==4 && xmlhttp.status==200)
    {
document.getElementById("myDiv").innerHTML="";
 var record= JSON.parse(xmlhttp.responseText);
var data = {
	datasets : [
		{
			fillColor : "rgba(220,220,220,0.5)",
			strokeColor : "rgba(220,220,220,1)",
			pointColor : "rgba(220,220,220,1)",
			pointStrokeColor : "#fff",
		},
		{
			fillColor : "rgba(151,187,205,0.5)",
			strokeColor : "rgba(151,187,205,1)",
			pointColor : "rgba(151,187,205,1)",
			pointStrokeColor : "#fff",
		}
	]
};
var d1=new Array();
var d2=new Array();
var l=new Array();
for (var i in record)
{
  d1[i]=record[i].Duration1;
  d2[i]=record[i].Duration2;
  l[i]=record[i].Time;
};

data["datasets"][0]["data"]=d1;
data["datasets"][1]["data"]=d2;
data["labels"]=l;
var ctx = document.getElementById("myChart").getContext("2d");
var myNewChart = new Chart(ctx).Line(data);
}
}
xmlhttp.open("GET","http://10.19.192.51:8888/data?database=Library&table=cuFFT",true);
xmlhttp.send(null);
}
