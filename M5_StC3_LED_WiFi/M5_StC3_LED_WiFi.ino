// ############################################
// Program:  M5_StC3_LED_WiFi.ino
// Task:     Colorfull LED
// Autor:    R. Hoermann
// Version:  2022-01-26
// AddBoard: https://m5stack.oss-cn-shenzhen.aliyuncs.com/resource/arduino/package_m5stack_index.json
// Hardware: M5 Stamp C3
// IDEBoard: STAMP-C3
// ExtraLib: FreeNove_WS2823_Lib_for_ESP32.h via LibManager
//           !! FastLED Lib doesnt work stable with active WiFI !!
//
//      G0 G1 5V GND 5V 10 8  7  6  5  4 GND
//     +-o--o--o--o--o--o--o--o--o--o--o--o-+
//     |           M5 STAMP C3              |
//     |USBC                              Y |
//     |Power P2:SK6812 P3:Btn  WiFi2.4GHz+ |
//     |Serial/Upload                       |
//     |                                    |
//     +-o--o--o--o--o--o--o--o--o--o-------+
//     GND 5V 19 18 GND 9  EN 20 21 3V3
//            D+  D-         ^Rx Txv
// ############################################

#include "Freenove_WS2812_Lib_for_ESP32.h"
#include <WiFi.h>
#include <WebServer.h>
#include "html.h"

#define WiFi_SSID  "SoHoWiFi"       // <==Change this to your SOHO-SSID
#define WiFi_PASS  "TopSecret"      // <==Change this to your SOHO-PASS
#define PORT_HTTP  80

WebServer serv_HTTP(PORT_HTTP);

#define LEDS_COUNT    1
#define pin_LEDRGB    2
#define CHANNEL       0
#define INTERVAL   1000

Freenove_ESP32_WS2812 ledc3 = Freenove_ESP32_WS2812(LEDS_COUNT, pin_LEDRGB, CHANNEL, TYPE_GRB);

int  i_cnt=1;
int  i_brightness=10;
int  i_red,i_gre,i_blu;
long l_mslast=0;
char ac_ledcol[8]="#RRGGBB";

void setup_WiFi()
{
	Serial.print("Attempting to connect to WiFi: ");  Serial.print(WiFi_SSID);
	WiFi.begin(WiFi_SSID, WiFi_PASS); int i_timeout=12;
	while(WiFi.status() != WL_CONNECTED & i_timeout>0)
	{ Serial.write('.'); delay(1000); i_timeout--; }
	if(i_timeout==0){ Serial.println("Timeout"); delay(20000); ESP.restart();}
	Serial.print("IP(by DHCP)="); Serial.println(WiFi.localIP());
}

void serv_HTML()
{
	String s_html=s_html_template;
	s_html.replace("%ledcol%",String(ac_ledcol));
	serv_HTTP.send(200,"text/html",s_html);
}

void serv_FAVICON()
{
	serv_HTTP.send(200,"image/svg+xml",s_favicon); 
}

void update_LED()
{
	if(i_cnt & 4){ i_red=255;} else{i_red=0;}
	if(i_cnt & 2){ i_gre=255;} else{i_gre=0;}
	if(i_cnt & 1){ i_blu=255;} else{i_blu=0;}
	sprintf(ac_ledcol,"#%02X%02X%02X",i_red,i_gre,i_blu);
	Serial.printf("%d: %s\r\n",i_cnt,ac_ledcol);
	ledc3.setLedColorData(0,i_red,i_gre,i_blu);
	ledc3.show();
	i_cnt++; i_cnt%=8;
}

void setup() 
{
	Serial.begin(115200); Serial.println();
	Serial.println("M5 Stamp C3 RGB-Demo mit WiFi");
	ledc3.begin();
	ledc3.setBrightness(i_brightness);  
	setup_WiFi();
	serv_HTTP.on("/"           ,serv_HTML);
	serv_HTTP.on("/favicon.ico",serv_FAVICON);
	serv_HTTP.begin();
}

void loop() 
{
	if((millis()-l_mslast)>INTERVAL){ l_mslast=millis(); update_LED();}
	serv_HTTP.handleClient();
}
