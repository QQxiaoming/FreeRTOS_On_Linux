#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"

static TaskHandle_t xTask = NULL;

static void task(void *p)
{
    int cnt = 0;

    for(;;)
    {
        printf("task %x\n", cnt++);
        vTaskDelay(1000);
    }
}


int main(void)
{
    BaseType_t xReturn = pdPASS;

    printf("Freertos v10.2.1\n");
    fflush(stdout);

    xReturn = xTaskCreate(  (TaskFunction_t )task,
                            (const char *   )"task",
                            (unsigned short )128,
                            (void *         )NULL,
                            (UBaseType_t    )1,
                            (TaskHandle_t * )&xTask);

    if (pdPASS != xReturn){
        return -1;
    }

    vTaskStartScheduler();

    while(1);
    return 0;
}
