#include "opera.h"
#include "enums.h"
#include <vector>

Opera::Opera(std::string title_, std::chrono::sys_seconds time_, double cost_):
    Session(title_, time_, cost_)
{}

std::vector<Extras> Opera::get_supported_extras() const{
    return {Extras::Binocular};
}
