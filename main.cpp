
#include <iostream>
#include <vector>
#include <k_arm_bandit.hpp>
#include <epsilon_k_arm_bandit.hpp>

int main()
{
    std::cout << "In main." << std::endl;
    std::vector<float> rew = std::vector<float>(4, 100);

    KArmBandit test = KArmBandit(rew);
    //EKArmBandit test2 = EKArmBandit(std::vector<float>(4, 100.0), (float)0.01);
    return 0;
}