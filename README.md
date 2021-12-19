# Arduino

To have this part of the project working, you'll need to buy : 

- **One** [Arduino Uno Rev 3](https://store.arduino.cc/products/arduino-uno-rev3/)
- **Two** [Adafruit Triple-Axis Accelerometer](https://www.adafruit.com/product/2019)

# Plug sensors 

First of all, you'll need to weld cables in order to have enough ports. 

This way, you'll have three "special cables" that have on male linked to two female plugs : 

![image](https://user-images.githubusercontent.com/79083274/146681447-0d59ed58-8229-47ec-a90b-bd23d4a906f7.png)

Now you can start to plug the arduino Uno Rev 3 with the sensors.

Pins of a sensor : 

![image](https://user-images.githubusercontent.com/79083274/146681664-3a33ad8b-e0b4-4019-885a-14ad780f33cc.png)

Pins of an arduino :

![image](https://user-images.githubusercontent.com/79083274/146681773-a678b52e-e16b-43af-9704-4d2eb906b97a.png)

Instructions : 

- Plug a weld cable in the arduino's **5V** pin (male) and in the sensors' **VIN** pins (female). 
- Plug a weld cable in the arduino's **SCL**(D19) pin (male) and in the sensors' **SCL** pins (female).
- Plug a weld cable in the arduino's **SDA**(D18) pin (male) and in the sensors' **SDA** pins (female).
- Plug a normal cable in the arduino's **GND** pin (male) and in **one** sensor's **GND** pin (female).
- Plug a normal cable in the arduino's **GND** pin (male) and in **one** sensor's **A** pin (female).

# Inject the program 
- Type this command in a shell : <tt>sudo chmod a+rw /dev/ttyACM0</tt>
- Download the [arduino IDE](https://www.arduino.cc/en/software).
- Plug the arduino Uno Rev 3 to your computer. 
- Open the **.ino** file with the ide and inject the code. 
