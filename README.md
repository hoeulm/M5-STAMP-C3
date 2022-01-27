# M5-STAMP-C3
Programms for M5 Stack Stamp C3 with Arduino IDE
![m5stampc3](https://user-images.githubusercontent.com/78592626/151159515-19b53a94-3303-4e2f-9a99-7310c0dba864.gif)
<svg viewBox='0 0 330 200' xmlns='http://www.w3.org/2000/svg'>
	<rect x='0' y='0' rx='9'   ry='9' width='330' height='200' fill='black' />
	<path stroke-width='4' stroke='gray' d='M80,50 h 50 a 10 10 0 0 1 10 10 v80 a 10 10 0 0 1 -10 10 h-50' ><title>Button Port=3</title></path>
	<rect fill='#C0C0C0'  x='0' y='60' width='70' height='80'><title>USB C</title></rect>
	<rect id='ledcol' fill='magenta' x='110' y='75' rx='5' ry='5' width='12' height='50'  ><title>LED SK6812 / Port=2</title></rect>
	<path fill='#A0A0A0' d='M276,40h40v50h-30v60h10v-5h-5v-50h25v60h-40z'><title>WiFi Antenna 3D</title></path>
	<path stroke-width='4' stroke='gray' stroke='red' fill='none' d='M202,70 l35,-35 a 10 10 0 0 1 20 20 l-35,35' ><title>Reset</title></path>
	<circle cx='245' cy='47' r='10' fill='gray'><title>RESET</title></circle>
	<circle cx='186' cy='100' r='18' fill='silver' />
	<path fill='orange' d='M179,88 h14 l9,12l-9,12 h-14l-9,-12l9,-12' ></path>
	<circle cx='186' cy='100' r='7' fill='silver' />
<g transform='translate(0 10)' >
	<circle id='LED' cx= '25.4' cy= '0' r= '8' fill='gold'  ><title>G0</title></circle>
	<circle id='LED' cx= '50.8' cy= '0' r=' 8' fill='gold'  ><title>G1</title></circle>
	<circle id='LED' cx= '76.2' cy= '0' r= '8' fill='red'   ><title>5V</title></circle>
	<circle id='LED' cx='101.6' cy= '0' r=' 8' fill='gray'  ><title>GND</title></circle>
	<circle id='LED' cx='127.0' cy= '0' r= '8' fill='red'   ><title>5V</title></circle>
	<circle id='LED' cx='152.4' cy= '0' r=' 8' fill='gold'  ><title>10</title></circle>
	<circle id='LED' cx='177.8' cy= '0' r= '8' fill='gold'  ><title>8</title></circle>
	<circle id='LED' cx='203.2' cy= '0' r=' 8' fill='gold'  ><title>7</title></circle>
	<circle id='LED' cx='228.6' cy= '0' r= '8' fill='gold'  ><title>6</title></circle>
	<circle id='LED' cx='254.0' cy= '0' r=' 8' fill='gold'  ><title>5</title></circle>
	<circle id='LED' cx='279.4' cy= '0' r= '8' fill='gold'  ><title>4</title></circle>
	<circle id='LED' cx='304.8' cy= '0' r=' 8' fill='gray'  ><title>GND</title></circle>
</g>
<g transform='translate(0 190)'>
	<circle id='LED' cx= '25.4' cy= '0' r= '8' fill='gray'  ><title>GND</title></circle>
	<circle id='LED' cx= '50.8' cy= '0' r=' 8' fill='red'   ><title>5V</title></circle>
	<circle id='LED' cx= '76.2' cy= '0' r= '8' fill='gold'  ><title>USB D+ 19</title></circle>
	<circle id='LED' cx='101.6' cy= '0' r=' 8' fill='gold'  ><title>USB D- 18</title></circle>
	<circle id='LED' cx='127.0' cy= '0' r= '8' fill='gray'  ><title>GND</title></circle>
	<circle id='LED' cx='152.4' cy= '0' r=' 8' fill='gold'  ><title> 9</title></circle>
	<circle id='LED' cx='177.8' cy= '0' r= '8' fill='gold'  ><title>ENABLE</title></circle>
	<circle id='LED' cx='203.2' cy= '0' r=' 8' fill='gold'  ><title>Serial Rx 20 C3 in</title></circle>
	<circle id='LED' cx='228.6' cy= '0' r= '8' fill='gold'  ><title>Serial Tx 21 C3 out</title></circle>
	<circle id='LED' cx='254.0' cy= '0' r=' 8' fill='orange'><title>3V3</title></circle>
</g>
</svg><br/>
<script>
var i_cnt=0
var eidled=document.getElementById('ledcol');
function changecol()
{
	if(i_cnt&4){s_col='#FF';} else {s_col='#00';}
	if(i_cnt&2){s_col+='FF';} else {s_col+='00';}
	if(i_cnt&1){s_col+='FF';} else {s_col+='00';}
	eidled.setAttribute('fill',s_col);
	i_cnt++; if(i_cnt>7){i_cnt=0;}
}
setInterval(changecol,1000);
</script>
