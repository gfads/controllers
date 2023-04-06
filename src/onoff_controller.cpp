#include "onoff_controller.h"

OnOffController::OnOffController(const OnOffInput &input):
        OnOffController(input.m_goal, input.m_output) {
}

OnOffController::OnOffController(float min, float max):
        m_min {min},
        m_max {max} {
}

float OnOffController::Update(float goal, float output) {
    return Update({goal, output});
}

float OnOffController::Update(OnOffInput input) {
    float direction = -1.0f;

    float goal = input.m_goal;
    float plantOutput = input.m_output;

    float err = direction * (goal - plantOutput);

    float update = (err >= 0) ? m_max : m_min;
    return update;
}
