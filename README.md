# esp32-devkitv1-zephyr
Repository to simplify your journey on Zephyr RTOS using the ESP-WROOM-32 DevKit V1 module.
  
todo: add sdk install instructions

### Initialization

The first step is to initialize the workspace folder (``workspace``) where
the ``esp32-devkitv1-zephyr`` and all Zephyr modules will be cloned. Run the following
command:

```shell
# initialize workspace for the esp32-devkitv1-zephyr (main branch)
west init -m https://github.com/joaocarlosfr/esp32-devkitv1-zephyr --mr main workspace
# update Zephyr modules
cd workspace
west update
```

### Building and running

To build the application, run the following command:

```shell
cd esp32-devkitv1-zephyr
west build -b esp32_devkit1_wroom/esp32/procpu examples/hello_world -DBOARD_ROOT=../../
```

where `$BOARD` is the target board.
