#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

#include "controller.h"

struct PidInput {
    float goal;
    float output;
};

class PidController: public Controller<float, PidInput> {
    static constexpr int DELTA_TIME = 1;

public:
    explicit PidController(float direction, float max, float min, float kp, float ki, float kd);

    PidController(const PidController &) = default;
    PidController(PidController &&) = default;
    PidController &operator=(const PidController &) = default;
    PidController &operator=(PidController &&) = default;

    float Update(float goal, float output);
    float Update(PidInput input) override;

private:
    float m_direction;
    float m_max;
    float m_min;

    float m_kp;
    float m_ki;
    float m_kd;

    float m_integrator {0.0f};
    float m_prevError {0.0f};
    float m_sumPrevError {0.0f};
    float m_prevPrevError {0.0f};
    float m_prevDifferentiator {0.0f};
};

#endif /* PID_CONTROLLER_H */
