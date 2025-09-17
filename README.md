# esp32-devkitv1-zephyr  
Repository to simplify your journey on Zephyr RTOS using the ESP-WROOM-32 DevKit V1 module.  
  
### Install Linux required dependecies  

```shell
sudo apt install --no-install-recommends git cmake ninja-build gperf \
  ccache dfu-util device-tree-compiler wget python3-dev python3-venv python3-tk \
  xz-utils file make gcc gcc-multilib g++-multilib libsdl2-dev libmagic1
```

### Install west  

1. Create a new virtual environment:  
```shell
python3 -m venv ~/zephyrproject/.venv
```

2. Activate the virtual environment:  
```shell
source ~/zephyrproject/.venv/bin/activate
```

3. Install west:  
```shell
pip install west
```  

4. Export a Zephyr CMake package. This allows CMake to automatically load boilerplate code required for building Zephyr applications. 
```shell
west zephyr-export
```  

5. Install Python dependencies using west packages. 

```shell
west packages pip --install
```  

### Install Zephyr SDK

1. Download and verify the Zephyr SDK bundle:  
```shell
cd ~
wget https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/zephyr-sdk-0.17.0_linux-x86_64.tar.xz
wget -O - https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0/sha256.sum | shasum --check --ignore-missing
```  

2. Extract the Zephyr SDK bundle archive:  
```shell
tar xvf zephyr-sdk-0.17.0_linux-x86_64.tar.xz
```  

3. Run the Zephyr SDK bundle setup script:
```shell
cd zephyr-sdk-0.17.0
./setup.sh
```  

4. Install udev rules, which allow you to flash most Zephyr boards as a regular user:  
```shell
sudo cp ~/zephyr-sdk-0.17.4/sysroots/x86_64-pokysdk-linux/usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d
sudo udevadm control --reload
```  

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
