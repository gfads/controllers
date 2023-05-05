#include "pid_controller.h"

PidController::PidController(float direction, float max, float min, float kp, float ki, float kd):
        m_direction(direction),
        m_max(max),
        m_min(min),
        m_kp(kp),
        m_ki(ki),
        m_kd(kd) {
}

float PidController::Update(float goal, float output) {
    return Update(PidInput {goal, output});
}

float PidController::Update(PidInput input) {
    float err = m_direction * (input.goal - input.output);

    float proportional = m_kp * err;

    m_integrator += DELTA_TIME * err;
    float integrator = m_integrator * m_ki;

    float differentiator = m_kd * (err - m_prevError) / DELTA_TIME;

    float out = proportional + integrator + differentiator;
    if (out > m_max) {
        out = m_max;
    } else if (out < m_min) {
        out = m_min;
    }

    m_prevError = err;
    m_sumPrevError += err;

    return out;
}
