/*
 * Observer_test.cpp
 *
 *  Created on: Apr 18, 2014
 *      Author: josephx
 */

#include "Observer.hpp"
#include <iostream>
namespace eutest
{} /* namespace eutest */

class Alarm
    : public eutest::Subject
{
public:
    virtual
    ~Alarm() {}
    NOTIFY();
    unsigned int
    getTime() const
    {
        return(rand());
    }
    void
    ON()
    {
        Notify();
    }
};


class Door
    : public eutest::Subject
{
public:
    virtual
    ~Door() {}
    NOTIFY();
    void
    Open()
    {
        Notify();
    }
};


class Sound
    : public eutest::Observer<Alarm>,
      public eutest::Observer<Door>
{
public:
    virtual
    ~Sound() {}
    virtual void
    Update(const Alarm& subj)
    {
        std::cout
        << "Singing: It's "
        << subj.getTime()
        << " o'clock."
        << std::endl;
    }
    virtual void
    Update(const Door& subj)
    {
        std::cout
        << "Singing: Door opened."
        << std::endl;
    }
};


class Light
    : public eutest::Observer<Alarm>
{
public:
    virtual
    ~Light() {}
    virtual void
    Update(const Alarm& alarm)
    {
        std::cout
        << "Light: shining."
        << std::endl;
    }
};

int
main()
{
    std::shared_ptr<Alarm> bigAlarm(new Alarm);
    Door                   Gate;
    std::shared_ptr<Sound> sound(new Sound);
    std::shared_ptr<Light> light(new Light);
    bigAlarm->Attach(sound);
    bigAlarm->Attach(light);
    Gate.Attach(sound);
    bigAlarm->ON();
    Gate.Open();
    return(0);
}
