// 引入 ESP8266 的库
#include <ESP8266WiFi.h>

// 设置串口监视器的波特率
#define BAUD_RATE 115200

// 设置 ESP8266 内置 LED 的引脚
#define LED_PIN 16

// 函数原型
void setup();
void loop();
void processSerialCommand();

void setup() {
  // 初始化串口监视器
  Serial.begin(BAUD_RATE);

  // 设置 LED 引脚为输出模式
  pinMode(LED_PIN, OUTPUT);

  // 初始状态关闭 LED
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  // 检查是否有可用的串口数据
  if (Serial.available() > 0) {
    // 处理串口命令
    processSerialCommand();
  }
}

void processSerialCommand() {
  // 读取串口输入的数据
  char receivedChar = Serial.read();

  // 检查收到的字符并执行相应操作
  if (receivedChar == '1') {
    // 点亮 LED
    digitalWrite(LED_PIN, HIGH);
    Serial.println("LED turned on");
  } else if (receivedChar == '0') {
    // 关闭 LED
    digitalWrite(LED_PIN, LOW);
    Serial.println("LED turned off");
  } else {
    // 未知命令
    Serial.println("Unknown command");
  }
}
