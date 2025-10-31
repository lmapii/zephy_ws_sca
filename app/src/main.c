
#include <zephyr/drivers/gpio.h>
#include <zephyr/input/input.h>
#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(app, LOG_LEVEL_DBG);

/***************************************************************************************************
 * Definitions
 **************************************************************************************************/

#define SLEEP_TIME_MS 1000U

static void prv_input_cb_all(struct input_event *evt, void *user_data);

/***************************************************************************************************
 * Data
 **************************************************************************************************/

static const struct device *const buttons_dev = DEVICE_DT_GET(DT_NODELABEL(buttons));

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios);

INPUT_CALLBACK_DEFINE(NULL, prv_input_cb_all, NULL);

/***************************************************************************************************
 * Functions
 **************************************************************************************************/

static void unused_function(void)
{
	LOG_DBG("oh, my");
}

static void prv_input_cb_all(struct input_event *evt, void *user_data)
{
	__ASSERT_NO_MSG(evt != NULL);
	(void)user_data;

	LOG_DBG("INPUT %s, zephyr_code=%u, value=%d\n", evt->dev->name, evt->code, evt->value);
}

static void prv_cfg_led(const struct gpio_dt_spec *spec)
{
	bool ready = gpio_is_ready_dt(spec);
	__ASSERT_NO_MSG(ready);

	int ret = gpio_pin_configure_dt(spec, GPIO_OUTPUT_ACTIVE);
	__ASSERT_NO_MSG(ret >= 0);

	ret = gpio_pin_set_dt(spec, 0);
	__ASSERT_NO_MSG(ret >= 0);
}

int main(void)
{
	prv_cfg_led(&led0);
	prv_cfg_led(&led1);

	char a[10];
	a[10] = 0 / 0;
	return 0;

	while (1) {
		k_msleep(SLEEP_TIME_MS);
	}
}
