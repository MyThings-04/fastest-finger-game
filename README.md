## 🎥 Project Demo

A complete demonstration of the LED Reaction Speed Game, including the startup countdown, gameplay, reaction time measurement, performance display, and restart functionality.

📹 **Watch the Demo:** https://drive.google.com/file/d/1uMxTxe5UOmF31UzrjlCbp8mo1x9vuUCR/view?usp=drivesdk

# fastest-finger-game
Reaction Speed Game 🎮  Arduino-based reaction speed game using LEDs, buttons, buzzer, and I2C LCD. It generates random LED patterns, detects button responses, counts successful hits, measures reaction time, and displays performance results. This project demonstrates embedded programming, digital I/O, LCD interfacing, and Arduino game development.
# LED Reaction Speed Game 🎮

The LED Reaction Speed Game is an Arduino UNO-based project that tests a player's reaction speed and hand-eye coordination. The game uses four LEDs, four push buttons, a buzzer, and a 16×2 I2C LCD display. At the start, a countdown is shown on the LCD before the game begins. A random LED lights up, and the player must press the corresponding button as quickly as possible. After each correct press, a short buzzer sound is played, the score increases, and another randomly selected LED lights up. The same LED is never selected twice in a row, making the game more challenging.

The objective is to complete 35 correct responses in the shortest possible time. The Arduino measures the total reaction time using the `millis()` function and displays the final result on the LCD. Based on the player's performance, the game shows a rating such as **Excellent**, **Good**, **Average**, or **Too Slow**. A unique game-over buzzer sound indicates the end of the challenge. The player can then press the restart button to begin a new round with a fresh countdown.

This project demonstrates several embedded systems concepts, including digital input/output, random number generation, button interfacing, I2C LCD communication, timing with `millis()`, and game logic implementation. It is a beginner-friendly Arduino project that combines electronics and programming to create an engaging reaction speed game while helping users learn practical embedded system development.
