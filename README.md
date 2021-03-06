# Universal-Manipulator
# Abstract

A mechanical arm, programmable with similar functions to a human arm having. The gripper attached can be used to pick objects from one  given coordinates and drop to another given coordinates .

# Team Members
* Amit Kumar
* Punit Gora
* Shivam Chopra
* Shubham Kumar
* Vipin Kumar

# Mentors
* Bhaskar Kaushik
* Shivam Srivastava

# Applicatioins

Robotic arms are typically used for industrial applications. The application is the type of work robot is designed to do.
Different applications will have different requirements. Industrial robots are designed for specific applications and based on their function will have their own movement, linkage dimension, control law, software and accessory packages. It can be used for welding, painting, palletizing.

# Hardware

1. 1 Base
  
![base](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/base.png)  
  
2. 1 Base gear
  
![base gear](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/gear.png)  
 
3. 2 3D printed arms

![arms](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/arm.png)

4. 6 Controling gears

![controling gears](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/3D-printed-Gear-set-for-prototyping-with-plastic-.jpg)


5. 5 bearings

![bearings](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/24007914_962347590582031_479002411_o.jpg)

6. 1 worm gear

![worm gear](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/download.jpg)

7. 1 gripper

![gripper](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/gripper.png)

8. 1 Arduino Uno

![arduino](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/sku_370842_1.jpg)

9. 3 Rotary Encoders

![rotary encoder](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/0%20UGE%20ROTARY%20ENCODER%20400PPR-500x375.jpg)

10. 3 High torque dc motors(12 volt)

![dc motor](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/150-rpm-high-torque-12-volt-dc-gear-motor-for-arduino-raspberry-pi-robotics-high-rpm-high-torque-dc-motors-rm0633-by-robomart-700-500x500.jpg)

11. 2 Motor driver(LN298N)

![motor driver](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/1-750x750.jpg)

12. 1 Servo motor for gripper</li>

![servo motor](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/micro-servo-sg90.jpg)



# Software

## Arduino
The movement of dc motors and the servo motor is controlled by the arduino code with the help of the feedback from the rotary encoders.


# Structure
The bot is made by joining 2 arms with base gear along with a gripper. DC motors are attached with arms and base gear to provide  motion. The whole structure is mounted on a wooden base. The 3D printed base is fixed with wodden base on which base gear is mounted using bearing. DC motor is attached to base gear using the controling gears along with the encoder. One arm is mounted on the base gear using shaft and bearings along with DC motor and rotory encoder.Worm gear is attached to the controlling gear to lock the arm at certain position and prvent the 2nd arm from falling. 2nd arm is mounted on the 1st arm along with DC motor and encoder.At the end of 2nd arm gripper is fixed. Servo motor is attached to the gripper to hold an object.

![gripper](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/DSC_0085.NEF.jpg)

# Coordinate Calculation

Here is a schematic diagram of our robot:

![robotarm](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/robotarm.png)

This diagram tells us a couple of things:
  * The segments have the length len1 and len2, respectively.
  * The root joint describes an angle A1 measured from the x axis.
  * The second joint describes an angle A2 measured from the first segment (counterclockwise in both cases).

using law of cosines:

![lawofcosines](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/lawofcosines.png)

now we have to calculate angle A1 and A2
* From the robotic arm diagram above (the one with D1, D2, dist, etc), we can directly derive the first formula: A1 = D1 + D2
     
* D1 is fairly easy to calculate. In the following diagram, x, y, and dist define a right-angled triangle. Here, D1 can be calculated in two ways: The arcsine of y/dist or the arctangent of y/x. As we have x and y readily available, let’s choose the arctangent formula.

![arctan](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/arctan.png)

* D2 requires the law of cosines. Basically, we just map our “robot triangle” to the “law of cosines” triangle by using dist as a, len1 as b, and len2 as c. The resulting angle C is our D2.


![lengtha](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/calcd2.png)

* Now only A2 is left. Luckily, we can reuse the law of cosines for this. We only need to map our triangle to the one from the law of cosines with different parameter mappings than for D2: len1 as a, len2 as b, and dist as c.

![lengthd](https://github.com/shubhamsharele/Universal-Manipulator/blob/master/Photos/calca2.png)



# Working
Basically initial and final coordinates are fixed.The sequence of steps followed are also fixed but can be varied using code. Initally one arm will go down and the gripper will grab the object using servo motor. Then the 2 arms will move up and base gear will rotate to another coordinates as given in the code. Then it will drop the object. Finally the the arms and base gear will come to their initial location. The initial and final coordinates can be varied using the code.

# Limitations and Future Improvements

1. It can only pick object from fixed coordinate and drop it to another fixed coordinate. The coordinates can be only be varied from the code.We can use  image processing to detect the positioin of the object and the bot shoud be able to pick up the object from that position.
2.The size of object is also fixed. It should also be able to pick the object of various sizes.

    
# Video
https://photos.app.goo.gl/8jrEAZFpoxkNe4iW9
