/*
Intro:
基于arduino单片机驱动步进电机，步进电机驱动机械装置yoyo摇摆。步进电机型号28byj-48，5v版本，为5相四线电机，单片机不能直接驱动，电机功率较小，可以用uln2003驱动。
author:langsunny
date:Jan 18, 2018
history:
version: 1.0.5 增加了按键调速功能，重复按键会循环增加速度（0,5...45）,按键每按一次led神灯状态会改变一次。
version: 1.0.1

*/
#include<Stepper.h>
 
// 参考文件
/*
    28BYJ-48.pdf
 
    该参数根据电机每一转的步数来修改
*/
const int stepsPerRevolution = 200;
// 定义按键输入针脚号常量，
// 并初始化为2号针脚。
int speed = 150; //摇摆器默认转速150

const int buttonPin = 12;

// 定义LED输入针脚号常量，
// 并初始化为13号针脚。
// 注：此处我们使用的LED神灯是Arduino UNO电路板自带，
// 此神灯对应的针脚号默认为13，此数值不得随意更改，
// 所以这里定义的数值13是为了和默认值相对应。
const int ledPin = 13;
// 定义记录LED神灯当前状态的变量，
// 并初始化状态为HIGH。
int ledState = HIGH;
// 定义记录按键当前状态的变量
int buttonState=0;
// 定义记录按键最近一次状态变化的变量，
// 并初始化状态为LOW。
int lastButtonState = LOW;
// 定义记录最近一次抖动的时间变量，
// 并初始化时间为0毫秒。
long lastDebounceTime = 0;
// 定义延迟抖动的时间变量，
// 并初始化为50毫秒。
long debounceDelay = 50;
 
// 初始化步进电机要使用的Arduino的引脚编号
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
 
void setup()
{
   
 
    // 初始化串口
    Serial.begin(9600);
    // 设置按键的针脚为输入状态
    pinMode(buttonPin, INPUT);
  // 设置电路板上LED神灯的针脚状态为输出状态
    pinMode(ledPin, OUTPUT);
  // 设置电路板上LED神灯的初始状态，
  // 此处因为变量ledState的初始状态为HIGH，
  // 所以LED神灯的初始状态为亮。
    digitalWrite(ledPin, ledState);
}
 
void loop()
{
    // 顺时针一次旋转
      // 读取按键的状态
  int reading = digitalRead(buttonPin);
  // 判断当前的按键状态是否和之前有所变化
  if (reading != lastButtonState) {
    // 如果按键发生了变化，
    // 则重新设置最近一次抖动的时间。
    lastDebounceTime = millis();
  }
  // 判断按键按下或抬起的状态时间间隔是否大于延迟抖动的时间长度。
  // 方法millis()可以获取当前时间，单位统一为毫秒。
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // 判断当前的按键状态是否和之前有所变化
    if (reading != buttonState) {
      // 如果发生了变化，
      // 则更新按键状态变量。
      buttonState = reading;
      // 判断按键的状态是否为按下，
      // 只有在按键按下的时候，
      // 才改变LED神灯的状态。
      if (buttonState == HIGH) {
        // 如果LED神灯当前为亮度，
        // 则变为灭。如果为灭，
        // 则变为亮。
        ledState = !ledState;
        num = num+5;
        if (num == 200) {  
         num = 150; //速度置位默认速度１５０  
    } 
      }
    }
  }
  // 最终改变电路板上LED神灯的状态
  digitalWrite(ledPin, ledState);
  // 更新按键最近一次状态变化的变量
   lastButtonState = reading;
   // 设置转速，单位r/min
   myStepper.setSpeed(speed);//摇摆器默认转速150
   
    Serial.println(speed);
    myStepper.step(stepsPerRevolution);
    delay(150);
 
    // 逆时针一次旋转
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(150);
}
