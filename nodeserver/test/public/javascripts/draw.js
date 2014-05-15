var tab;
var recordsPerPage;
var page;
var rootelement;
var header;
function Next()
{
	if(page<Math.ceil(tab.length/recordsPerPage))
	{
		rootelement.innerHTML="";
		addHeader(rootelement,header);
		for(var k=page*recordsPerPage;k<(page+1)*recordsPerPage;k++)
		{
			setRow(rootelement,tab[k]);
		};
		page++;
	}
}

function Back()
{
	if(page>=2)
	{
		rootelement.innerHTML="";
		addHeader(rootelement,header);
		for(var k=(page-2)*recordsPerPage;k<(page-1)*recordsPerPage;k++)
		{
			setRow(rootelement,tab[k]);
		};
	page--;
	}
};



function getData()
{
var xmlhttp;
xmlhttp=new XMLHttpRequest();
xmlhttp.onreadystatechange=function(){
if (xmlhttp.readyState==4 && xmlhttp.status==200)
{
document.getElementById("myChart").onclick=function() {
this.style.display="none";
};


rootelement=document.getElementById("myDiv");
document.getElementById("myDiv").innerHTML="";
recordsPerPage=1000;
page=1;
var record= JSON.parse(xmlhttp.responseText);
tab=new Array();
var idx=-1;
var lastcase="";
header=new Object();
for(i=0;i<record.length;i++)
{
	header[record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=0;
};
addHeader(rootelement,header);
for (i=0;i<record.length;i++)
{
    if(record[i]["Casename"]!=lastcase)
    {	
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
for(var k=0;k<page*recordsPerPage;k++)
{
	setRow(rootelement,tab[k]);
};
//var jsonHtmlTable = ConvertJsonToTable(tab, 'jsonTable', null, 'Download');

//document.getElementById("myDiv").innerHTML=jsonHtmlTable ;



}};
xmlhttp.open("GET","/data?database=Library&table=cuFFT",true);
xmlhttp.send(null);
};


function addHeader(root,row)
{
        var p = document.createElement("div");
        p.className="Row";
	p.setAttribute("id","header");
        var subp=document.createElement("div");
        subp.className="Cell";
        subp.appendChild(document.createTextNode("Casename"));
        p.appendChild(subp);

        for(var i in row)
        {
                subp=document.createElement("div");
                subp.className="Cell";
		var ar=i.split("_");
		for(var j in ar)
		{
			subp.innerHTML="date:"+ar[0]+"<br/>"
                        +"driver:"+ar[1]+"<br/>"
                        +"CL:"+ar[2];
                	p.appendChild(subp);
		};
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


