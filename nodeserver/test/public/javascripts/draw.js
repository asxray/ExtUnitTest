function getData()
{
var xmlhttp;
xmlhttp=new XMLHttpRequest();
xmlhttp.onreadystatechange=function(){
if (xmlhttp.readyState==4 && xmlhttp.status==200)
{
document.getElementById("myDiv").innerHTML="";

var record= JSON.parse(xmlhttp.responseText);
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
	tab[idx][record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=record[i]["Duration1"];
	i++;
	if(i>=record.length)
		break;
	lastcase=tab[idx]["Casename"];
    };
    tab[idx][record[i]["Time"]+ "_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=record[i]["Duration1"];
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
			fillColor : "rgba(151,187,205,0.5)",
			strokeColor : "rgba(0,0,60,1)",
			pointColor : "rgba(151,187,205,1)",
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
 }else
 {
    data["datasets"][0]["title"]=record[i];
 }
};
 data["datasets"][0]["data"]=d1;
data["labels"]=l;
var ctx = document.getElementById("myChart").getContext("2d");
var max_=Math.max.apply(null,d1);
var step=10;
var option= 
{
    scaleOverride: true,
    scaleSteps: step,
    scaleStepWidth: Math.ceil(max_ / step * 1.5),
    scaleStartValue: 0
};
var myNewChart = new Chart(ctx).Line(data,option);
document.getElementById("myChart").style.top=(window.pageYOffset+event.clientY+10)+"px";

document.getElementById("myChart").style.display="block";   
 

});
}}
xmlhttp.open("GET","/data?database=Library&table=cuFFT",true);
xmlhttp.send(null)
};


