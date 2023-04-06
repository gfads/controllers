#ifndef CONTROLLER_H
#define CONTROLLER_H

template <typename OutputType, typename InputType>
class Controller {
public:
    Controller() = default;
    Controller(const Controller &) = default;
    Controller(Controller &&) noexcept = default;
    Controller &operator=(const Controller &) = default;
    Controller &operator=(Controller &&) noexcept = default;

    virtual OutputType Update(InputType input) = 0;

    virtual ~Controller() = default;
};

#endif /* CONTROLLER_H */
