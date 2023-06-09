// #include <Arduino.h>
// #include <math.h>
// #include <ESP32Encoder.h>
// #include <vector>

// #include "OneButton.h"
// #include "FastLED.h"

// #include "Dot2D/dot2d.h"
// #include "Examples/Matrix/Matrix.h"
// // #include "Examples/TripleClick/TripleClick.h"
// // #include "Examples/Snake/Snake.h"
// // #include "Examples/Text/Text.h"

// #include "menu/menuFSM.h"
// #include "ui/menu_ui.h"
// #include "menu/cmd.h"

// // EC11 config
// #define EC11_A_PIN 25
// #define EC11_B_PIN 26
// #define EC11_K_PIN 4
// #define POWER_KEY_PIN 0 // to add.

// // WS2812 LOGO
// #define LOGO_LED_PIN 5

// // WS2812 config
// #define MATRIX_WIDTH 40
// #define MATRIX_HEIGHT 7
// #define MATRIX_LED_PIN 18
// #define MATRIX_MAX_BRIGHTNESS 10

// int32_t lastEncoderValue = 0;
// int32_t delta = 0;

// // extern float Voltage;
// // extern int16_t cur_cmd_index;
// // extern int32_t all_cmd_num;
// // extern char* cur_cmd_values[];
// // extern const char* menu[];
// // extern const int32_t cmd_pos[];
// // extern const char* cmd_items[];
// // extern unsigned char cur_text[9];

// ESP32Encoder spin(false); // true interrupt.
// OneButton spin_key(EC11_K_PIN, false, false);
// OneButton power(POWER_KEY_PIN);
// Menu menuFSM;

// dot2d::Director *director = nullptr;

// void update_cmd_str(void);
// void show_voice_volume(unsigned char vol);

// void click(void);
// void doubleclick(void);
// void longclick(void);

// void poweron()
// {
//     if (!menuFSM.get_power_state())
//     {
//         menuFSM.set_power_state(true); // power on
//     }
// }

// void poweroff()
// {
//     menuFSM.set_power_state(false); // power off
// }

// void click()
// {
//     //   Serial.println("double clicked.");
//     // director->runWithScene(dot2d::Text::create());
//     menuFSM.set_button_state(Menu::ButtonType::CLICK);
// }

// void doubleclick()
// {
//     // director->runWithScene(dot2d::TripleClick::create());
//     menuFSM.set_power_state(!menuFSM.get_power_state()); // for test.

//     Serial.printf("double clicked. %d", menuFSM.get_power_state());
//     menuFSM.set_button_state(Menu::ButtonType::D_CLICK);
// }

// // 按键长按回调函数
// void longclick()
// {
//     //  director->runWithScene(dot2d::Snake::create());
//     // director->runWithScene(dot2d::MenuUi::create());
//     menuFSM.set_button_state(Menu::ButtonType::L_CLICK);
// }

// void callback_boot()
// {
//     // director->runWithScene(dot2d::MenuUi::create()); // power on LOGO render.
//     Serial.println("render boot");
//     // dot2d::MenuUi* s =  (dot2d::MenuUi*)director->getRunningScene();
//     // s->getLayer()->show_logo();
    
// }

// void callback_home()
// {
//     // get FPGA infput info.
//     // unsigned char * input = get_input_from_FPGA();
//     show_8char((unsigned char *)"AES P441");
//     // director->runWithScene(dot2d::Matrix::create()); // power on LOGO render.
//     // Serial.println("render home");
// }

// void callback_spin_menu()
// {        

//     // Serial.printf("cmd_index = %d \n", cur_cmd_index);
//     if (cur_cmd_index < 0)
//     {
//         cur_cmd_index = (cur_cmd_index + all_cmd_num) % all_cmd_num;
//     }
//     else
//     {
//         cur_cmd_index %= all_cmd_num;
//     }
//     update_cmd_str();
//     // director->runWithScene(dot2d::Matrix::create()); // power on LOGO render.
//     // Serial.println("rend menu");
// }

// void callback_spin_cmd()
// {
//     // director->runWithScene(dot2d::Matrix::create()); // power on LOGO render.
//     Serial.println("render cmd");
// }

// // 必须要实现的dot2d导演对象代理方法
// class MainDelegate : public dot2d::DirectorDelegate
// {

//     void render()
//     {
//         FastLED.show();
//         // 输出ESP32内存占用情况
//         // Serial.printf("-----Free Heap Mem : %d [%.2f%%]-----\n",
//         //               ESP.getFreeHeap(),
//         //               ESP.getFreeHeap() / (double)ESP.getHeapSize() * 100);
//         // Serial.printf("-----Free PSRAM Mem: %d [%.2f%%]-----\n",
//         //               ESP.getFreePsram(),
//         //               ESP.getFreePsram() / (double)ESP.getPsramSize() * 100);
//     }

//     size_t write(uint8_t c)
//     {
//         return Serial.write(c);
//     }

//     void initMatrix(dot2d::DTRGB *data)
//     {
//         FastLED.addLeds<WS2812Controller800Khz, MATRIX_LED_PIN, GRB>((CRGB *)data, MATRIX_WIDTH * MATRIX_HEIGHT);
//     }

//     uint32_t dotOrder(uint16_t x, uint16_t y)
//     {
//         uint16_t factor = floor(x / 5);
//         uint32_t order = y * 5 + x % 5 + factor * 35;
//         return order;
//     }
// };

// void setup()
// {
//     Serial.begin(115200);
//     // Serial.printf("ESP32 chip revision : %d\r\n", (int16_t)ESP.getChipRevision());
//     // Serial.printf("ESP32 SDK Version : %s\r\n", ESP.getSdkVersion());
//     // Serial.printf("ESP32 Speed : %u MHz\r\n", ESP.getCpuFreqMHz());
//     // Serial.print("Task render function running on core: ");
//     // Serial.println(xPortGetCoreID());
//     FastLED.setBrightness(MATRIX_MAX_BRIGHTNESS);

//     // init ec11-spin.
//     ESP32Encoder::useInternalWeakPullResistors = UP;
//     spin.attachSingleEdge(EC11_A_PIN, EC11_B_PIN);

//     // init ec11-button.
//     spin_key.attachClick(click);
//     spin_key.attachDoubleClick(doubleclick);
//     spin_key.attachLongPressStop(longclick);
//     // spin_key.setDebounceTicks(20);//滤波(ms)
//     // spin_key.setClickTicks(200);
//     // spin_key.setPressTicks(500);

//     power.attachClick(poweron);
//     power.attachLongPressStop(poweroff);

//     menuFSM.attachBoot(callback_boot);
//     menuFSM.attachHome(callback_home);
//     menuFSM.attachSpinMenu(callback_spin_menu);
//     menuFSM.attachSpinCmd(callback_spin_cmd);


//     // show_voice_volume(100); // test

//     // init engine and init  canvas.
//     director = dot2d::Director::getInstance();            // get director object.
//     director->setDelegate(new MainDelegate());            // set director delegate.
//     director->setFramesPerSecond(30);                     // set FPS.
//     director->initDotCanvas(MATRIX_WIDTH, MATRIX_HEIGHT); // init director canvas.
//     director->runWithScene(dot2d::MenuUi::create());
//     Serial.println("#############setup done.##################\n");
// }

// void loop()
// {
//     // spin_key.tick();
//     // if (lastEncoderValue != spin.getCount())
//     // {
//     //     int now_count = spin.getCount();
//     //     delta = now_count - lastEncoderValue; // global value
//     //     lastEncoderValue = now_count;
//     //     menuFSM.update_delta(delta);
//     //     // Serial.printf("delta = %d \n", delta);

//     // }
//     // menuFSM.tick();

//     // unsigned long start = millis(); // current (relative) time in msecs.
//     director->mainLoop();
//     // unsigned long end = millis(); // current (relative) time in msecs.
//     // Serial.printf("%d \n", end - start);
// }
