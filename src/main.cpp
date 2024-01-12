
#include "Arduino.h"
#include "DEV_Config.h"
#include "EPD.h"
#include "GUI_Paint.h"
#include "imagedata.h"
#include <stdlib.h>

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
    Paint_DrawImage(BST_64, 0, 0, 64, 64);
    //Paint_DrawString_CN(30, 45, "BST", &Font24CN, BLACK, WHITE);

    //显示英文字符以及线条
    // Paint_DrawLine(6, 10, 6, 20, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawLine(1, 15, 6, 10, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawLine(1, 15, 6, 20, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(7, 10, "IO05", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 5, 210, 5, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 6, "EDP", &Font12, WHITE, BLACK);//表头
    // Paint_DrawString_EN(175, 6, "ESP12", &Font12, WHITE, BLACK);



    // Paint_DrawLine(140, 19, 210, 19, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 20, "MOSI", &Font12, WHITE, BLACK);//mosi
    // Paint_DrawString_EN(178, 20, "IO13", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 33, 210, 33, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 34, "CLK", &Font12, WHITE, BLACK);//clk
    // Paint_DrawString_EN(178, 34, "IO14", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 47, 210, 47, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 48, "CS", &Font12, WHITE, BLACK);//cs
    // Paint_DrawString_EN(178, 48, "IO15", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 61, 210, 61, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 62, "DC", &Font12, WHITE, BLACK);
    // Paint_DrawString_EN(178, 62, "IO00", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 75, 210, 75, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 76, "RST", &Font12, WHITE, BLACK);
    // Paint_DrawString_EN(178, 76, "IO02", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 89, 210, 89, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawString_EN(142, 90, "BUSY", &Font12, WHITE, BLACK);//mosi//busy
    // Paint_DrawString_EN(178, 90, "IO04", &Font12, WHITE, BLACK);

    // Paint_DrawLine(140, 103, 210, 103, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);

    // Paint_DrawLine(140, 5, 140, 103, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawLine(174, 5, 174, 103, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    // Paint_DrawLine(210, 5, 210, 103, BLACK, DOT_PIXEL_1X1, LINE_STYLE_SOLID);


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
