#include "esphome/core/log.h"
#include "ES72432.h"

namespace esphome {
namespace ES72432 {

const uint8_t I2C_ADDRESS = 0x13;
const uint8_t REGISTER_ADDRESS = 0x01;
const uint8_t register_value = 0x00 ^ (0b011 << 2);



static const char *TAG = "ES72432.component";

void ES72432::setup() {
    this->write_register(REGISTER_ADDRESS, &register_value, 1);
}

void ES72432::loop() {

}

void ES72432::dump_config(){
    ESP_LOGCONFIG(TAG, "Empty component");
}


}  // namespace ES72432
}  // namespace esphome
