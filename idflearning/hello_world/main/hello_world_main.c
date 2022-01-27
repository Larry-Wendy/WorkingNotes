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
#include "esp_task_wdt.h"
#include "freertos/queue.h"

// typedef struct  myStruct
// {
//     int Mem1;
//     float Mem2;
// } xStruct;

// xStruct xStrTest = {4, 2.2};
// static const char *pString = "this is a string!";
//------------------------------------------------
void sendTask(void *pvParam)
{
    QueueHandle_t QHandle;
    QHandle = (QueueHandle_t)pvParam;
    BaseType_t xStatus;
    int i = 0;

    while (1)
    {
        xStatus = xQueueSend(QHandle, &i, 0);
        if (xStatus != pdPASS)
        {
            printf("send fail!\n");
        }
        else
        {
            printf("send successful!\n");
        }
        i++;
        if (i == 8)
            i = 0;
        // printf("task1-111\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        // vTaskSuspend(NULL);
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

void recTask(void *pvParam)
{
    QueueHandle_t QHandle;
    QHandle = (QueueHandle_t)pvParam;
    BaseType_t xStatus;
    int j = 0;

    while (1)
    {
        if (uxQueueMessagesWaiting(QHandle) != 0)
        {
            xStatus = xQueueReceive(QHandle, &j, 0);
            if (xStatus != pdPASS)
            {
                printf("rec fail!\n");
            }
            else
            {
                printf("rec j=%d\n", j);
            }
            vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
        else
        {
            printf("no data!\n");
        }
    }
}

//------------------------------------------------

void app_main(void)
{
    TaskHandle_t myHandle1 = NULL;
    // TaskHandle_t myHandle2 = NULL;
    // UBaseType_t iPriority1 = 0;
    // UBaseType_t iPriority2 = 0;
    QueueHandle_t QHandle;
    QHandle = xQueueCreate(5, sizeof(int));

    if (QHandle != NULL)
    {
        printf("Create queue successfully!\n");

        xTaskCreate(sendTask, "sendTask", 1024 * 5, (void *)QHandle, 1, NULL);
        xTaskCreate(recTask, "recTask", 1024 * 5, (void *)QHandle, 1, NULL);
    }
    else
    {
        printf("Can't create queue!\n");
    }

    //

    // UBaseType_t iStack;
    // while(1)
    // {
    //     iStack = uxTaskGetStackHighWaterMark(myHandle1);
    //     printf("task1 iStack = %d\n", iStack);

    //     vTaskDelay(3000 / portTICK_PERIOD_MS);
    // }
    // static char pcWriteBuffer[512] = {0};
    // vTaskList(pcWriteBuffer);

    // printf("-----------------------------------------------------------\n");
    // printf("Name    State   Priority    Stack   Num\n");
    // printf("%s\n",pcWriteBuffer);
    // printf("-----------------------------------------------------------\n");
    // // vTaskDelay(5000 / portTICK_PERIOD_MS);
    // vTaskResume(myHandle1);

    // vTaskSuspend(myHandle1);
    // iPriority1 = uxTaskPriorityGet(myHandle1);
    // iPriority2 = uxTaskPriorityGet(myHandle2);
    // printf("iPriority1 = %d\n", iPriority1);
    // printf("iPriority2 = %d\n", iPriority2);
    // vTaskDelay(1000 / portTICK_PERIOD_MS);

    // if (myHandle != NULL)
    //     vTaskDelete( myHandle );
}
