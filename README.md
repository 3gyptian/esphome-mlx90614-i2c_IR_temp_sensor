# esphome MLX90614 I2C IR Temperature Custom Sensor (GY-906)

These sensors are what's in an ear thermometer and provide quite quick reading of an object's temperature from many centimetres away. They also include an ambient sensor which is providing the temperature reading of the sensor's case.  

These aren't the cheapest sensors but they are quite fast and accurate and can be used in all sorts of situations where attaching a probe isn't practical.  In my case I have successfully used these sensors to monitor and control a water boiler and a pressure cooker. 

Here is the mlx sensor in the middle of the HC-SR04 distance sensor used to detect if the pot is on the element or not before beginning .. turning things off if it's removed:

![](https://github.com/3gyptian/esphome-mlx90614-i2c_IR_temp_sensor/blob/master/images/Pot_Temp_Distance_Sensor.png)


IMPORTANT:  To get reliable IR readings from a pot of water I needed to paint the the pot black in front of the sensor.  My aluminum and stainless steel pots painted up quite well with hardware store matte black spray paint after a slight sand and a clean.  

## How to create this custom sensor in esphome

1) Copy example yaml files into your esphome main folder
2) Create 'custom' folder and copy in mlx90614.h
3) Build away


## Resoloving missing Adafruit_MLX90614.h

Received this error after recompiling some time after upgrading esphome:

```
In file included from src/main.cpp:19:0:
src/mlx90614.h:2:31: fatal error: Adafruit_MLX90614.h: No such file or directory
```

Above this error it shows unable to find the adafruit library:

```HARDWARE: ESP8266 80MHz, 80KB RAM, 4MB Flash
PACKAGES: 
 - framework-arduinoespressif8266 3.20704.0 (2.7.4) 
 - tool-esptool 1.413.0 (4.13) 
 - tool-esptoolpy 1.20800.0 (2.8.0) 
 - toolchain-xtensa 2.40802.200502 (4.8.2)
Library Manager: Installing adafruit/Adafruit-MLX90614-Library
Warning! Could not find the package with 'adafruit/Adafruit-MLX90614-Library' requirements for your system 'darwin_x86_64'
Library Manager: Installing Update
Library Manager: Already installed, built-in library
```

Even though I included:
```
 libraries:
  - adafruit/Adafruit-MLX90614-Library
```

Worked around via:

```
# cd boiler_temp_distance/.piolibdeps/boiler_temp_distance
# git clone https://github.com/adafruit/Adafruit-MLX90614-Library
```

voila


## Notes

- this sensor uses 'sort of' i2c and it's important to lower clock rate to 50 khz (as seen in the yaml)
- on three different sensors (different vendors) and ESP8266 and ESP32 I kept encountering intermittent 1037.5 C ambient sensor readings..which is what the routine returns if the sensor isn't even connected.   I noticed the ambient sensor was being read first by the routine so figured maybe some sort of timeout. I modified the source code (mlx90614.h) to take two readings of the ambient sensor (returns the second reading) and have encountered no more bogus 1037.5C readings.  For the hek of it I also take double reading of the object sensor and returning the second reading.  

These two posts were most helpful in figuring out how to build this:
https://www.reddit.com/r/Esphome/comments/h0d8ly/custom_i2c_sensor_example/
https://github.com/esphome/feature-requests/issues/476#issuecomment-555215130



