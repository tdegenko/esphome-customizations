#pragma once
#include "esphome.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace ES72432 {

class ES72432 : public Component, public i2c::I2CDevice {
 public:
//  ES72432(I2CBus *bus, uint8_t address = I2C_ADDRESS){
//    set_i2c_address(address);
//    set_i2c_bus(bus)
//    }
    float get_setup_priority() const override { return esphome::setup_priority::BUS; } //Access I2C bus

    void setup() override;
    void loop() override;
    void dump_config() override;
};


}  // namespace ES72432
}  // namespace esphome
