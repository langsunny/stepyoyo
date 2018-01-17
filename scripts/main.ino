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
    myStepper.setSpeed(180);//摇摆器默认转速150
 
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
