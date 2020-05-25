#include<Arduino.h>
#include<WMBoard.h>
#include<WMHead.h>
/// Sensor1 Cam bien hong ngoai do line (11)
/// Sensor1 Cam bien hong ngoai do line (12)
WMLineFollower lineFollower1(11,12);  
   
/// Tạo hanlder điều khiển động cơ trái với 2 pin 8(hướng quay), và 6(công suất PWM)
WMDCMotor motor1(8);
/// Tạo hanlder điều khiển động cơ phải với 2 pin 7(hướng quay), và 5(công suất PWM)
WMDCMotor motor2(7); 
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  ///Nếu như đường line lệch về phía bên trái thì cho xe rẽ sang hướng bên trái 
    if(lineFollower1.readEdgeSensor1Status()){
      /// Tùy vào góc rẽ theo ý muốn, lập trình viên thiết lập tốc độ ở hai motor cho hợp lý
      motor1.reverseRun(20);
      motor2.reverseRun(50);
    }
   ///Nếu như đường line lệch về phía bên phải thì cho xe rẽ sang hướng bên phải 
    else if(lineFollower1.readEdgeSensor2Status()){
      /// Tùy vào góc rẽ theo ý muốn, lập trình viên thiết lập tốc độ ở hai motor cho hợp lý
      motor1.reverseRun(50);
      motor2.reverseRun(20);
    }  
   ///Nếu không lệch thì đi thẳng 
    else if(lineFollower1.readEdgeSensor1Status()==0 && lineFollower1.readEdgeSensor2Status()==0){
       motor1.reverseRun(20);
       motor2.reverseRun(20);
    }
   ///Nếu không tìm được đường thì đi lùi lại 
    else if(lineFollower1.readEdgeSensor1Status() == 1 && lineFollower1.readEdgeSensor2Status()==1){
      motor1.reverseRun(20);
      motor2.reverseRun(20);
    }
}
