import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_ID

DEPENDENCIES = ["i2c"]

CONF_I2C_ADDR = 0x13

empty_component_ns = cg.esphome_ns.namespace("ES72432")
EmptyComponent = empty_component_ns.class_("ES72432", cg.Component)

CONFIG_SCHEMA = (
    cv.Schema({cv.GenerateID(): cv.declare_id(EmptyComponent)})
    .extend(cv.COMPONENT_SCHEMA)
    .extend(i2c.i2c_device_schema(CONF_I2C_ADDR))
)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
    yield i2c.register_i2c_device(var, config)
