#include <CSMS.h>
const int AirValue = 520;   
const int WaterValue = 260; 
int intervals = (AirValue - WaterValue)/3;
int MoistureValue = 0;

void Start(){
    Serial.begin(115200);
}
    
void Measurement(){
    MoistureValue = analogRead(Sensor_pin); 
    Serial.print(MoistureValue);
if (MoistureValue > WaterValue && MoistureValue < (WaterValue + intervals))
{
  Serial.println("-Very Wet");
}
else if (MoistureValue > (WaterValue + intervals) && MoistureValue < (AirValue - intervals))
{
  Serial.println("-Wet");
}
else if (MoistureValue < AirValue && MoistureValue > (AirValue - intervals))
{
  Serial.println("-Dry");
}
delay(100);
}
