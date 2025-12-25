#include "is_booted.h"
bool computer_running = true;
bool is_booted() {
    if (computer_running) {
        return true;
    }
}