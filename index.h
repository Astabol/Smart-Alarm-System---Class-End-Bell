

const char LOGIN_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title> login page</title>

<style>
body
{

background-image:url(http://tadalafilforsale.net/data/media/33/55385213.jpg);

height: 100vh;
background-size:80%;

}

form
{

background-color:black;
font-size:20px;
padding:30px;
color:black ;
text-align: center;
position: absolute;
left:950px;
top:150px;
 
}

 

</style>

</head>
<body>

<h1 style="text-decoration: underline;color:#FFA500;text-align:center">IOT Based Smart Alam System</h1>
<form >
 <h2 style="color:#FFA500;text-align:left">LOGIN FORM</h2> 

 <p style="color:#FFA500;text-align:left">USERNAME</p>
 <input type="text" name="USERNAME" placeholder="User Name">

 <p style="color:#FFA500;text-align:left">PASSWORD</p>
 <input type ="password" name="PASSWORD" placeholder="password"><br><br>
 <input type='submit' name='SUBMIT' value='Login'>
</form>
</body>
</html>



)=====";




/*const char HOME_PAGE[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h style="color: #3333ff;">Present Time:</h>
</br>
</br>
<h style="color:#3333ff;">Present Date:</h>
</br>
</br>
</br>
</br>


<h style="color:#3333ff;">Set Present Time:</h>
</br>
<input type="text" name="HH_PRE" size= 2% placeholder="HH">
<input type="text" name="MM_PRE" size= 2% placeholder="MM">
<input type="text" name="SS_PRE" size= 2% placeholder="SS">
<input type="submit" name="SET_PRE_TIME" value="set" style=background-color:#99cc00; size= 40% >
</br>
</br>
</br>

<h style="color:#3333ff;">Set Present Date:</h>
</br>
<input type="text" name="DD_PRE" size= 2% placeholder="DD">
<input type="text" name="MO_PRE" size= 2% placeholder="MO">
<input type="text" name="YYYY_PRE" size= 10S% placeholder="YYYY">
<input type="submit" name="SET_PRE_DATE" value="set" style=background-color:#99cc00; size= 40% >
</br>
</br>
</br>
<h2 style=" text-decoration: underline;color:blue;text-align:center">SET ALAM </h2>
<hr color= #3399ff style=width:90%;>
</br>
</br>

<h3> Alam No: 1</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<form>
<input type="text" name="HH_ALARM1" size= 2% placeholder="HH">
<input type="text" name="MM_ALARM1" size= 2% placeholder="MM">
<input type="text" name="SS_ALARM1" size= 2% placeholder="SS">
</br>
<h style="color:#3333ff;">Set Delay Time :--</h>
<input type="text" size= 5% placeholder="mili sec">
</br>
</br>
<input type="submit" name="SUBMIT" value="set" style=background-color:#99cc00; size= 40% >
<button style="background-color:#ff5050; size= 100%">clear1</button>
</form>

</br>
</br>

<h3> Alam No: 2</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<input type="text" size= 2% placeholder="HH">
<input type="text" size= 2% placeholder="MM">
<input type="text" size= 2% placeholder="SS">
</br>
<h style="color:#3333ff;">Set Delay Time :--</h>
<input type="text" size= 5% placeholder="mili sec">
</br>
</br>
<button style=background-color:#99cc00; size= 40% >a2set</button>
<button style="background-color:#ff5050; size= 100%">clear2</button>

</br>
</br>

<h3> Alam No: 3</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<input type="text" size= 2% placeholder="HH">
<input type="text" size= 2% placeholder="MM">
<input type="text" size= 2% placeholder="SS">
</br>
<h style="color:#3333ff;">Set Delay Time :--</h>
<input type="text" size= 5% placeholder="mili sec">
</br>
</br>
<button style=background-color:#99cc00; size= 40% >a3set</button>
<button style="background-color:#ff5050; size= 100%">clear3</button>

</br>
</br>

<h3> Alam No: 4</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<input type="text" size= 2% placeholder="HH">
<input type="text" size= 2% placeholder="MM">
<input type="text" size= 2% placeholder="SS">
</br>
<h style="color:#3333ff;">Set Delay Time :--</h>
<input type="text" size= 5% placeholder="mili sec">
</br>
</br>
<button style=background-color:#99cc00; size= 40% >a4set</button>
<button style="background-color:#ff5050; size= 100%">clear4</button>

</br>
</br>

<h3> Alam No: 5</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<input type="text" size= 2% placeholder="HH">
<input type="text" size= 2% placeholder="MM">
<input type="text" size= 2% placeholder="SS">
</br>
<h style="color:#3333ff;">Set Delay Time :--</h>
<input type="text" size= 5% placeholder="mili sec">
</br>
</br>
<button style=background-color:#99cc00; size= 40% >a5set</button>
<button style="background-color:#ff5050; size= 100%">clear5</button>


</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</br>
</body>
</html
</html


)=====";
*/
/*const char HOME_PAGE[] PROGMEM = R"=====(
)=====";*/


const char ALARM_FORM[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h2 style=" text-decoration: underline;color:blue;text-align:center">SET ALAM </h2>
</br>

<h3> Alam No: 1</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<form>
<input type="text" name="HH_ALARM1" size= 2% placeholder="HH">
<input type="text" name="MM_ALARM1" size= 2% placeholder="MM">
<input type="text" name="SS_ALARM1" size= 2% placeholder="SS">

</br>
</br>
<input type="submit" name="SUBMIT" value="set" style=background-color:#99cc00; size= 40% >
<button style="background-color:#ff5050; size= 100%">clear</button>
</form>

</br>
</br>

<h3> Alam No: 2</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<form>
<input type="text" name="HH_ALARM2" size= 2% placeholder="HH">
<input type="text" name="MM_ALARM2" size= 2% placeholder="MM">
<input type="text" name="SS_ALARM2" size= 2% placeholder="SS">
</br>
</br>
<input type="submit" name="SUBMIT" value="set" style=background-color:#99cc00; size= 40% >
<button style="background-color:#ff5050; size= 100%">clear</button>
</form>

</br>
</br>

<h3> Alam No: 3</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<form>
<input type="text" name="HH_ALARM3" size= 2% placeholder="HH">
<input type="text" name="MM_ALARM3" size= 2% placeholder="MM">
<input type="text" name="SS_ALARM3" size= 2% placeholder="SS">

</br>
</br>
<input type="submit" name="SUBMIT" value="set" style=background-color:#99cc00; size= 40% >
<button style="background-color:#ff5050; size= 100%">clear</button>
</form>

</br>
</br>

<h3> Alam No: 4</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<form>
<input type="text" name="HH_ALARM4" size= 2% placeholder="HH">
<input type="text" name="MM_ALARM4" size= 2% placeholder="MM">
<input type="text" name="SS_ALARM4" size= 2% placeholder="SS">

</br>
</br>
<input type="submit" name="SUBMIT" value="set" style=background-color:#99cc00; size= 40% >
<button style="background-color:#ff5050; size= 100%">clear</button>
</form>

</br>
</br>

<h3> Alam No: 5</h3>
<h style="color:#3333ff;">Set Time :----------</h>
<form>
<input type="text" name="HH_ALARM5" size= 2% placeholder="HH">
<input type="text" name="MM_ALARM5" size= 2% placeholder="MM">
<input type="text" name="SS_ALARM5" size= 2% placeholder="SS">

</br>
</br>
<input type="submit" name="SUBMIT" value="set" style=background-color:#99cc00; size= 40% >
<button style="background-color:#ff5050; size= 100%">clear</button>
</form>
<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html

)=====";



const char SHOW_DATE[] PROGMEM = R"=====(
 <!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h style="color: #3333ff;">Present Time- @@H@@:@@M@@:@@S@@</h>
</br>
</br>
<h style="color:#3333ff;">Present Date- @@D@@:@@MO@@:@@Y@@</h>
</br>
</br>
</br>
</br>


<h style="color:#3333ff;">Set Present Time:</h>
</br>
<form>
<input type="text" name="HH_PRE" size= 2% placeholder="HH">
<input type="text" name="MM_PRE" size= 2% placeholder="MM">
<input type="text" name="SS_PRE" size= 2% placeholder="SS">

</br>
</br>
</br>

<h style="color:#3333ff;">Set Present Date:</h>
</br>
<input type="text" name="DD_PRE" size= 2% placeholder="DD">
<input type="text" name="MO_PRE" size= 2% placeholder="MO">
<input type="text" name="YYYY_PRE" size= 10S% placeholder="YYYY">
</br>
</br>
<input type="submit" name="SET_PRE_DATE" value="Set Date & Time" style=background-color:#99cc00; size= 40% >
</form>
</br>
</br>
</br>
<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html


)=====";

const char ALARM_SET[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h2 style=" text-decoration: underline;color:blue;text-align:center">Your alarm has been set! </h2>
</br>

<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html

)=====";

const char HOME_PAGE[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>
<form action='/?ALARM=YES' method='POST'>
<input type="submit" name="SUBMIT" value="SET ALARM" style=background-color:#99cc00; size= 100% >
</form>
</br></br>
<form action='/?ALARM_STATUS=YES' method='POST'>
<input type="submit" name="SUBMIT" value="ALARM STATUS" style=background-color:#99cc00; size= 100% >
</form>
</br></br>
<form action='/?RESET_DATE=YES' method='POST'>
<input type="submit" name="SUBMIT" value="SHOW & RESET TIME & DATE" style=background-color:#99cc00; size= 100% >
</form>
</br></br>
<form action='/?HOME_AUTOMATION=YES' method='POST'>
<input type="submit" name="SUBMIT" value="CONTROL AC APPLIANCES" style=background-color:#99cc00; size= 100% >
</form>
</br>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>
</body>
</html
</html

)=====";

const char STATUS_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h2 style=" text-decoration: underline;color:blue;text-align:center">Your First alarm is: @@SET1@@ </h2>
</br>
<h2 style=" text-decoration: underline;color:blue;text-align:center">Your Second alarm is: @@SET2@@  </h2>
</br>
<h2 style=" text-decoration: underline;color:blue;text-align:center">Your Third alarm is: @@SET3@@  </h2>
<br>
<h2 style=" text-decoration: underline;color:blue;text-align:center">Your Forth alarm is: @@SET4@@  </h2>
<br>
<h2 style=" text-decoration: underline;color:blue;text-align:center">Your Fifth alarmis:  @@SET5@@  </h2>

<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html



)=====";

const char PRETIME_SET[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h2 style=" text-decoration: underline;color:blue;text-align:center">Your Time and Date has been set! </h2>
</br>

<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html

)=====";

const char APPLIANCES_ON[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h2 style=" text-decoration: underline;color:blue;text-align:center">Your appliances is set to ON! </h2>
</br>

<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html

)=====";

const char APPLIANCES_OFF[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>

<h2 style=" text-decoration: underline;color:blue;text-align:center">Your appliances is set to OFF! </h2>
</br>

<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>

</body>
</html
</html

)=====";

const char APPLIANCES[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>

<body style=background-color:powderblue;>

<h1 style="color:blue;text-align:center" >SMART ALAM SYSTEM</h1>


<hr color= #3399ff style=width:90%;>
<hr color=  #3399ff style=width:90%;>
</br>
</br>
</br>
<form action='/?LED_ON=YES' method='POST'>
<input type="submit" name="SUBMIT" value="TURN ON APPLIANCE" style=background-color:#99cc00; size= 100% >
</form>
</br>
<form action='/?LED_OFF=YES' method='POST'>
<input type="submit" name="SUBMIT" value="TURN OFF APPLIANCE" style=background-color:#99cc00; size= 100% >
</form>
</br>
<a href="/"><H3>HOME</H3></a>
<a href="/login?LOGOUT=YES"><H3>Log Out</H3></a>
</body>
</html
</html

)=====";
