#include "menuCtrl.h"

void menu_ctrl::show_volume(void);
void menu_ctrl::show_home(void)
{
    uint32_t infos = get_info_from_FPGA();
    if (infos != _info_from_FPGA)
    { // update
        _info_from_FPGA = infos;
        callback_home();
        _fresh_starttime();
        }
}
