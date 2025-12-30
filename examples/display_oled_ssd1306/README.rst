.. zephyr:code-sample:: display_oled_ssd1306
   :name: Display OLED SSD1306
   :relevant-api: display
   
   Print Batman logo on OLED Display.

Overview
********

This sample shows how to use the Zephyr :ref:`display` API driver for the
`SSD1306`_ 128 x 64 display.

.. _SSD1306:
   https://www.solomon-systech.com/product/ssd1306/

Building and Running
********************

The sample can be configured to support SSD1306 128x64 OLED display connected via I2C. 
Configuration is done via :ref:`devicetree <dt-guide>`. The devicetree
must have an enabled node with ``ssd1306: ssd1306@3c {``. See
`Zephyr SSD1306`_ for the devicetree binding and see below for
examples and common configurations.

If the sensor is not built into your board, start by wiring the sensor pins
according to the connection diagram given in the shield

.. _Zephyr SSD1306:
   https://docs.zephyrproject.org/latest/boards/shields/ssd1306/doc/index.html

Sample Output
=============

.. code-block:: console

[00:00:00.147,000] <inf> display: Display Capabilities Report:
[00:00:00.147,000] <inf> display: Resolution X,Y: 128, 64
[00:00:00.147,000] <inf> display: Current Orientation: 0
[00:00:00.147,000] <inf> display: Screen Info: 1
[00:00:00.147,000] <inf> display: Supported Pixel Formats: 6
[00:00:00.147,000] <inf> display: Current Pixel Format: 2

