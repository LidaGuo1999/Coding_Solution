from AutoTest import AutoTest

'''
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
'''

class Solution:
    def minWindow(self, s, t):
        target = {}
        for tl in t:
            if tl not in target: target[tl] = 0
            target[tl] += 1
        
        rtn = 2**31-1
        i, j, flag = 0, 0, 0
        while 
        
    def __check(self, target):
        total = 0
        for key in target:
            total += target[key]
        return total == 0