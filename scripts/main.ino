/*
Intro:
基于arduino单片机驱动步进电机，步进电机驱动机械装置yoyo摇摆。步进电机型号28byj-48，5v版本，为5相四线电机，单片机不能直接驱动，电机功率较小，可以用uln2003驱动。
author:langsunny
date:Jan 18, 2018
version: 1.0.2

*/
#include<Stepper.h>

 
// 参考文件
/*
    28BYJ-48.pdf
 
    该参数根据电机每一转的步数来修改
*/
const int stepsPerRevolution = 200;
 
// 初始化步进电机要使用的Arduino的引脚编号
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
 
void setup()
{
    // 设置转速，单位r/min
    myStepper.setSpeed(180);//摇摆器默认转速150,Yoyo周期大约是1秒
 
    // 初始化串口
    Serial.begin(9600);
}
 
void loop()
{
    // 顺时针一次旋转
    Serial.println("clockwise");
    myStepper.step(stepsPerRevolution);
    delay(150);
 
    // 逆时针一次旋转
    Serial.println("counterclockwise");
    myStepper.step(-stepsPerRevolution);
    delay(150);
}
