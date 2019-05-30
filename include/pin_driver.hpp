#ifndef RVT_PIN_DRIVER_HPP
#define RVT_PIN_DRIVER_HPP

#include <vector>

namespace hardware
{

enum class gpio_pin
{
    P8_3  = 38,  P8_4  = 39,
    P8_5  = 34,  P8_6  = 35,
    P8_7  = 66,  P8_8  = 67,
    P8_9  = 69,  P8_10 = 68,
    P8_11 = 45,  P8_12 = 44,
    P8_13 = 23,  P8_14 = 26,
    P8_15 = 47,  P8_16 = 46,
    P8_17 = 27,  P8_18 = 65,
    P8_19 = 22,  P8_20 = 63,
    P8_21 = 62,  P8_22 = 37,
    P8_23 = 36,  P8_24 = 33,
    P8_25 = 32,  P8_26 = 61,
    P8_27 = 86,  P8_28 = 88,
    P8_29 = 87,  P8_30 = 89,
    P8_31 = 10,  P8_32 = 11,
    P8_33 = 9,   P8_34 = 81,
    P8_35 = 8,   P8_36 = 80,
    P8_37 = 78,  P8_38 = 79,
    P8_39 = 76,  P8_40 = 77,
    P8_41 = 74,  P8_42 = 75,
    P8_43 = 72,  P8_44 = 73,
    P8_45 = 70,  P8_46 = 71,

    P9_11 = 30,  P9_12 = 60,
    P9_13 = 31,  P9_14 = 50,
    P9_15 = 48,  P9_16 = 51,
    P9_17 = 5,   P9_18 = 4,

    P9_21 = 3,   P9_22 = 2,
    P9_23 = 49,  P9_24 = 15,
    P9_25 = 117, P9_26 = 14,
    P9_27 = 115, P9_28 = 113,
    P9_29 = 111, P9_30 = 112,
    P9_31 = 110,

    P9_41 = 20,  P9_42 = 7
};

enum class adc_pin
{
    P9_33 = 4,
    P9_35 = 6,   P9_36 = 5,
    P9_37 = 2,   P9_38 = 3,
    P9_39 = 0,   P9_40 = 1
};

class pin_driver
{
    public:

    pin_driver();

    ~pin_driver();

    bool read(gpio_pin);

    void write(gpio_pin, bool state);

    double read(adc_pin);

    static const std::vector<gpio_pin>& gpios();

    static const std::vector<adc_pin>& adcs();
};

} // namespace hardware

#endif // RVT_PIN_DRIVER_HPP
