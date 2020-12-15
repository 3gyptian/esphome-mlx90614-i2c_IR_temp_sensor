#include "esphome.h"
#include "Adafruit_MLX90614.h"

class MLX90614 : public PollingComponent {
  public:
    // Adafruit_BMP085 bmp;
    Adafruit_MLX90614 mlx = Adafruit_MLX90614();
    Sensor *ambient_temperature_sensor = new Sensor();
    Sensor *object_temperature_sensor = new Sensor();

    // MLX90614() : PollingComponent(15000) { }
    MLX90614( uint32_t update_interval ) : PollingComponent(update_interval) { }  // https://github.com/esphome/feature-requests/issues/782

    void setup() override {
      mlx.begin();
    }

    void update() override {
      // This is the actual sensor reading logic.
      float amb_temperature = 0.0;
      amb_temperature = mlx.readAmbientTempC(); // reading twice seemed to eliminate intermittent invalid data reads (shows as 1037.5 C)
      amb_temperature = mlx.readAmbientTempC(); 
      ambient_temperature_sensor->publish_state(amb_temperature);
      float obj_temperature = 0.0;
      obj_temperature = mlx.readObjectTempC(); // only had invalid reads for ambient teperature but taking two readings of object temperature as well fwiw
      obj_temperature = mlx.readObjectTempC();
      object_temperature_sensor->publish_state(obj_temperature);
    }
};
