#include <stdio.h>
#include <string.h>
#include <unistd.h> 

int led_state = 0;
int blinking = 0;
char log[100][100];
int log_index = 0;

// Log helper
void add_log(const char* message) {
if (log_index < 100) {
snprintf(log[log_index++], 100, "%s", message);
}
}

// Toggle LED and log state
void toggle_led() {
led_state = !led_state;
printf("LED is now %s\n", led_state ? "ON" : "OFF");


if (led_state)
    add_log("LED turned ON");
else
    add_log("LED turned OFF");
}

// Simulate button interrupt (to pause/resume blinking)
void button_interrupt_handler() {
blinking = !blinking;
printf("Button pressed → Blinking %s\n", blinking ? "RESUMED" : "STOPPED");


if (blinking)
    add_log("Button pressed: blinking resumed");
else
    add_log("Button pressed: blinking stopped");
}

// Simulated ambient light sensor
void read_light_sensor() {
int lux;
printf("Enter ambient light (0–1000 Lux): ");
scanf("%d", &lux);

if (lux < 300) {
    blinking = 1;
    printf("→ It's dark. Auto-starting blinking.\n");
    add_log("Ambient dark detected: blinking started");
} else {
    blinking = 0;
    printf("→ It's bright. Blinking remains off.\n");
    add_log("Ambient light detected: blinking stopped");
}
}

// Display log
void print_log() {
printf("\nEvent Log:\n");
printf("----------\n");
for (int i = 0; i < log_index; i++) {
printf("%d. %s\n", i + 1, log[i]);
}
}

// Boot sequence (LED blink pattern)
void startup_animation() {
printf("System booting...\n");
toggle_led(); sleep(1);
toggle_led(); sleep(1);
toggle_led(); sleep(1);
toggle_led(); sleep(1);
printf("Boot sequence complete. Ready to operate.\n\n");
add_log("Startup animation completed");
}

int main() {
char input;

printf("Simulated LED Blinker with Sensor, ISR & Log\n");
printf("============================================\n");

startup_animation();
read_light_sensor();

printf("Commands:\n");
printf(" b → simulate button press (pause/resume blinking)\n");
printf(" n → next blink step (if blinking is on)\n");
printf(" l → print event log\n");
printf(" q → quit program\n");

while (1) {
    printf("\nEnter command (b/n/l/q): ");
    scanf(" %c", &input);

    if (input == 'b') {
        button_interrupt_handler();
    } else if (input == 'n') {
        if (blinking) {
            toggle_led();
        } else {
            printf("Blinking is paused. LED stays %s\n", led_state ? "ON" : "OFF");
        }
    } else if (input == 'l') {
        print_log();
    } else if (input == 'q') {
        printf("Exiting program...\n");
        add_log("System shut down");
        break;
    } else {
        printf("Invalid input. Try again.\n");
    }
}

return 0;
}
