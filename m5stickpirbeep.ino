/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*  PIR example modified for M5StackC Plus 2
*   ---Dead Hiccups------                
* Visit for more information: https://docs.m5stack.com/en/unit/pir
* 获取更多资料请访问: https://docs.m5stack.com/zh_CN/unit/pir
*
* Product: PIR.  人体红外
* Date: 2021/8/11
*******************************************************************************
  Please connect to Port A,Human body detection using PIR Unit.
  请连接端口B,使用PIR Unit进行人体检测。
  Modified example code from M5 Stack PIR -
  Modified so you can use Port A - added Beep
  Modify Beep sound on line 30 M5.Speaker.setVolume
*/

#include "M5StickCPlus2.h"


void setup() {
    M5.begin();             // Init M5Core2.  初始化 M5Core2
    M5.Lcd.setTextSize(2);  // Set the text size to 2.  设置文字大小为2
    M5.Lcd.println("PIR Test");
    M5.Lcd.setCursor(0,
                     25);  // Position the cursor at (0,25).  将光标固定在(0,25)
    M5.Lcd.println("Status: \nValue: ");
    //For port A switching to pin 33 UART_RX_PIN = 33 - use 36 for port B
    pinMode(33, INPUT);  // Set pin 36 to input mode.  设置36号引脚为输入模式
    //max volume can go to 255
    M5.Speaker.setVolume(255);
 //   M5.Speaker.tone(4000, 200);
}

void loop() {
    M5.Lcd.fillRect(90, 25, 180, 50,
                    BLACK);  // Draw a black rectangle 180 by 50 at (90,25).
                             // 在(90,25)处画一个宽180高50的黑的矩形
    if (digitalRead(33) ==
        1) {  // If pin 36 reads a value of 1.  如果36号引脚的读取到的值为1
        M5.Lcd.setCursor(95, 25);
        M5.Lcd.print("Sensing");
        M5.Lcd.setCursor(95, 45);
        M5.Lcd.print("1");
        M5.Speaker.tone(2000, 300);
    } else {
        M5.Lcd.setCursor(95, 25);
        M5.Lcd.print("Not Sensed");
        M5.Lcd.setCursor(95, 45);
        M5.Lcd.print("0");
    }
    delay(500);
}
