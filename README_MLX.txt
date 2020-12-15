https://www.reddit.com/r/Esphome/comments/h0d8ly/custom_i2c_sensor_example/
https://github.com/esphome/feature-requests/issues/476#issuecomment-555215130

mkdir custom
cd custom
copy in custom/mlx90614.h

create yaml


modifid mlx.h to allow for 'update_interval' equivalent
https://github.com/esphome/feature-requests/issues/782

class MyCustomSensor : public PollingComponent, public Sensor {
 public:
  // constructor
  MyCustomSensor(uint32_t update_interval) : PollingComponent(update_interval) {}

  void setup() override {
    // This will be called by App.setup()
  }
  void update() override {
    // This will be called every "update_interval" milliseconds.
  }
};

sensor:
- platform: custom
  lambda: |-
    auto my_sensor = new MyCustomSensor(5000);
