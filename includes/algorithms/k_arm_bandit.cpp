#include <k_arm_bandit.hpp>

//Constructors
KArmBandit::KArmBandit(std::vector<std::normal_distribution<float>> rewards)
{
    true_rewards = rewards;
    estimated_rewards = std::vector<float>(rewards.size(), 0.0);
    action_frequency = std::vector<int>(rewards.size(), 0);
    actions_taken = std::vector<int>();
    recieved_rewards = std::vector<float>();
    action_range = {0, (int)rewards.size()};
}
KArmBandit::KArmBandit(std::vector<float> rewards)
{
    std::vector<std::normal_distribution<float>> vec;
    for (auto val : rewards)
    {
        vec.emplace_back(std::normal_distribution(val, (float)0.0));
    }
    true_rewards = vec;
    estimated_rewards = std::vector<float>(rewards.size(), 0.0);
    action_frequency = std::vector<int>(rewards.size(), 0);
    actions_taken = std::vector<int>();
    recieved_rewards = std::vector<float>();
    action_range = {0, (int)rewards.size()};
}

//Resetters
void KArmBandit::reset_learning() { std::fill(estimated_rewards.begin(), estimated_rewards.end(), 0.0); }
void KArmBandit::reset_action_frequency() { std::fill(action_frequency.begin(), action_frequency.end(), 0.0); }
void KArmBandit::reset_actions_taken() { std::fill(actions_taken.begin(), actions_taken.end(), 0.0); }

//Const getters
const std::vector<std::normal_distribution<float>> &KArmBandit::get_true_rewards() const { return true_rewards; }
const std::vector<float> &KArmBandit::get_estimated_rewards() const { return estimated_rewards; }
const std::vector<int> &KArmBandit::get_action_frequency() const { return action_frequency; }
const std::vector<int> &KArmBandit::get_actions_taken() const { return actions_taken; }
const std::vector<float> &KArmBandit::get_recieved_rewards() const { return recieved_rewards; }
const std::array<int, 2> &KArmBandit::get_action_range() const { return action_range; }

//Non const getters
std::vector<std::normal_distribution<float>> &KArmBandit::get_true_rewards() { return true_rewards; }
std::vector<float> &KArmBandit::get_estimated_rewards() { return estimated_rewards; }
std::vector<int> &KArmBandit::get_action_frequency() { return action_frequency; }
std::vector<int> &KArmBandit::get_actions_taken() { return actions_taken; }
std::vector<float> &KArmBandit::get_recieved_rewards() { return recieved_rewards; }
std::array<int, 2> &KArmBandit::get_action_range() { return action_range; }

//Setters
void KArmBandit::set_true_rewards(std::vector<std::normal_distribution<float>> rewards)
{
    if (rewards.size() != true_rewards.size())
    {
        throw std::out_of_range("Tried to set true rewards using incorrect number of rewards");
    }
    std::copy(rewards.begin(), rewards.end(), true_rewards.begin());
    return;
}
void KArmBandit::set_estimated_rewards(std::vector<float> rewards)
{
    if (rewards.size() > rewards.size())
    {
        throw std::out_of_range("Tried to set estimate rewards using incorrect number of rewards");
    }
    std::copy(rewards.begin(), rewards.end(), estimated_rewards.begin());
    return;
}
void KArmBandit::set_action_frequency(std::vector<int> frequency)
{
    if (frequency.size() > true_rewards.size())
    {
        throw std::out_of_range("Tried to set action frequency using incorrect number of actions");
    }
    std::copy(frequency.begin(), frequency.end(), estimated_rewards.begin());
    return;
}
void KArmBandit::set_actions_taken(std::vector<int> actions)
{
    actions_taken = actions;
}
void KArmBandit::set_recieved_rewards(std::vector<float> rewards)
{
    recieved_rewards = rewards;
}
void KArmBandit::set_action_range(std::array<int, 2> ar)
{
    action_range = ar;
}