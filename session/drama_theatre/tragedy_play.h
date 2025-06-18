#pragma once

#include "play.h"

class TragedyPlay : public Play{
protected:
public:
    TragedyPlay(std::string title_, std::chrono::sys_seconds time_, double cost_);
};