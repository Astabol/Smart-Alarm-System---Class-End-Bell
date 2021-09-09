#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include"index.h"
#include <RTClib.h>
#include <Wire.h>
#include <LiquidCrystal595.h>    // include the library
LiquidCrystal595 lcd(D6,D7,D8);// data_pin, latch_pin, clock_pin
int Contrast=45;
 
RTC_DS3231 rtc;

const char* ssid = "smart_alarm_clock";
const char* password = "1234";

int setCounter1=0;
int setCounter2=0;
int setCounter3=0;
int setCounter4=0;
int setCounter5=0;


String set1;
String set2;
String set3;
String set4;
String set5;

int Hor;
int Min;
int Sec;

int p_day;
int p_month;
int p_year;

int alarm_hour1;
int alarm_min1;
int alarm_sec1;

int alarm_hour2;
int alarm_min2;
int alarm_sec2;


int alarm_hour3;
int alarm_min3;
int alarm_sec3;

int alarm_hour4;
int alarm_min4;
int alarm_sec4;

int alarm_hour5;
int alarm_min5;
int alarm_sec5;

ESP8266WebServer server(80);

//Check if header is present and correct
bool is_authentified() {
  Serial.println("Enter is_authentified");
  if (server.hasHeader("Cookie")) {
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
    if (cookie.indexOf("ESPSESSIONID=1") != -1) {
      Serial.println("Authentification Successful");
      return true;
    }
  }
  Serial.println("Authentification Failed");
  return false;
}

//login page, also called for disconnect
void handleLogin() {
  String msg;
  if (server.hasHeader("Cookie")) {
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
  }
  if (server.hasArg("DISCONNECT")) {
    Serial.println("Disconnection");
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.sendHeader("Set-Cookie", "ESPSESSIONID=0");
    server.send(301);
    return;
  }
  if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")) {
    if (server.arg("USERNAME") == "admin" &&  server.arg("PASSWORD") == "admin") {
      server.sendHeader("Location", "/");
      server.sendHeader("Cache-Control", "no-cache");
      server.sendHeader("Set-Cookie", "ESPSESSIONID=1");
      server.send(301);
      Serial.println("Log in Successful");
      return;
    }
    msg = "Wrong username/password! try again.";
    Serial.println("Log in Failed");
  }
  server.send(200, "text/html", LOGIN_PAGE);
}

//root page can be accessed only if authentification is ok
void handleRoot() {
  Serial.println("Enter handleRoot");
  String header;
  if (!is_authentified()) {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }

  if (server.hasArg("HH_PRE") && server.hasArg("MM_PRE") && server.hasArg("SS_PRE") && server.hasArg("DD_PRE") && server.arg("MO_PRE") &&  server.arg("YYYY_PRE")  ) {
    String pre_h1 = server.arg("HH_PRE");
    String pre_m1 = server.arg("MM_PRE");
    String pre_s1 = server.arg("SS_PRE");
    int pre_hour1 = atoi(pre_h1.c_str());
    int pre_min1 = atoi(pre_m1.c_str());
    int pre_sec1 = atoi(pre_s1.c_str());


    String pre_d1 = server.arg("DD_PRE");
    String pre_mo1 = server.arg("MO_PRE");
    String pre_y1 = server.arg("YYYY_PRE");
    int pre_day1 = atoi(pre_d1.c_str());
    int pre_month1 = atoi(pre_mo1.c_str());
    int pre_year1 = atoi(pre_y1.c_str());

    
    rtc.adjust(DateTime(pre_year1, pre_month1, pre_day1, pre_hour1, pre_min1, pre_sec1));
    
    Serial.println(pre_hour1);
    Serial.print(":");
    Serial.print(pre_min1);
    Serial.print(":");
    Serial.print(pre_sec1);


    Serial.println(pre_day1);
    Serial.print(":");
    Serial.print(pre_month1);
    Serial.print(":");
    Serial.print(pre_year1);


    server.send(200, "text/html", PRETIME_SET);

  }

/*  if (server.hasArg("DD_PRE") && server.hasArg("MO_PRE") && server.hasArg("YYYY_PRE") ) {
    String pre_h1 = server.arg("DD_PRE");
    String pre_m1 = server.arg("MO_PRE");
    String pre_s1 = server.arg("YYYY_PRE");
    int pre_day1 = atoi(pre_h1.c_str());
    int pre_month1 = atoi(pre_m1.c_str());
    int pre_year1 = atoi(pre_s1.c_str());

    Serial.println(pre_day1);
    Serial.print(":");
    Serial.print(pre_month1);
    Serial.print(":");
    Serial.print(pre_year1);

    server.send(200, "text/html", PRETIME_SET);

  }  */
  
  if (server.hasArg("HH_ALARM1") && server.hasArg("MM_ALARM1") && server.hasArg("SS_ALARM1") ) {
    String alarm_h1 = server.arg("HH_ALARM1");
    String alarm_m1 = server.arg("MM_ALARM1");
    String alarm_s1 = server.arg("SS_ALARM1");
    alarm_hour1 = atoi(alarm_h1.c_str());
    alarm_min1 = atoi(alarm_m1.c_str());
    alarm_sec1 = atoi(alarm_s1.c_str());
    setCounter1=1;
    Serial.println(alarm_hour1);
    Serial.print(":");
    Serial.print(alarm_min1);
    Serial.print(":");
    Serial.print(alarm_sec1);

    server.send(200, "text/html", ALARM_SET);

  }

    if (server.hasArg("HH_ALARM2") && server.hasArg("MM_ALARM2") && server.hasArg("SS_ALARM2") ) {
    String alarm_h2 = server.arg("HH_ALARM2");
    String alarm_m2 = server.arg("MM_ALARM2");
    String alarm_s2 = server.arg("SS_ALARM2");
    alarm_hour2 = atoi(alarm_h2.c_str());
    alarm_min2 = atoi(alarm_m2.c_str());
    alarm_sec2 = atoi(alarm_s2.c_str());

    setCounter2=1;
    
    Serial.println(alarm_hour2);
    Serial.print(":");
    Serial.print(alarm_min2);
    Serial.print(":");
    Serial.print(alarm_sec2);

    server.send(200, "text/html", ALARM_SET);

  }

    if (server.hasArg("HH_ALARM3") && server.hasArg("MM_ALARM3") && server.hasArg("SS_ALARM3") ) {
    String alarm_h3 = server.arg("HH_ALARM3");
    String alarm_m3 = server.arg("MM_ALARM3");
    String alarm_s3 = server.arg("SS_ALARM3");
    alarm_hour3 = atoi(alarm_h3.c_str());
    alarm_min3 = atoi(alarm_m3.c_str());
    alarm_sec3 = atoi(alarm_s3.c_str());

    setCounter3=1;
    Serial.println(alarm_hour3);
    Serial.print(":");
    Serial.print(alarm_min3);
    Serial.print(":");
    Serial.print(alarm_sec3);

    server.send(200, "text/html", ALARM_SET);

  }
    if (server.hasArg("HH_ALARM4") && server.hasArg("MM_ALARM4") && server.hasArg("SS_ALARM4") ) {
    String alarm_h4 = server.arg("HH_ALARM4");
    String alarm_m4 = server.arg("MM_ALARM4");
    String alarm_s4 = server.arg("SS_ALARM4");
    alarm_hour4 = atoi(alarm_h4.c_str());
    alarm_min4 = atoi(alarm_m4.c_str());
    alarm_sec4 = atoi(alarm_s4.c_str());


    setCounter4=1;
    Serial.println(alarm_hour4);
    Serial.print(":");
    Serial.print(alarm_min4);
    Serial.print(":");
    Serial.print(alarm_sec4);

    server.send(200, "text/html", ALARM_SET);

  }

    if (server.hasArg("HH_ALARM5") && server.hasArg("MM_ALARM5") && server.hasArg("SS_ALARM5") ) {
    String alarm_h5 = server.arg("HH_ALARM5");
    String alarm_m5 = server.arg("MM_ALARM5");
    String alarm_s5 = server.arg("SS_ALARM5");
    alarm_hour5 = atoi(alarm_h5.c_str());
    alarm_min5 = atoi(alarm_m5.c_str());
    alarm_sec5 = atoi(alarm_s5.c_str());
    setCounter5=1;
    Serial.println(alarm_hour5);
    Serial.print(":");
    Serial.print(alarm_min5);
    Serial.print(":");
    Serial.print(alarm_sec5);

    server.send(200, "text/html", ALARM_SET);

  }

    if (server.hasArg("ALARM")){


    server.send(200, "text/html", ALARM_FORM);

  }
  
if (server.hasArg("RESET_DATE")){
    String statusPage=SHOW_DATE;
    statusPage.replace("@@H@@",String(Hor));
    String s=statusPage;
    s.replace("@@M@@",String(Min));
    String f=s;
    f.replace("@@S@@",String(Sec));
    s=f;
    s.replace("@@D@@", String(p_day));
    f=s;
    f.replace("@@MO@@", String(p_month));
    s=f;
    s.replace("@@Y@@", String(p_year));
    f=s;
    //String statusPage2=statusPage1.replace("@@M@@", String(Min));
    //String statusPage3=statusPage2.replace("@@S@@", String(Sec));
    server.send(200, "text/html", f);

  }
  if (server.hasArg("HOME_AUTOMATION")){
    server.send(200, "text/html", APPLIANCES);

  }
    if (server.hasArg("LED_ON")){
      digitalWrite(D0,LOW);
    server.send(200, "text/html", APPLIANCES_ON);

  }

    if (server.hasArg("LED_OFF")){
      digitalWrite(D0,HIGH);
    server.send(200, "text/html", APPLIANCES_OFF);

  }
  
  
  if (server.hasArg("ALARM_STATUS")){
    String alarmStatus=STATUS_PAGE;
    if(setCounter1==1)
    {
      set1="SET";
      
    }
    else{
      set1="NOT SET";
    }
    if(setCounter2==1)
    {
      set2="SET";
      
    }
    else{
      set2="NOT SET";
    }
    if(setCounter3==1)
    {
      set3="SET";
      
    }
    else{
      set3="NOT SET";
    }
    if(setCounter4==1)
    {
      set4="SET";
      
    }
    else{
      set4="NOT SET";
    }
    if(setCounter5==1)
    {
      set5="SET";
      
    }
    else{
      set5="NOT SET";
    }

    
    alarmStatus.replace("@@SET1@@",set1);
    String s=alarmStatus;
    s.replace("@@SET2@@",set2);
    String f=s;
    f.replace("@@SET3@@",set3);
    s=f;
    s.replace("@@SET4@@",set4);
    f=s;
    f.replace("@@SET5@@", set5);
    s=f;
    //String statusPage2=statusPage1.replace("@@M@@", String(Min));
    //String statusPage3=statusPage2.replace("@@S@@", String(Sec));
    server.send(200, "text/html", s);

  }
  server.send(200, "text/html", HOME_PAGE);
}

//no need authentification
void handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void) {
  pinMode(D0,OUTPUT);
  pinMode(D3,OUTPUT);
  pinMode(D4,OUTPUT); 
  digitalWrite(D3,HIGH); 
  digitalWrite(D0,HIGH);
  Serial.begin(9600);
  
  
  WiFi.mode(WIFI_AP); // For wifi accesspoint you can select Wifi station :   WiFi.mode(STA);
  WiFi.softAP(ssid); // For wifi sation you can replace the line by :     Wifi.begin(ssid);
  Serial.println("");
  rtc.begin();
  Serial.println("IP address: ");
  Serial.println(WiFi.softAPIP());
  pinMode(D2, OUTPUT);
  lcd.begin(16,2); // 16 characters, 2 rows
 
   lcd.setCursor(0, 0);
   lcd.print("SMART ALARM ");
   delay(2000);
   
  
  lcd.clear();
  pinMode(D5,OUTPUT);
  analogWrite(D5,Contrast);
  
  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.on("/inline", []() {
    server.send(200, "text/plain", "this works without need of authentification");
  });

  server.onNotFound(handleNotFound);
  //here the list of headers to be recorded
  const char * headerkeys[] = {"User-Agent", "Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys) / sizeof(char*);
  //ask server to track these headers
  server.collectHeaders(headerkeys, headerkeyssize);
  server.begin();
  Serial.println("HTTP server started");
}

void alarm_on(void){
  digitalWrite(D3, LOW);
  delay(5000);
  digitalWrite(D3, HIGH);
}

void loop(void) {
  DateTime now = rtc.now();
  Hor = now.hour();

  Min = now.minute();
   lcd.clear();
  Sec = now.second();
  Serial.println("Time:");
  Serial.print(Hor);
  Serial.print(":");
  Serial.print(Min);
  Serial.print(":");
  Serial.print(Sec);
  Serial.print("");
  
 lcd.setCursor(0,0);
 lcd.print("Time:");
 lcd.print(Hor);
 lcd.print(":");
 lcd.print(Min);
 lcd.print(":");
 lcd.print(Sec);
 lcd.print("");

 lcd.setCursor(0,1);
 lcd.print("Date:");
 lcd.print(p_day);
 lcd.print(":");
 lcd.print(p_month);
 lcd.print(":");
 lcd.print(p_year);
 lcd.print("");


  p_day=now.day();
  p_month=now.month();
  p_year=now.year();  

  Serial.println(p_day);
  Serial.print(":");
  Serial.print(p_month);
  Serial.print(":");
  Serial.print(p_year);

  Serial.print("");
  
  if( Hor == alarm_hour1 &&  Min == alarm_min1) //|| Sec == alarm_sec)//Comparing the current time with the Alarm time

{

Serial.println("1st Alarm");
while(setCounter1==1){
set1="NOT SET";
alarm_on();
setCounter1=0;

}

}


  if( Hor == alarm_hour2 &&  Min == alarm_min2) //|| Sec == alarm_sec)//Comparing the current time with the Alarm time

{

Serial.println("2st Alarm");


Serial.println("Alarming");
while(setCounter2==1){
set2="NOT SET";
alarm_on();
setCounter2=0;

}

}

  if( Hor == alarm_hour3 &&  Min == alarm_min3) //|| Sec == alarm_sec)//Comparing the current time with the Alarm time

{

Serial.println("3st Alarm");
Serial.println("Alarming");
while(setCounter3==1){
set3="NOT SET";
alarm_on();
setCounter3=0;

}
}


  if( Hor == alarm_hour4 &&  Min == alarm_min4) //|| Sec == alarm_sec)//Comparing the current time with the Alarm time

{

Serial.println("4st Alarm");
Serial.println("Alarming");
while(setCounter4==1){
set4="NOT SET";
alarm_on();
setCounter4=0;

}
}


  if( Hor == alarm_hour5 &&  Min == alarm_min5) //|| Sec == alarm_sec)//Comparing the current time with the Alarm time

{

Serial.println("5st Alarm");
Serial.println("Alarming");
while(setCounter5==1){
set5="NOT SET";
alarm_on();
setCounter5=0;

}
}


  
  server.handleClient();
  delay(1000);
}


