#include "my_interface.h"
#include <stdlib.h>
#include "lvgl/lvgl.h"
#include "fbdev.h"
#include "evdev.h"
#include <unistd.h>
#include <sys/time.h>

#define DISP_BUF_SIZE (800 * 480)

/* ---------- 主菜单 ---------- */
void Show_Main_Menu() 
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_layout(&style , LV_LAYOUT_FLEX);
    lv_style_set_flex_flow(&style , LV_FLEX_FLOW_ROW_WRAP_REVERSE);
    
    lv_obj_t * cont = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont , 300 , 320);
    lv_obj_add_style(cont , &style , 0);

    lv_obj_t * cont_row = lv_obj_create(lv_scr_act());
    lv_obj_set_size(cont_row , 300 , 320);
    lv_obj_align_to(cont_row , cont , LV_ALIGN_OUT_RIGHT_TOP , 30 , 0);
    lv_obj_set_flex_flow(cont_row , LV_FLEX_FLOW_COLUMN_WRAP_REVERSE);
    
    lv_obj_t * obj , * label;
    for (int i = 0; i < 10; i++)
    {   
        obj = lv_btn_create(cont);
        lv_obj_set_size(obj , 100 , LV_PCT(100));
        label = lv_label_create(obj);
        lv_label_set_text_fmt(label , "Item：%u" , i);
        lv_obj_center(label);

        obj = lv_btn_create(cont_row);
        lv_obj_set_size(obj , 100 , LV_PCT(100));
        label = lv_label_create(obj);
        lv_label_set_text_fmt(label , "Item：%u" , i);
        lv_obj_center(label);
    }
}

/* ---------- 主函数 ---------- */
int main(void)
{

    
    while(1) 
    {
        lv_timer_handler();
        usleep(5000);
    }

    return 0;
}

/* 自定义tick函数 */
uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if(start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
