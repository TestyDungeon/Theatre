#pragma once

#include "play.h"

class ComedyPlay : public Play{
protected:
public:
    ComedyPlay(std::string title_, std::chrono::sys_seconds time_, double cost_);
};