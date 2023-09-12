#include "esphome/core/log.h"
#include "ES72432.h"

namespace esphome {
namespace ES72432 {

const uint8_t I2C_ADDRESS = 0x13;
const uint8_t REGISTER_ADDRESS = 0x01;
const uint8_t register_value = 0x00 ^ (0b011 << 2);



static const char *TAG = "ES72432.component";

void ES72432::setup() {
    ESP_LOGCONFIG(TAG, "Empty component");
    ESP_LOGD(TAG, "Setting up bits/sample");
    this->write_register(REGISTER_ADDRESS, &register_value, 1);
    ESP_LOGD(TAG, "Bits/sample Configured");
}

void ES72432::loop() {
    uint8_t data[2];
    this->read_register(REGISTER_ADDRESS, data, 1);
    char out[20];
    snprintf(out,20 ,"%x%x", data[0],data[1]);
    ESP_LOGD(TAG, out);

}

void ES72432::dump_config(){
    ESP_LOGCONFIG(TAG, "ES72432");
}


}  // namespace ES72432
}  // namespace esphome
