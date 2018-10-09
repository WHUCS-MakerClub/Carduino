char serial_data;

int wheel_L[2] = { 5, 6 };
int wheel_R[2] = { 9, 10 };

void setup(){
    // 设置控制轮的引脚为输出
    pinMode(wheel_L[0], OUTPUT);
    pinMode(wheel_L[1], OUTPUT);
    pinMode(wheel_R[0], OUTPUT);
    pinMode(wheel_R[1], OUTPUT);

    Serial.begin(9600);
}

void loop(){
    if(Serial.available()){
        serial_data = Serial.read();

        if( serial_data == 'w' ){
            go_ahead( 200 );
        }
        else if( serial_data == 'x'){
            go_back( 200 );
        }
        else if( serial_data == 'a'){
            turn_left( 200 );
        }
        else if( serial_data == 'd'){
            turn_right( 200 );
        }
        else if( serial_data == 's'){
            wheel_stop( wheel_L );
            wheel_stop( wheel_R );
        }
    }
}

void wheel_run( int *wheel, int spd){
    if( spd >= 0 && spd <=255){  // 如果传入速度值大于0，轮正转
        analogWrite( wheel[0], spd);
        analogWrite( wheel[1], 0);
    }
    else if( spd <= 0 && spd >= -255){  // 如果传入速度值小于0，轮反转
        analogWrite( wheel[0], 0);
        analogWrite( wheel[1], spd);
    }
    // 处理大于255的输入值？    
}

void wheel_stop( int *wheel ){
    analogWrite( wheel[0], 0 );
    analogWrite( wheel[1], 0 );
}

void go_ahead( int spd ){ //？
    wheel_run( wheel_L, spd );
    wheel_run( wheel_R, spd );
}

void go_back( int spd ){ //？
    wheel_run( wheel_L, spd );
    wheel_run( wheel_R, spd );
}

void turn_left( int spd ){ //
    wheel_run( wheel_L, spd/2 );
    wheel_run( wheel_R, spd );
}

void turn_right( int spd ){ //
    wheel_run( wheel_L, spd );
    wheel_run( wheel_R, spd/2 );
}
