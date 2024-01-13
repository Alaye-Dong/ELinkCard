
#include "Arduino.h"
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>
//212 x 104
void setup(){
    Serial.begin(115200);
    DEV_Module_Init();
    printf("e-Paper Init and Clear...\r\n");
    EPD_2IN13D_Init();
    EPD_2IN13D_Clear();
    delay(500);

    //显示图片 
    UBYTE *BlackImage;
    UWORD Imagesize = ((EPD_2IN13D_WIDTH % 8 == 0) ? (EPD_2IN13D_WIDTH / 8 ) : (EPD_2IN13D_WIDTH / 8 + 1)) * EPD_2IN13D_HEIGHT;
    if ((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
        while (1);
    }
    Paint_NewImage(BlackImage, EPD_2IN13D_WIDTH, EPD_2IN13D_HEIGHT, 270, WHITE);
    Paint_SelectImage(BlackImage);
    Paint_Clear(WHITE);

    //显示汉字
    Paint_DrawImage(BST_64, 0, 148, 64, 64);
    Paint_DrawString_CN(88, 0, "软件部", &Font24CN, WHITE, BLACK);
    Paint_DrawString_CN(44, 40, "蓝色技术工作室", &Font24CN, BLACK, WHITE);
    //Paint_DrawString_CN(44, 64, "你好", &Font12CN, BLACK, WHITE);
                                                                                                                                 
    //显示英文字符以及线条
    Paint_DrawLine(0, 64, 212, 64, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);     //1号大横线
    Paint_DrawString_EN(24, 74, "Alaye-Dong", &Font20, WHITE, BLACK);



    EPD_2IN13D_Display(BlackImage);
    DEV_Delay_ms(1000);

    //局部刷新时间测试
    // Paint_SelectImage(BlackImage);
    // PAINT_TIME sPaint_time;
    // sPaint_time.Hour = 12;
    // sPaint_time.Min = 34;
    // sPaint_time.Sec = 56;
    // UBYTE num = 20;
    // for (;;) {
    //     sPaint_time.Sec = sPaint_time.Sec + 1;
    //     if (sPaint_time.Sec == 60) {
    //         sPaint_time.Min = sPaint_time.Min + 1;
    //         sPaint_time.Sec = 0;
    //         if (sPaint_time.Min == 60) {
    //             sPaint_time.Hour =  sPaint_time.Hour + 1;
    //             sPaint_time.Min = 0;
    //             if (sPaint_time.Hour == 24) {
    //                 sPaint_time.Hour = 0;
    //                 sPaint_time.Min = 0;
    //                 sPaint_time.Sec = 0;
    //             }
    //         }
    //     }
    //     Paint_ClearWindows(30, 70, 30 + Font20.Width * 7, 70 + Font20.Height, WHITE);
    //     Paint_DrawTime(30, 70, &sPaint_time, &Font20, WHITE, BLACK);
    //     num = num - 1;
    //     if (num == 0) {
    //         break;
    //     }
    //     EPD_2IN13D_DisplayPart(BlackImage);
    //     DEV_Delay_ms(500);
    // }
}

void loop(){
    delay(1000);
}
