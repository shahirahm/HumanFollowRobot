# HumanFollowRobot
The human-following robot is designed to autonomously follow a human target. This application has numerous benefits in real-world scenarios, such as assisting the elderly, acting as a personal assistant, or carrying loads in industrial settings. 

The human-following robot is designed to autonomously follow a human target. This application has numerous benefits in real-world scenarios, such as assisting the elderly, acting as a personal assistant, or carrying loads in industrial settings. Our robot uses IR sensors to detect the proximity of the human and an ultrasonic sensor to measure the distance from the target, ensuring accurate and reliable tracking. The project aims to create a cost-effective and efficient solution for human assistance through robotics.

Several existing works have explored robotic assistants using various sensor technologies. Studies have shown that combining IR and ultrasonic sensors can enhance detection accuracy and reliability in dynamic environments [1]. Prior research also highlights the use of servo motors for adaptive sensor positioning to improve tracking performance [2]. Our approach builds on these foundations by integrating these components into a cohesive system that balances cost and functionality.

Our project differentiates itself from existing solutions by integrating a dual-sensor approach (IR and ultrasonic) with a servo motor for dynamic sensor adjustment. This configuration improves the robot's ability to follow a human target more accurately in varying environments. Additionally, the use of an Arduino Uno makes the system both affordable and accessible for further development and customization.


The project features include:

Human detection and following using IR and ultrasonic sensors.
Dynamic sensor positioning with a servo motor.
Control of robot movement using a motor driver and Arduino Uno.
III. COMPONENT LIST

IR Sensor

Used for proximity detection.
Mounted on the robot to sense the presence of the human target.

Ultrasonic Sensor

Measures distance to the human target.
Ensures accurate tracking by providing distance data.

Servo Motor

Adjusts the position of the sensors for better tracking.
Enhances the robot's ability to follow the target.

Arduino Uno

Central controller of the robot.
Processes sensor data and controls the motors.

Motor Driver

Drives the motors based on commands from the Arduino.
Controls the movement of the robot.


    \item Arduino UNO R3 Board
    \item IR sensor
    \item Ultrasonic Sensor
    \item L293D Motor Driver
    \item BO Motor
    \item Servo Motor
    \item Switch
    \item Jumper Wires
    \item 18650 Battery

