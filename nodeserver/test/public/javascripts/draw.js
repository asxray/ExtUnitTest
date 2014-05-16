var tab;
var current_tab;
var recordsPerPage;
var page;
var rootelement;
var header;
var header_array;
function Search()
{
	rootelement.innerHTML="";
	addHeader(rootelement,header_array);
	var pattern=document.getElementById("input").value;
	var regx=new RegExp(pattern);
	delete current_tab;
	current_tab=new Array();
	for(var i=0;i<tab.length;i++)
	{
		if(tab[i]["Casename"].match(regx))
		{
			current_tab.push(tab[i]);
			
		}
	};
	page=1;
	for(var k=0;k<page*recordsPerPage && k<current_tab.length ;k++)
	{	
       		 setRow(rootelement,current_tab[k],header_array);
	};
};


function Next()
{
	if(page<Math.ceil(current_tab.length/recordsPerPage))
	{
		rootelement.innerHTML="";
		addHeader(rootelement,header_array);
		for(var k=page*recordsPerPage;k<(page+1)*recordsPerPage && k < current_tab.length ;k++)
		{
			setRow(rootelement,current_tab[k],header_array);
		};
		page++;
	}
}

function Back()
{
	if(page>=2)
	{
		rootelement.innerHTML="";
		addHeader(rootelement,header_array);
		for(var k=(page-2)*recordsPerPage;k<(page-1)*recordsPerPage && k<current_tab.length ;k++)
		{
			setRow(rootelement,current_tab[k],header_array);
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
header_array=new Array();

for(var i=0;i<record.length;i++)
{
	header[record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=0;
};
for( var i in header)
{
	header_array.push(i);
}
header_array.sort();
addHeader(rootelement,header_array);
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

current_tab=tab;
for(var k=0;k<page*recordsPerPage && k<tab.length ;k++)
{
	setRow(rootelement,tab[k],header_array);
};

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

        for(var i=0;i<row.length;i++)
        {
                subp=document.createElement("div");
                subp.className="Cell";
		var ar=row[i].split("_");
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

function setRow(root,row,headerArray){
	var p = document.createElement("div");
	p.className="Row";
	var sortedRow=new Array();
	for(var i=-1;i<headerArray.length;i++)
	{
		var subp=document.createElement("div");
		subp.className="Cell";
		if(i==-1)
		{
			subp.appendChild(document.createTextNode(row["Casename"]));
		}else
		{
			subp.appendChild(document.createTextNode(row[headerArray[i]]));	
			sortedRow.push(row[headerArray[i]]);
		};
		p.appendChild(subp);
	}
	p.onclick = function () {drawRowData(row["Casename"],sortedRow,headerArray);};
	root.appendChild(p);
}




function drawRowData(casename, rowdata, headerArray)
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
data["datasets"][0]["title"]=casename;
data["datasets"][0]["data"]=rowdata;
data["labels"]=headerArray;
var ctx = document.getElementById("myChart").getContext("2d");
var max_=Math.max.apply(null,rowdata);
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


