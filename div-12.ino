extern "C" {
    void start_clock(void);
}

void setup() {
    start_clock(); // Hands off execution directly to assembly
}

void loop() {
    // Unused
}