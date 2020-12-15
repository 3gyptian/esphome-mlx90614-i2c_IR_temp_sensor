# esphome MLX90614 I2C IR Temperature Custom Sensor 

These sensors are what's in an ear thermometer and provide quite quick reading of an object's temperature from many centimetres away. They also include an ambient sensor which is providing the temperature reading of the sensor's case.  

These aren't the cheapest sensors but they are quite fast and accurate and can be used in all sorts of situations where attaching a probe isn't practical.  In my case I have successfully used these sensors to monitor and control a water boiler and a pressure cooker. 

![Image 1](https://github.com/3gyptian/esphome-mlx90614-i2c_IR_temp_sensor/blob/master/images/Pot_Temp_Distance_Sensor.png)

![Image 2](https://github.com/3gyptian/esphome-mlx90614-i2c_IR_temp_sensor/blob/master/images/Pot_Temp_Sensor_Install.png)


IMPORTANT:  To get reliable IR readings I found I needed to paint the the pot black on the side that was facing the sensor.  My aluminum and stainless steel pots painted up quite well with hardware store matte black spray paint after a slight sand and a clean.  

## How to create this custom sensor in esphome

1) Copy example yaml files into your esphome main folder
2) Create 'custom' folder and copy in mlx90614.h
3) Build away


## Notes

- this sensor uses 'sort of' i2c and it's important to lower clock rate to 50 khz (as seen in the yaml)
- on three different sensors (different vendors) and ESP8266 and ESP32 I kept encountering intermittent 1037.5 C ambient sensor readings..which is what the routine returns if the sensor isn't even connected.   I noticed the ambient sensor was being read first by the routine so figured maybe some sort of timeout. I modified the source code (mlx90614.h) to take two readings of the ambient sensor (returns the second reading) and have encountered no more bogus 1037.5C readings.  For the hek of it I also take double reading of the object sensor and returning the second reading.  

These two posts were most helpful in figuring out how to build this:
https://www.reddit.com/r/Esphome/comments/h0d8ly/custom_i2c_sensor_example/
https://github.com/esphome/feature-requests/issues/476#issuecomment-555215130



