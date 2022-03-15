#include <string.h>

#include <stdbool.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "app_temp.h"
#include "app_wifi.h"
#define TAG "app"
#ifndef MQTT_BROKER_URL
#define MQTT_BROKER_URL "mqtt://aghiv1:AghiProject@aghiv1.cloud.shiftr.io"
#endif
#define SENSOR_NO "1"
#define NABLE_TOPIC "home/" SENSOR_NO "/enable"
#define TEMP_TOPIC "home/temperature/" SENSOR_NO
#define HUM_TOPIC "home/humidity/" SENSOR_NO
static esp_mqtt_client_handle_t client = NULL;
static bool enabled = false;

void app_main()
{
    esp_event_loop_create_default();
    connect_wifi_params_t cbs = {
        .on_connected = handle_wifi_connect,
        .on_failed = handle_wifi_failed};
    appwifi_connect(cbs);
}
