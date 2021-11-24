add_library(k_arm_bandit k_arm_bandit.hpp k_arm_bandit.cpp)
target_include_directories(k_arm_bandit PUBLIC "${PROJECT_SOURCE_DIR}/includes/algorithms")

add_library(e_k_arm_bandit epsilon_k_arm_bandit.hpp epsilon_k_arm_bandit.cpp)
target_include_directories(e_k_arm_bandit PUBLIC "${PROJECT_SOURCE_DIR}/includes/algorithms")