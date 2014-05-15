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

header=new Object();
for(i=0;i<record.length;i++)
{
	header[record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=0;
};
var rootelement=document.getElementById("myDiv");
addHeader(rootelement,header);
for (i=0;i<record.length;i++)
{
    if(record[i]["Casename"]!=lastcase)
    {	
	if(idx>=0)
	{
		setRow(rootelement,tab[idx]);	
	};
	idx++;
	tab[idx]=new Object();
	tab[idx]["Casename"]=record[i]["Casename"];
	for( a in header)
	{
		if(a!=record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"])
		{
			tab[idx][a]=0;
		}else
		{
			tab[idx][record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=record[i]["Duration1"];
		}
	};
	i++;
	if(i>=record.length)
		break;
	lastcase=tab[idx]["Casename"];
    };
    tab[idx][record[i]["Time"]+ "_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=record[i]["Duration1"];
    
};
if(idx>=0)
{
	setRow(rootelement,tab[idx]);
};

	
//var jsonHtmlTable = ConvertJsonToTable(tab, 'jsonTable', null, 'Download');

//document.getElementById("myDiv").innerHTML=jsonHtmlTable ;
function addHeader(root,row)
{
        var p = document.createElement("div");
        p.className="Row";
        var subp=document.createElement("div");
        subp.className="Cell";
        subp.appendChild(document.createTextNode("Casename"));
        p.appendChild(subp);

        for(var i in row)
        {
                subp=document.createElement("div");
                subp.className="Cell";
                subp.appendChild(document.createTextNode(i));
                p.appendChild(subp);
        }
	root.appendChild(p);
};

function setRow(root,row){
	var p = document.createElement("div");
	p.className="Row";
	for(var i in row)
	{
		var subp=document.createElement("div");
		subp.className="Cell";
		subp.appendChild(document.createTextNode(row[i]));
		p.appendChild(subp);
	}
	p.onclick = function () {drawRowData(row);};
	root.appendChild(p);
}

$( "#myChart").click(function() {
this.style.display="none";

});

function drawRowData(rowdata)
{
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
for (var i in rowdata)
{
 if (i != "Casename")
 {
  d1[idx]=rowdata[i];
  l[idx]=i;
  idx++;
 }else
 {
    data["datasets"][0]["title"]=rowdata[i];
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

};


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


