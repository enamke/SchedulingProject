cmake_minimum_required(VERSION 3.7...3.21)

# set the project name
project(TermProject)

set(CMAKE_CXX_STANDARD 20)

# add the executable
add_executable(main main.cpp)
#set_target_properties(main PROPERTIES LINKER_LANGUAGE C)

#add subdirectories
add_subdirectory(includes)

target_link_libraries(main PUBLIC k_arm_bandit e_k_arm_bandit)

#add libraries
target_include_directories(main PUBLIC
                        "${PROJECT_SOURCE_DIR}/includes/algorithms"
                        )



