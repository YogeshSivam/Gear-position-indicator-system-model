# Gear-position-indicator-system-model
Developed a system to display the gear position on an LCD, ensuring accurate gear detection and reliable data transmission using UART communication protocol with 8-bit PIC Microcontroller.

#Table of contents
-[Requirements] (#Requirements)
-[Process] (#Process)
-[usage] (#Usage)

#Requirements
- Data sheet
1. Controller - [PIC16F887] (https://ww1.microchip.com/downloads/en/DeviceDoc/41291D.pdf)
2. Display - [16X2 LCD] (https://www.alldatasheet.com/category/index.jsp?sSearchword=16x2%20lcd%20datasheet)
- Software
1. simulation software - [Proteus 8 Professional] (https://www.labcenter.com/free-trial/)
2. IDE - [MPLAB X IDE v6.20] (https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide)
- Hardware
1. Controller - [Pic16f887] (https://www.microchip.com/en-us/product/PIC16F887)
2. jumper wires
3. 16X2 LCD
4. Push Button

#process 
MUST REFER DATA SHEETS BEFORE SETTING UP AND PROGRAMMING
- Simulation
1. Install Simulation software and design the circuit the way you want the pins are connected and configure the settings.
- Programming
1. Install the IDE and create  a new project and create a file as main.c.
2. set the configuration bits.
3. compile and run the project.
4. Verify whether the .hex file is created.
5. upload the .hex file into the circuit design for both transmission and receiving controller.
6. Check the simulation works properly.
- Interfacing with hardware
1. Interface the two controllers by connecting the UART pins on both.
2. Inteface the 16x2 LCD in PORTD as we programmed.
3. Connect the push buttons using jumper wires in PORTA as we programmed.
4. Connect the power supply.

#Usage 
- Gained the knowledge of programming the peripherals of 8-bit controller and hands on experience.
- It is used to learn the UART protocol which is used to intialize the serial communication from one controller to another.
- Understanding the fundamentals of LCD by sending the data through parallel communication and programmed some commands like (configure the LCD to use 8-bit, 4- bit, 1 line, 2 line, Display, Cursor, Force cursor to begin based on the address).
- It can be developed as a project for students to enhance their skills in embedded systems. 
