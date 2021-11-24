# -*- coding: utf-8 -*-
"""
Created on Thu Nov  4 14:14:56 2021

@author: 2jake
"""

import gym
from gym import spaces
import numpy as np

from stable_baselines3.common.env_checker import check_env

class RLMine(gym.Env):
    """Custom environment that follows gym interface"""
    
    def __init__(self, mine):
        
        self.action_space = spaces.Box(low = 0, high = 100, shape = (3,), dtype = np.int32)
        self.observation_space = spaces.Box(low = 0, high = 1, dtype = np.float32, shape=(100,100,100))
        self.mine = mine
        self.sched = np.full((100,100,100), -1)
        self.period = 0
        
    def reset(self):
        self.sched = np.full((100,100,100), -1)
        self.period = 0
        return self.observation_space
            
    def step(self, action):
        print(action)
        
        return 0, 1, False, {}
    
    def close(self):
        pass

mine = np.random.rand(100,100,100)
env = RLMine(mine)

check_env(env)
