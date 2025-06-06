#include <Adafruit_LSM6DSO32.h>

#define SDA 20
#define SCL 21
#define BTN1 8
#define LED1 7
#define LED2 6
#define LED3 5

Adafruit_LSM6DSO32 sensor;

int mode = 0;

sensors_vec_t gravity;
sensors_vec_t adjusted_accel;

sensors_vec_t prev_vel;
sensors_vec_t prev_ang_vel;
sensors_vec_t prev_pos;
sensors_vec_t prev_ori;

sensors_vec_t velocity;
sensors_vec_t angular_velocity;
sensors_vec_t position;
sensors_vec_t orientation;

long prev_time;
long delta_time;

int rounding = 10000;

void initialize() {
  prev_vel.x = 0;
  prev_vel.y = 0;
  prev_vel.z = 0;

  prev_ang_vel.x = 0;
  prev_ang_vel.y = 0;
  prev_ang_vel.z = 0;

  prev_pos.x = 0;
  prev_pos.y = 0;
  prev_pos.z = 0;

  prev_ori.x = 0;
  prev_ori.y = 0;
  prev_ori.z = 0;

  prev_time = 0;
  delta_time = 0;
}

void calibrate_gravity() {
  sensors_event_t accel;
  sensors_event_t gyro; //unsued, placeholder
  sensors_event_t temp; //unused, placeholder
  sensor.getEvent(&accel, &gyro, &temp);

  gravity.x = accel.acceleration.x;
  gravity.y = accel.acceleration.y;
  gravity.z = accel.acceleration.z;
}

bool trash = true;

void sensorLoop() {
  
  long time = micros();
  delta_time = time - prev_time;

  if (trash)
  {
    trash = false;
    delta_time = 0;
  }

  sensors_event_t accel;
  sensors_event_t gyro;
  sensors_event_t temp; //unused, placeholder
  sensor.getEvent(&accel, &gyro, &temp);

  adjusted_accel.x = accel.acceleration.x - gravity.x;
  adjusted_accel.y = accel.acceleration.y - gravity.y;
  adjusted_accel.z = accel.acceleration.z - gravity.z;

  velocity.x = prev_vel.x + trunc(adjusted_accel.x * rounding) / rounding * delta_time / 1000;
  velocity.y = prev_vel.y + trunc(adjusted_accel.y * rounding) / rounding * delta_time / 1000;
  velocity.z = prev_vel.z + trunc(adjusted_accel.z * rounding) / rounding * delta_time / 1000;

  position.x = prev_pos.x + velocity.x * delta_time / 1000;
  position.y = prev_pos.y + velocity.y * delta_time / 1000;
  position.z = prev_pos.z + velocity.z * delta_time / 1000;

  angular_velocity.x = prev_ang_vel.x + gyro.gyro.x * delta_time / 1000;
  angular_velocity.y = prev_ang_vel.y + gyro.gyro.y * delta_time / 1000;
  angular_velocity.z = prev_ang_vel.z + gyro.gyro.z * delta_time / 1000;

  orientation.x = prev_ori.x + angular_velocity.x * delta_time / 1000;
  orientation.x = prev_ori.y + angular_velocity.y * delta_time / 1000;
  orientation.x = prev_ori.z + angular_velocity.z * delta_time / 1000;

  Serial.print("Accel:   ");
  Serial.print("X: ");
  Serial.print(trunc(adjusted_accel.x * 10) / 10);
  Serial.print("    Y: ");
  Serial.print(trunc(adjusted_accel.y * 10) / 10);
  Serial.print("    Z: ");
  Serial.println(trunc(adjusted_accel.z * 10) / 10);
  

  Serial.print("IAc:   ");
  Serial.print("X: ");
  Serial.print(adjusted_accel.x * delta_time / 1000);
  Serial.print("    Y: ");
  Serial.print(adjusted_accel.y * delta_time / 1000);
  Serial.print("    Z: ");
  Serial.println(adjusted_accel.z * delta_time / 1000);

  

  
  Serial.print("Vel:   ");
  Serial.print("X: ");
  Serial.print(velocity.x);
  Serial.print("    Y: ");
  Serial.print(velocity.y);
  Serial.print("    Z: ");
  Serial.println(velocity.z);
  
  

  /*
  Serial.print("Pos:   ");
  Serial.print("X: ");
  Serial.print(position.x);
  Serial.print("    Y: ");
  Serial.print(position.y);
  Serial.print("    Z: ");
  Serial.println(position.z);
  */

  Serial.println("");

  /*Serial.print(",{");
  Serial.print(position.x);
  Serial.print(",");
  Serial.print(position.y);
  Serial.print("}");
  */

  prev_vel = velocity;
  prev_ang_vel = angular_velocity;
  prev_pos = position;
  prev_ori = orientation;
  prev_time = time;
  
  //delay(1);
}

void blink(uint8_t pin, int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(pin, HIGH);
    delay(50);
    digitalWrite(pin, LOW);
    delay(50);
  }
}

void printHeader() {
  Serial.print("ListPlot[{{0,0}");
}

void printFooter() {
  Serial.print("}]");
}

void setup() {
  pinMode(BTN1, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);


  initialize();

  Serial.begin(115200);
  while (!Serial){
    delay(10);
  }

  if (!sensor.begin_I2C()) {
    while (1) {
      delay(10);
    }
  }

  sensor.setAccelRange(LSM6DSO32_ACCEL_RANGE_8_G);
}

void loop() {
  
  if (mode == 0) {
    if (digitalRead(BTN1))
    {
      delay(1000);
      calibrate_gravity();
      digitalWrite(LED1, HIGH);
      mode = 1;
    }
    //delay(10);
  } else if (mode == 1) {
    if (digitalRead(BTN1)) {
      delay(1000);
      digitalWrite(LED2, HIGH);
      printHeader();
      mode = 2;
    }
  } else if (mode == 2) {
    sensorLoop();
    if (digitalRead(BTN1)) {
      digitalWrite(LED3, HIGH);
      printFooter();
      delay(100);
      mode = 3;
    }
  } else if (mode == 3) {
    if (digitalRead(BTN1)) {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      delay(100);
      mode = 0;
    }
    delay(10);
  }
  //Serial.println(digitalRead(BTN1));
}

