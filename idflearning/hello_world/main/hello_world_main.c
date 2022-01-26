/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

// typedef struct  myStruct
// {
//     int Mem1;
//     float Mem2;
// } xStruct;

// xStruct xStrTest = {4, 2.2};
// static const char *pString = "this is a string!";
//------------------------------------------------
void myTask1(void *pvParam)
{
    while (1)
    {
        printf("task1-111\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        vTaskSuspend(NULL);
    }

    // char *pTxt;

    // pTxt = (char *)pvParam;

    // printf("i got string = %s\n", pTxt);
    // // printf("i got struct Num2 = %f\n",pStrTest->Mem2);

    // vTaskDelay(1000 / portTICK_PERIOD_MS);

    // // while(1)
    // {
    //     printf("1 hello world!\n");
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);

    //     printf("2 hello world!\n");
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);

    //     printf("3 hello world!\n");
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // }

    // vTaskDelete(NULL);
}

void myTask2(void *pvParam)
{
    while (1)
    {
        printf("task2-222\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

//------------------------------------------------

void app_main(void)
{
    TaskHandle_t myHandle1 = NULL;
    TaskHandle_t myHandle2 = NULL;
    UBaseType_t iPriority1 = 0;
    UBaseType_t iPriority2 = 0;
    xTaskCreate(myTask1, "myTask1", 2048, NULL, 1, &myHandle1);
    xTaskCreate(myTask2, "myTask2", 2048, NULL, 2, &myHandle2);

    
    vTaskDelay(5000 / portTICK_PERIOD_MS);
    vTaskResume(myHandle1);
    
    // vTaskSuspend(myHandle1);
    // iPriority1 = uxTaskPriorityGet(myHandle1);
    // iPriority2 = uxTaskPriorityGet(myHandle2);
    // printf("iPriority1 = %d\n", iPriority1);
    // printf("iPriority2 = %d\n", iPriority2);
    // vTaskDelay(1000 / portTICK_PERIOD_MS);

    // if (myHandle != NULL)
    //     vTaskDelete( myHandle );
}
