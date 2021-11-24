#include <epsilon_k_arm_bandit.hpp>

//Constructors
EKArmBandit::EKArmBandit(std::vector<float> rewards, float eps) : KArmBandit{rewards}, epsilon(eps) {}
EKArmBandit::EKArmBandit(std::vector<std::normal_distribution<float>> rewards, float eps) : KArmBandit{rewards}, epsilon(eps) {}
