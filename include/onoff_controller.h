#ifndef ONOFF_CONTROLLER_H
#define ONOFF_CONTROLLER_H

#include "controller.h"

struct OnOffInput {
    float goal;
    float output;
};

class OnOffController: public Controller<float, OnOffInput> {
public:
    explicit OnOffController(const OnOffInput &input);
    explicit OnOffController(float min, float max);

    OnOffController(const OnOffController &) = default;
    OnOffController(OnOffController &&) noexcept = default;
    OnOffController &operator=(const OnOffController &) = default;
    OnOffController &operator=(OnOffController &&) noexcept = default;

    ~OnOffController() override = default;

    float Update(float goal, float output);
    float Update(OnOffInput input) override;

private:
    float m_min;
    float m_max;
};

#endif /* ONOFF_CONTROLLER_H */
