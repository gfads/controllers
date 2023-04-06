#include <iostream>

#include "onoff_controller.h"

int main() {
    OnOffController controller(32.0f, 50.0f);

    float goal = 10.0f;      // desired value
    float output = 11.0f;    // plant output

    // 1. Update with OnOffInput
    OnOffInput onOffInput {};

    onOffInput.m_goal = goal;
    onOffInput.m_output = output;

    float updatedOutput = controller.Update(onOffInput);
    std::cout << "1: " << updatedOutput << '\n';

    // 2. Direct use of two floats, this function overload redirect the call for the Update function
    // above
    updatedOutput = controller.Update(goal, output);
    std::cout << "2: " << updatedOutput << '\n';

    return EXIT_SUCCESS;
}
