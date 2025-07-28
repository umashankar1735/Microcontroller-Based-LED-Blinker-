# 💡 Microcontroller-Based LED Blinker

Created a simulation of an embedded LED blinking system using ISR-based button handling and GPIO control.  
Includes an LED sequence for startup and integrates ambient light (lux) input for automatic blinking control.  
Real-time event logging is incorporated to simulate the behavior of embedded systems — all without hardware.

---

## ✅ Features

- Simulated LED blinking (ON/OFF)  
- ISR-like button toggle to pause/resume blinking  
- Ambient light sensor simulation (lux-based trigger)  
- Boot-time LED sequence animation  
- Real-time event logging (console-based)  
- Pure C implementation — no hardware required  

---

## 🛠 Tools Used

- Language: C  
- Platform: OnlineGDB or any local C compiler (GCC, Code::Blocks, etc.)  
- Concepts: GPIO, ISR, state toggling, sensors, debug logs  

---

## 🚀 How to Run

1. Go to: https://www.onlinegdb.com/online_c_compiler  
2. Copy & paste the contents of led_blinker.c into the editor  
3. Click “Run”  

💻 Use the following commands during execution:

- b → simulate button press (pause/resume blinking)  
- n → trigger next blink  
- l → show event log  
- q → quit program  

---

## 📷 Sample Output

- Enter ambient light (0–1000 Lux): 150
- → It's dark. Auto-starting blinking.
- LED is now ON
- LED is now OFF
- Button pressed → Blinking STOPPED
...

📁 File: main_code.c

---

## 💡 Project Insight

This project demonstrates embedded principles like:

- GPIO-style conditional control  
- Interrupt simulation (via user input)  
- Input-based behavior (lux detection)  
- Boot sequence animation  
- Real-time logging/debug messages  

All built in pure C for portability and ease of demonstration, with no hardware required.

---

## 👤 Author

- 👨‍💻 Kesireddi Sai Uma Shankar  
- 🔗 LinkedIn: [saiumashankar](https://www.linkedin.com/in/saiumashankar)  
- 💻 GitHub: [umashankar1735](https://github.com/umashankar1735)  
- 📧 Email: ksaiumashankar@gmail.com  
