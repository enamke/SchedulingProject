#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <array>
#include <k_arm_bandit.hpp>
#include <random>

class EKArmBandit : public KArmBandit
{
    float epsilon;

public:
    EKArmBandit(std::vector<float> rewards, float eps);
    EKArmBandit(std::vector<std::normal_distribution<float>> rewards, float eps);
};