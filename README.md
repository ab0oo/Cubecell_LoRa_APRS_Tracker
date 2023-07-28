# Cubecell GPS LoRa APRS Tracker

This Project is a fork of [@peterus](https://github.com/peterus) [LoRa APRS ESP32 Tracker](https://github.com/lora-aprs/LoRa_APRS_Tracker) ported to the Heltec Cubecell GPS ASR650x CPU

This project has been specially tweaked for use in Black Rock City, the home of Burning Man.  Specifically, it's
designed to be used on bikes, art cars, Mutant Vehicles, or even carried in a backpack to allow for tracking of 
a specific item, vehicle, or even person.  It should even work in aircraft and on jumpers parachuting as part of
Burning Skies.

This code pairs with the [APRS iGate](https://github.com/ab0oo/LoRa_APRS_iGate) project to provide a complete
tracking infrastructure to be deployed in BRC.

The version of the code has an additional menu screen to show you where you are currently located in the city, using
the radial address system.  All locations are given with respect to the Man.  For locations in the city, they are
given as "4:30 & A" or "7:14 & D".  In open playa, both inner and outer, locations are given as a clock-radial and
distance to the man, i.e. "1:15 and 5800'".  This came about after I spent hours pedalling around in a dust storm
one year looking for a specific art piece in deep playa.  Hopefully it will help others.

The code has many parts of the [CubeCell-GPS Helium Mapper](https://github.com/hkicko/CubeCell-GPS-Helium-Mapper)

![Tracker](pics/cubecell_tracker.png)

## Supported boards

At this moment, only the Heltec CubeCell GPS is supported:

* Heltec CubeCell GPS-6502 ([HTCC-AB02S](https://heltec.org/project/htcc-ab02s/)) 

This board cost around 25-30 Euros, a little bit cheaper and smaller than the widely used TTGO T-Beam.

Keep in mind: you need a 915MHz version!

## Project State

First Goal was the Port to the ASR650x platform, keeping the great Tracking and SmartBeacon Functions from Peters Project.

This Firmware is still in a very early and not well-tested State.
Expect Bugs and Functions not working.

Please feel free to open an issue if you found Bugs.


## Compiling and configuration

### How to compile

The best success is to use PlatformIO (and it is the only platform where I can support you). 

* Go to [PlatformIO](https://platformio.org/) download and install the IDE. 
* If installed open the IDE, go to the left side and klick on 'extensions' then search for 'PatformIO' and install.
* Windows users may have to install [GIT](https://git-scm.com/download/win)
* When installed click 'the ant head' on the left and choose import the project on the right.
* Just open the folder and you can compile and upload the Firmware.

### Configuration

* You can find all necessary settings to change for your configuration in **src/config.h**.

### Button Actions

Top Button can be used, the lower Button is hardwired to Device Reset.

* Button > 1s: Send Position Beacon
* Button < 1s: Open Menu / Next Menu Item
* Button > 1s in Menu: Change Setting
