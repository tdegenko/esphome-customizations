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
    const uint8_t mode_val = 0x01;
    // set to "Software Mode" whatever that does?
    this->write_register(0x00, &mode_val, 1);
    this->write_register(REGISTER_ADDRESS, &register_value, 1);
    const uint8_t gain_val = 0x43;
    this->write_register(0x08, &gain_val, 1);
    ESP_LOGD(TAG, "Bits/sample Configured");
}

void ES72432::loop() {

}

void ES72432::dump_config(){
    ESP_LOGCONFIG(TAG, "ES72432");
    uint8_t data;
    char out[20];
    for( uint8_t r = 0; r<= 0x0e; r++){
        this->read_register(r, &data, 1);
        snprintf(out,20 ,"r%x -> %x", r, data);
        ESP_LOGD(TAG, out);
    }
}


}  // namespace ES72432
}  // namespace esphome
