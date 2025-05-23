#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <sdkconfig.h>
#include <esp_log.h>
#include <esp_rom_gpio.h>

#include "chenillard.h"

#define BLINK_GPIO 4
#define STACK_SIZE 2048

void app_main()
{
    int gpio4 = 4;
    int gpio2 = 2;
    int gpio13 = 13;
    int gpio12 = 12;

    xTaskCreate(blink_led,
                "blink_led3",
                2048,
                &gpio4,
                5,
                NULL);

    vTaskDelay(250 / portTICK_PERIOD_MS);
    xTaskCreate(blink_led,
                "blink_led2",
                2048,
                &gpio2,
                5,
                NULL);

    vTaskDelay(250 / portTICK_PERIOD_MS);
    xTaskCreate(blink_led,
                "blink_led13",
                2048,
                &gpio13,
                5,
                NULL);

    vTaskDelay(250 / portTICK_PERIOD_MS);
    xTaskCreate(blink_led,
                "blink_led12",
                2048,
                &gpio12,
                5,
                NULL);
} 
