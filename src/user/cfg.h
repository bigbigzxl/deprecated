#ifndef MENU_CFG_H
#define MENU_CFG_H
#include "../ctrl/menuCtrl.h"
#include "../render/display.h"

Display* g_screen = Display::getInstance();



const MenuItem g_user_menus[] = 
{   /**********************************************/
    MENU_LIST_L1,
    "VOL",
    0, // CMD pos.
    NULL,
        /******************************************/
        MENU_SET,
        "000",
        0,     // volume value
        NULL,  // adjust volume function.
    /**********************************************/
    MENU_LIST_L1,
    "DSPL",
    0,  // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "CLR",
        -1,
        NULL,
        // clear_color_r,
        /******************************************/
        MENU_SET,
        "R00",
        0,
        NULL,
        // set_color_g,
        /******************************************/
        MENU_SET,
        "G00",
        -1,
        NULL,
        // set_color,
        /******************************************/
        MENU_SET,
        "B00",
        -1,
        NULL,
        // set_color_b,

    /**********************************************/
    MENU_LIST_L1,
    "INPT",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "AES",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "COS",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "USB",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "I2S",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "BLT",
        -1,
        NULL,
    
    /***********************************************/
    MENU_LIST_L1,
    "PHAS",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "000",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "180",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "PLL",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "FAST",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "ACCU",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "SYNC",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "INT",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "EXT",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "OUPT",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "HPA",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "PRE",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "AMPL",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "LO",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "MI",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "HI",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "TNT",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "OFF",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "ON",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "ADIM",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "5S",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "10S",
        -1,
        NULL,
        /******************************************/
        MENU_CMD,
        "OFF",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "FW",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "S001",
        -1,
        NULL,

    /***********************************************/
    MENU_LIST_L1,
    "SN",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "S0xxx",
        -1,
        NULL,
        
    /***********************************************/
    MENU_LIST_L1,
    "DAT",
    0, // CMD default pos.
    NULL,
        /******************************************/
        MENU_CMD,
        "2209",
        -1,
        NULL,
        
};


#endif