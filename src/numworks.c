/*

    numworks.c
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
*/



#include "main.h"
#include "extapp_api.h"
#include "numworks.h"



// to get a character but non blocking
void init_platform() {
    clear_screen();
}


void gracefully_shutdown(char* message) {
    clear_screen();
    // Print the end text
    print_at(0, 0, message);
    uni_sleep(1000);
}


void print_at(int x, int y, char * text) {
    // The screen is 320 x 240 px
    // We divide the screen by 15 squares vertically and 20 squares
    // horizontally of 16 pixels each side.
    extapp_drawTextSmall(text, x*10, y*10, 0X0000, 0XFFFF, false);
    extapp_waitForVBlank();
}


void draw_sth(int x, int y, DrawObject draw_object) {
    // The screen is 320 x 240 px
    // We divide the screen by 24 squares vertically and 32 squares
    // horizontally of 10 pixels each side.
    // Because we draw on the playground, we avoid the first line so we add
    // 10 to y coordinates.
    switch(draw_object) {
        case snake_body:
            extapp_pushRectUniform(x*10, y*10+10, 10, 10, 0x0F00);
            break;
        case fruit_dr:
            extapp_pushRectUniform(x*10, y*10+10, 10, 10, 0xF000);
            break;
        case nothing_dr:
            extapp_pushRectUniform(x*10, y*10+10, 10, 10, 0xFFFF);
            break;
    }
    extapp_waitForVBlank();
}


// to get a character but non blocking
Control get_control_non_blocking() {
    
    if      (extapp_isKeydown(KEY_CTRL_UP))  {
        return up;
    } else if (extapp_isKeydown(KEY_CTRL_LEFT)) {
        return left;
    } else if (extapp_isKeydown(KEY_CTRL_DOWN)) {
        return down;
    } else if (extapp_isKeydown(KEY_CTRL_RIGHT)) { 
        return right;
    } else if (extapp_isKeydown(KEY_CTRL_OK)) {
        return holdon;
    } else if (extapp_isKeydown(KEY_CTRL_EXIT)) {   
        return end_game;
    } else if (extapp_isKeydown(KEY_CTRL_MENU)) { 
        return quit;
    } else if (extapp_isKeydown(KEY_CTRL_LEFT)) { 
        return zero;
    } else if (extapp_isKeydown(KEY_CHAR_B)) { 
        return one;
    } else if (extapp_isKeydown(KEY_CHAR_C)) {
        return two;
    } else if (extapp_isKeydown(KEY_CHAR_3)) {    
        return three;
    } else if (extapp_isKeydown(KEY_CHAR_4)) {    
        return four;
    } else {
        return nullissime; 
    }
}


// To get a character but blocking
Control get_control_blocking() {
    int key = extapp_getKey(0, 0);
    switch (key) {
        case KEY_CHAR_0:
            return zero;
            break;
        case KEY_CHAR_1:
            return one;
            break;
        case KEY_CHAR_2:
            return two;
            break;
        case KEY_CHAR_3:
            return three;
            break;
        case KEY_CHAR_4:
            return four;
            break;
        case KEY_CTRL_MENU:
            return quit;
            break;
        case KEY_CTRL_EXIT:
            return end_game;
            break;
        case KEY_CTRL_OK:
            return holdon;
            break;
        case KEY_CTRL_RIGHT:
            return right;
            break;
        case KEY_CTRL_DOWN:
            return down;
            break;
        case KEY_CTRL_LEFT:
            return left;
            break;
        case KEY_CTRL_UP:
            return up;
            break;
        default:
            return nullissime;
            break;
    }     
}


void clear_screen() {
    // Draw a rectangle to fill all the screen
    extapp_pushRectUniform(0, 0, 320, 240, 0xFFFF);
    extapp_waitForVBlank();
}


int screen_x() {
    // The screen is 320 x 240 px
    // We divide the screen by 15 squares vertically and 20 squares
    // horizontally of 16 pixels each side.
    return 32;
}


int screen_y() {
    // The screen is 320 x 240 px
    // We divide the screen by 15 squares vertically and 20 squares
    // horizontally of 16 pixels each side.
    return 24;
}


void uni_sleep(int time_ms) {
    extapp_msleep(time_ms);
}


void draw_top_separator(int x) {
    /* Draw some sort of black bar on top to show that the first line is not
    usable. */
    extapp_pushRectUniform(x*10, 13, 10, 3, 0X0000);
    extapp_waitForVBlank();
}
