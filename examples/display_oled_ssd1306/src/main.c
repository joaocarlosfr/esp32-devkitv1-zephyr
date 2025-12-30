#include <stdint.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/display.h>
#include <zephyr/logging/log.h>

#include "batman.h"

#define DISPLAY_BUFFER_PITCH 128

LOG_MODULE_REGISTER(display);

static const struct device *display = DEVICE_DT_GET(DT_NODELABEL(ssd1306));

void main(void)
{
	if(display == NULL)
	{
		LOG_ERR("Display device pointer is NULL!");
		return;
	}

	if(!device_is_ready(display))
	{
		LOG_ERR("Display device is not ready!");
		return;
	}

	struct display_capabilities info;
	display_get_capabilities(display, &info);

	const struct display_buffer_descriptor buffer_descriptor = {
		.width = info.x_resolution,
		.height = info.y_resolution,
		.buf_size = info.x_resolution * info.y_resolution,
		.pitch = DISPLAY_BUFFER_PITCH
	};

	LOG_INF("Display Capabilities Report:");
	LOG_INF("Resolution X,Y: %d, %d", info.x_resolution, info.y_resolution);
	LOG_INF("Current Orientation: %d", info.current_orientation);
	LOG_INF("Screen Info: %d", info.screen_info);
	LOG_INF("Supported Pixel Formats: %d", info.supported_pixel_formats);
	LOG_INF("Current Pixel Format: %d", info.current_pixel_format);

	if(display_write(display, 0, 0, &buffer_descriptor, batman_buffer) != 0)
	{
		LOG_ERR("Could not write to display!");
	}

	if(display_set_contrast(display, 0) != 0)
	{
		LOG_ERR("Could not set display contrast!");
	}

	while(true) 
	{
		// Increase Brightness
		for (size_t i = 0; i < 255; i++) {
			display_set_contrast(display, i);
			k_sleep(K_MSEC(5));
		}

		// Decrease Brightness
		for (size_t i = 255; i > 0; i--) {
			display_set_contrast(display, i);
			k_sleep(K_MSEC(5));
		}
	}
}