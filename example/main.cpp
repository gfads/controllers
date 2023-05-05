#include <iostream>

#include "onoff_controller.h"
#include "pid_controller.h"

int main() {
    OnOffController onOff(32.0f, 50.0f);

    float goal = 10.0f;      // desired value
    float output = 11.0f;    // plant output

    // 1. Update with OnOffInput
    OnOffInput onOffInput {};
    onOffInput.goal = goal;
    onOffInput.output = output;

    float updatedOutput = onOff.Update(onOffInput);
    std::cout << "[OnOff] 1: " << updatedOutput << '\n';

    // 2. Direct use of two floats, this function overload redirect the call for the Update function
    // above
    updatedOutput = onOff.Update(goal, output);
    std::cout << "[OnOff] 2: " << updatedOutput << '\n';

    /***********************************************************/
    PidController pid(-1.0f, 32.0f, 50.0f, 5.0f, 3.0f, 2.0f);

    // 1. Update with PidInput
    PidInput pidInput {};
    pidInput.goal = goal;
    pidInput.output = output;

    updatedOutput = pid.Update(pidInput);
    std::cout << "[PID] 1: " << updatedOutput << '\n';

    // 2. Direct use of two floats, this function overload redirect the call for the Update function
    // above
    updatedOutput = pid.Update(goal, output);
    std::cout << "[PID] 2: " << updatedOutput << '\n';

    return EXIT_SUCCESS;
}
