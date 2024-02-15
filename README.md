# Smart-waste-segregator
# OBJECTIVE :

Develop an automated Wet and Dry Waste Segregation Machine to enhance waste management efficiency by accurately sorting dry and wet materials at the source, promoting recycling and composting.

# Components used :

i.	Audrino Mega 2650 :

The Arduino Mega 2560 is a microcontroller board based on the ATmega2560 (datasheet). It has 54 digital input/output pins (of which 14 can be used as PWM outputs), 16 analog inputs, 4 UARTs (hardware serial ports), a 16 MHz crystal oscillator, a USB connection, a power jack, an ICSP header, and a reset button. It contains everything needed to support the microcontroller; simply connect it to a computer with a USB cable or power it with a AC-to-DC adapter or battery to get started.

ii.	Soil Moisture Sensor :

The soil moisture sensor is one kind of sensor used to gauge the volumetric content of water within the soil. As the straight gravimetric dimension of soil moisture needs eliminating, drying, as well as sample weighting. These sensors measure the volumetric water content not directly with the help of some other rules of soil like dielectric constant, electrical resistance, otherwise interaction with neutrons, and replacement of the moisture content.

iii.	Touch Sensor :

A touch sensor is a type of device that captures and records physical touch or embrace on a device and/or object. It enables a device or object to detect touch or near proximity, typically by a human user or operator. Touch sensing input devices offer numerous possibilities for novel interaction techniques and it reliably replaces mechanical buttons and switches to eliminate mechanical wear and tear.

iv.	Servo Motor (x2) :

A servomotor is a rotary or linear actuator that allows for precise control of angular or linear position, velocity, and acceleration in a mechanical system. It constitutes part of a servomechanism, and consists of a suitable motor coupled to a sensor for position feedback.

v.	Ultrasonic Sensor :

An ultrasonic sensor is an electronic device that measures the distance of a target object by emitting ultrasonic sound waves, and converts the reflected sound into an electrical signal. Ultrasonic sensors have two main components: the transmitter (which emits the sound using piezoelectric crystals) and the receiver (which encounters the sound after it has travelled to and from the target).


# Methodology :


The Soil Moisture Sensor helps us to classify the dry and wet waste , it return values from 0 to 1023 which is proportional to the value of the output voltage , by using wet and dry test cases we have set a threshold value for the moisture sensor to classify them .


The threshold value has been set at 900 after analysing some test cases.


Output given by Soil moisture sensor	.  Status of the Waste

  => 900                  .                     Dry Waste

  < 900	                  .                    Wet Waste



The touch sensor helps us to know whether the waste has been placed or not , it is required because in default the soil moisture sensor returns analog value of 1023 , which would classify it as dry waste .

 The 2 servo motors are placed in the opposite sides of the garbage placing surface , initially at 90 degrees , they either rotate to 0 or 180 according to the type of waste placed.

Table:2 – Rotation of the motor with respect to the type of waste.


State of the Waste	. Servo Motor – 1 (angle)	. Servo Motor -2 (angle)

No waste placed	    .         90	            .          90

Wet Waste	          .         0	               .       180

Dry Waste	          .       180	                .       0

 
A box with partition between them is used for collecting the waste after classification.


The Ultrasonic sensor helps in the detection of the garbage level , when the garbage reaches a certain height , the ultrasonic sensor alerts the user using led to clear the garbage of whichever side the garbage has been filled . The sensor has been placed facing the opposite wall which has a distance of 30 cm , since the partition is at 15 cm , we are able to say that garbage is full on specific side when the garbage is full, and is shown by blinking led whenever a side is full.

Distance shown by ultrasonic sensor	      .         Status of the bin

30 cm	                        .                 Neutral (No bins filled)

15cm – 30 cm	                 .                   Wet waste is filled

0 cm – 15 cm	                  .                  Dry waste is filled



