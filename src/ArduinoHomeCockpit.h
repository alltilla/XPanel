#pragma once
#include <stdlib.h>
#include "UsbHidDevice.h"

class ArduinoHomeCockpit :public UsbHidDevice
{
private:
	std::vector<PanelButton> arduino_buttons;
	std::vector<PanelDisplay> arduino_displays;
	int read_board_configuration(std::string file_name, int expected_vid, int expected_pid);

	unsigned int register_index;
	const std::string TOKEN_DEVICE = "\\[device:id=\"([a-zA-Z0-9_-]+)\"\\]";
	const std::string TOKEN_VID = "vid=\"(.+)\"";
	const std::string TOKEN_PID = "pid=\"(.+)\"";
	const std::string TOKEN_REGISTER = "\\[register:adr=([0-9]+)\\]";
	const std::string TOKEN_BUTTON = "button:id=\"([a-zA-Z0-9_-]+)\",bit=([0-9]+)";
	const std::string TOKEN_DISPLAY = "display:id=\"([a-zA-Z0-9_-]+)\",width=([0-9]+)";
public:
	ArduinoHomeCockpit(DeviceConfiguration& config);
	int connect();
	void start();
	void stop(int timeout);
};

