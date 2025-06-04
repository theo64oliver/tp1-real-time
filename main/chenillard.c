#include "chenillard.h"

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <sdkconfig.h>
#include <esp_log.h>
#include <esp_rom_gpio.h>

/**
 * @brief Task to blink an LED on a specified GPIO pin.
 *
 * This task will toggle the specified GPIO pin on and off every second,
 * logging the state changes to the console.
 *
 * @param pvParameters Pointer to the GPIO number to blink.
 */
void blink_led(void *pvParameters)
{
    int* parameters = (int *)pvParameters;
    int gpio = *parameters;
    
    esp_rom_gpio_pad_select_gpio(gpio);

    gpio_set_direction(gpio, GPIO_MODE_OUTPUT);

    while (1)
    {
        /* Blink off (output low) */
        ESP_LOGI("Blink", "Blink off led %d", gpio);
        gpio_set_level(gpio, 0);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

        /* Blink on (output high) */
        ESP_LOGI("Blink", "Blink on led %d", gpio);
        gpio_set_level(gpio, 1);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL); //Delete this task if it exits from the loop above
}
