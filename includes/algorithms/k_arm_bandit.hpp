#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <array>
#include <random>

class KArmBandit
{
    std::vector<std::normal_distribution<float>> true_rewards;
    std::vector<float> estimated_rewards;
    std::vector<int> action_frequency;
    std::vector<int> actions_taken;
    std::vector<float> recieved_rewards;
    std::array<int, 2> action_range;

public:
    //Constructors
    KArmBandit() = default;
    KArmBandit(std::vector<std::normal_distribution<float>> rewards);
    KArmBandit(std::vector<float> rewards);

    //Reset
    void reset_learning();
    void reset_action_frequency();
    void reset_actions_taken();

    //Const getters
    const std::vector<std::normal_distribution<float>> &get_true_rewards() const;
    const std::vector<float> &get_estimated_rewards() const;
    const std::vector<int> &get_action_frequency() const;
    const std::vector<int> &get_actions_taken() const;
    const std::vector<float> &get_recieved_rewards() const;
    const std::array<int, 2> &get_action_range() const;

    //Mutable getters
    std::vector<std::normal_distribution<float>> &get_true_rewards();
    std::vector<float> &get_estimated_rewards();
    std::vector<int> &get_action_frequency();
    std::vector<int> &get_actions_taken();
    std::vector<float> &get_recieved_rewards();
    std::array<int, 2> &get_action_range();

    //Setters
    void set_true_rewards(std::vector<std::normal_distribution<float>> rewards);
    void set_estimated_rewards(std::vector<float> rewards);
    void set_action_frequency(std::vector<int> frequency);
    void set_actions_taken(std::vector<int> actions);
    void set_recieved_rewards(std::vector<float> rewards);
    void set_action_range(std::array<int, 2> ar);

    //Runner
    void run(int n);
};