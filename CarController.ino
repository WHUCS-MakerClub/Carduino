char serial_data;   // 将从串口读入的消息存储在该变量中

int wheel_L_1 = 5;  // 左轮in1对应Arduino 5号引脚
int wheel_L_2 = 6;  // 左轮in2对应Arduino 6号引脚
int wheel_R_1 = 9;  // 右轮in1对应Arduino 9号引脚
int wheel_R_2 = 10; // 右轮in2对应Arduino 10号引脚

void setup(){
    // 配置所有控制轮的引脚为输出
    pinMode(wheel_L_1, OUTPUT);
    pinMode(wheel_L_2, OUTPUT);
    pinMode(wheel_R_1, OUTPUT);
    pinMode(wheel_R_2, OUTPUT);
    // 配置串口波特率
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        // 将从串口读入的消息存储在该变量中
        serial_data = Serial.read();
        // 按照 w a s d x 在键盘上的布局来控制车
        // 如果接收到 w ，直行
        if( serial_data == 'w' ){
            go_ahead( );
        }
        // 如果接收到 x ，后退
        else if( serial_data == 'x'){
            go_back( );
        }
        // 如果接收到 a ，左转
        else if( serial_data == 'a'){
            turn_left( );
        }
        // 如果接收到 d ，右转
        else if( serial_data == 'd'){
            turn_right( );
        }
        // 如果接收到 s ，停止
        else if( serial_data == 's'){
            stop();
        }
    }
}


// 定义直行函数
void go_ahead(){
    digitalWrite( wheel_L_1, HIGH);
    digitalWrite( wheel_L_2, LOW;
    digitalWrite( wheel_R_1, HIGH);
    digitalWrite( wheel_R_2, LOW);
}

// 定义后退函数
void go_back(){
    digitalWrite( wheel_L_1, LOW);
    digitalWrite( wheel_L_2, HIGH;
    digitalWrite( wheel_R_1, LOW);
    digitalWrite( wheel_R_2, HIGH);
}

// 定义左转函数
void turn_left(){
    digitalWrite( wheel_L_1, LOW);
    digitalWrite( wheel_L_2, LOW;
    digitalWrite( wheel_R_1, HIGH);
    digitalWrite( wheel_R_2, LOW);
}

// 定义右转函数
void turn_right(){
    digitalWrite( wheel_L_1, HIGH);
    digitalWrite( wheel_L_2, LOW;
    digitalWrite( wheel_R_1, LOW);
    digitalWrite( wheel_R_2, LOW);
}

void stop(){
    digitalWrite( wheel_L_1, LOW);
    digitalWrite( wheel_L_2, LOW;
    digitalWrite( wheel_R_1, LOW);
    digitalWrite( wheel_R_2, LOW);
}