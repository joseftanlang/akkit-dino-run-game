# Ak Base Kit - Dino Game

## Dino Game picture
<table align="center">
  <tr>
    <td align="center"><img src="resources/dino_game_running.png" alt="Dino game" width="512" height="256"/></td>
  </tr>
</table>
<p align="center"><strong><em>Figure 1:</em></strong> The Dino Game</p>

## Tables of Content
<!--ts-->
   * [Overview](#OverView)
   * [Features](#Features)
   * [Hardware](#Hardware)
   * [Software](#Software)
   * [Folder Structure](#structure)
   * [Getting Started](#getstart)
   * [Programming and Flashing](#pnf)
   * [Game modules](#gamemod)
   * [Development](#develop)
   * [Troubleshooting](#troubleshoot)
   * [Game sample](#gamesamp)
   * [Location](#location)
   * [Liscence](#liscence)
   * [Additional Resources](#addresource)
<!--te-->

## Overview

This STM32L151 Ak-Kit project is inspired by the offline dinosaur game (https://trex-runner.com/) developed by Google. In the game, the main character, the dinosaur, must jump or duck to avoid oncoming obstacles such as birds and cacti. The primary goal is to survive as long as possible by skillfully navigating these challenges. Each 100 milliseconds of survival increases your score by 1 point, motivating players to maintain focus and endurance. To keep the game moving, press the UP button to make the dinosaur jump and avoid the obstacles. You can adjust the game speed through the settings menu. Additionally, the sound can be enabled or disabled in the same settings menu, allowing for a customizable gaming experience.

## Features
<details>
    <summary> Jump and Duck to avoid obstacles </summary>
    Jump and duck to avoid oncoming obstacles (cacti and birds).
</details>
<details>
    <summary> Time based scoring system </summary>
    Score increases continuously while surviving (score increments per tick/time).
</details>
<details>
    <summary> Multiple obstacles type </summary>
    Ground cacti (several sprite types) and occasional flying birds.
</details>
<details>
    <summary> Abjsutable game speed </summary>
    Speed setting affects obstacle/bird velocity and jump timing.
</details>
<details>
    <summary> Game state and timers </summary>
    Uses timers for game ticks and obstacle spawn, end-screen display, restart logic, and limited on-screen obstacles.
</details>

## Hardware
ST state-of-the-art patented technology

<table align="center">
  <tr>
    <td align="center"><img src="resources/akkit_architecture.png" alt="akkit arch" width="620" height="290"/></td>
  </tr>
</table>
<p align="center"><strong><em>Figure 1:</em></strong> The Dino Game</p>
<details>  
    <summary>Ultra-low-power platform</summary>
            1.65 V to 3.6 V power supply
            -40°C to 105°C temperature range
            305 nA Standby mode (3 wakeup pins)
            1.15 µA Standby mode + RTC
            0.475 µA Stop mode (16 wakeup lines)
            1.35 µA Stop mode + RTC
            11 µA Low-power run mode
            230 µA/MHz Run mode
            10 nA ultra-low I/O leakage
            8 µs wakeup time
</details> 
<details>   
    <summary>Core: Arm® Cortex®-M3 32-bit CPU</summary>
            From 32 kHz up to 32 MHz max
            33.3 DMIPS peak (Dhrystone 2.1)
            Memory protection unit
            Up to 34 capacitive sensing channels
            CRC calculation unit, 96-bit unique ID
</details>  
<details>
        <summary>Reset and supply management</summary>
            Low-power, ultrasafe BOR (brownout reset) with 5 selectable thresholds
            Ultra-low-power POR/PDR
            Programmable voltage detector (PVD)
</details> 
<details>
        <summary>Clock sources</summary>
            1 to 24 MHz crystal oscillator
            32 kHz oscillator for RTC with calibration
            High Speed Internal 16 MHz factory-trimmed RC (+/- 1%)
            Internal low-power 37 kHz RC
            Internal multispeed low-power 65 kHz to 4.2 MHz
            PLL for CPU clock and USB (48 MHz)
</details>
<details>
        <summary>Pre-programmed bootloader</summary>
            USB and USART supported
        Serial wire debug, JTAG and trace
        Up to 116 fast I/Os (102 I/Os 5V tolerant), all mappable on 16 external interrupt vectors
</details>
<details>
        <summary>Memories</summary>
            384 Kbytes of Flash memory with ECC (with 2 banks of 192 Kbytes enabling Rww capability)
            48 Kbytes of RAM
            12 Kbytes of true EEPROM with ECC
            128-byte backup register
            Memory interface controller supporting SRAM, PSRAM and NOR Flash
        LCD driver (except STM32L151xD devices) up to 8x40 segments, contrast adjustment, blinking mode, step-up converter
</details>
<details>
        <summary>Rich analog peripherals (down to 1.8V)</summary>
            3x operational amplifiers
            12-bit ADC 1 Msps up to 40 channels
            12-bit DAC 2 ch with output buffers
            2x ultra-low-power-comparators(window mode and wakeup capability)
</details>
<details>
        <summary>DMA controller 12x channels</summary>
        12x peripheral communication interfaces
            1x USB 2.0 (internal 48 MHz PLL)
            5x USARTs
            Up to 8x SPIs (2x I2S, 3x 16 Mbit/s)
            2x I2Cs (SMBus/PMBus)
            1x SDIO interface
        11x timers: 1x 32-bit, 6x 16-bit with up to 4 IC/OC/PWM channels, 2x 16-bit basic timers, 2x watchdog timers (independent and window)
</details>


## Software


## Folder Structure