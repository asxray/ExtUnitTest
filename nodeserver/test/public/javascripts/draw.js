var tab;
var current_tab;
var recordsPerPage;
var page;
var rootelement;
var header;
var header_array;
var tb;
function SearchRecordByRegex()
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

function NextPage()
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

function PreviousPage()
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


function RearrangeRecordAndHeader(record)
{
	tab=new Array();
	header=new Object();
	header_array=new Array();
	casename_hash=new Object();
	for(var i=0;i<record.length;i++)
	{
        	header[record[i]["Time"]+"_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=0;
        	casename_hash[record[i]["Casename"]]=0;
	};
	var tabidx=0;
	for(var i in casename_hash)
	{
       		tab[tabidx]=new Object();
        	tab[tabidx]["Casename"]=i;
        	casename_hash[i]=tabidx;
        	for( var a in header)
        	{
                	tab[tabidx][a]=0;
        	};
        	tabidx++;
	};
	for( var i in header)
	{
        	header_array.push(i);
	}
	header_array.sort();
	addHeader(rootelement,header_array);
	for (var i=0;i<record.length;i++)
	{
       		tab[casename_hash[record[i]["Casename"]]][record[i]["Time"]+ "_"+record[i]["DriverVersion"]+"_"+record[i]["CL"]]=record[i]["Duration1"];
	};
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
		RearrangeRecordAndHeader(record);
		current_tab=tab;
		for(var k=0;k<page*recordsPerPage && k<tab.length ;k++)
		{
			setRow(rootelement,tab[k],header_array);
		};
	}
	};
	tb=document.getElementById("select_id").value;
	if(tb != "Select")
	{
		xmlhttp.open("GET","/data?database=Library&table="+tb,true);
		xmlhttp.send(null);
	}else
	{
		document.getElementById("myDiv").innerHTML="";	
	};
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
			var date=ar[0].substring(0,4)+"-"+ar[0].substring(4,6)+"-"+ar[0].substring(6,8);
			subp.innerHTML="date:"+date+"<br/>"
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
			subp.innerHTML=row[headerArray[i]];
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
                        strokeColor : "rgba(220,220,220,1)",
                        pointColor : "rgba(151,187,205,1)",
                        pointStrokeColor : "#fff",
                },
		{
			fillColor : "rgba(220,220,220,0.5)",
			strokeColor : "rgba(220,220,220,1)",
			pointColor : "rgba(220,220,220,1)",
			pointStrokeColor : "#fff",
		}
        	]
	};
var row1=new Array();
var row2=new Array();
for(var i=0;i<rowdata.length;i++)
{
	var rowStr=rowdata[i]+"";
	var ar=rowStr.split("<br/>");
	row1.push(ar[0]);
	if(ar.length>1)
		row2.push(ar[1]);
	else
		row2.push(0);
}
data["datasets"][0]["data"]=row1;
data["datasets"][1]["data"]=row2;
var chartHeader=new Array();
for(var i=0;i<headerArray.length;i++)
{
        var ar=headerArray[i].split("_");
        var date=ar[0].substring(0,4)+"-"+ar[0].substring(4,6)+"-"+ar[0].substring(6,8);
	chartHeader.push(date);
};
data["labels"]=chartHeader;
var ctx = document.getElementById("myChart").getContext("2d");
var max_1=Math.max.apply(null,row1);
var max_2=Math.max.apply(null,row2);
var step=10;
var option=
{
    scaleOverride: true,
    scaleSteps: step,
    scaleStepWidth: Math.ceil((max_1>max_2?max_1:max_2) / step * 1.5),
    scaleStartValue: 0
};
var myNewChart = new Chart(ctx).Line(data,option);
document.getElementById("myChart").style.top=(window.pageYOffset+event.clientY+10)+"px";
document.getElementById("myChart").style.display="block";
};
