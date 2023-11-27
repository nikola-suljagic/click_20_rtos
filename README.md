# click_20_rtos


## Description
### This project showcase how FREE RTOS can be used for 
### MirkoE development borad Sensor Fusion for ARMv8

# Project setup
## Setup Sensor fusion for armv8 dev board
* Move pull up on port A swicth SW3
* Connect POWER/DEBUG port to the laptop for downloading and debug firmware purpose
* Conect USB-UART to the laptop
* PA5 button is used as user button


## Cube IDE
### Import project
* Go to File->Import->General->Existing Projects into Workspace
* Navigate to the folder where project reside
* Configuring OpenOCD debugger:
    - Install GNU ARM C/C++ OpenOCD Debugging plugin:<br> 
    ![Alt text](image-2.png)
    - Right click on project and go Debug As -> Debug Configurations -> GDB Open OCD Debugging: <br>
    ![Alt text](image-3.png)
    - Setup debug configuration: <br>
    ![Alt text](image-4.png)
* Configure printf with floating point numbers:
    - Right click on the project and go to Properties -> C/C++ Build -> Settings -> MCU settings 
    - Check 'Use float with printf from (-u_printf_float)': <br>
    ![Alt text](image-5.png)