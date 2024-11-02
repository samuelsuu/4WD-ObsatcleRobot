<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>Obstacle Avoidance Robot Car</h1>

<p>This project is an <strong>Obstacle Avoidance Robot Car</strong> that autonomously navigates around obstacles using an ultrasonic sensor and a servo motor. It is programmed to detect objects within a certain distance and change direction to avoid collisions.</p>

<h2>Features</h2>
<ul>
    <li>Obstacle detection with an ultrasonic sensor</li>
    <li>Automatic turning based on the best path</li>
    <li>Forward, backward, left, and right directional movements</li>
    <li>Obstacle scanning through a servo motor to detect optimal path</li>
</ul>

<h2>Components Required</h2>
<ul>
    <li>Arduino Board</li>
    <li>Adafruit Motor Shield or any compatible motor driver</li>
    <li>4 DC Motors</li>
    <li>1 Ultrasonic Sensor (HC-SR04)</li>
    <li>1 Servo Motor</li>
    <li>3x 3.7V Lithium-Ion Batteries (in series for 11.1V total)</li>
    <li>Chassis for mounting components</li>
</ul>

<h2>Power Supply</h2>
<p>This robot car is powered by three 3.7V batteries connected in <strong>series</strong>, which provides a combined voltage of <strong>11.1V</strong>. Using batteries in series increases the voltage, which is suitable for powering both the motors and the Arduino.</p>

<h3>Battery Connection Instructions</h3>
<ol>
    <li>Ensure each battery is rated at 3.7V.</li>
    <li>Connect the batteries in series by linking the positive terminal of one battery to the negative terminal of the next.</li>
    <li>The final voltage output from three 3.7V batteries in series should be 11.1V.</li>
    <li>Attach the positive and negative terminals from the series connection to the input terminals of the motor driver and Arduino (or power it separately if needed).</li>
</ol>

<h2>Code Explanation</h2>
<p>The code for this robot is written in Arduino C and includes various functions for movement, obstacle detection, and decision-making:</p>
<ul>
    <li><strong>Movement Functions:</strong> Controls the robot’s direction, allowing it to move forward, backward, and turn left or right.</li>
    <li><strong>Ultrasonic Sensor:</strong> Measures the distance to nearby obstacles.</li>
    <li><strong>Servo Motor:</strong> Rotates to scan left and right for better path detection when an obstacle is detected in front.</li>
</ul>

<h2>How to Run the Code</h2>
<ol>
    <li>Copy the provided Arduino code into the Arduino IDE.</li>
    <li>Connect the Arduino board to your computer.</li>
    <li>Select the appropriate board and port from the IDE settings.</li>
    <li>Upload the code to the Arduino board.</li>
</ol>

<h2>How It Works</h2>
<p>The robot moves forward until it detects an obstacle within a 12 cm range. Once an obstacle is detected, it performs the following actions:</p>
<ol>
    <li>Stops and reverses briefly.</li>
    <li>Uses the servo motor to check left and right distances.</li>
    <li>Chooses the direction with the most clearance and turns accordingly.</li>
    <li>Resumes moving forward if no obstacles are detected.</li>
</ol>

<h2>Additional Notes</h2>
<ul>
    <li>Make sure the batteries are properly secured and connected in series.</li>
    <li>For longer operation, consider using batteries with higher capacity (measured in mAh).</li>
    <li>Verify motor connections before running the robot to ensure proper directional control.</li>
</ul>

<h2>License</h2>
<p>This project was created by the <strong>SriTu Tech Team</strong>. Feel free to use, modify, and distribute this code for educational and personal use.</p>

</body>
</html>
