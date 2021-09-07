from AutoTest import AutoTest

'''
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母都恰好只用一次。
'''

class Solution:
    '''
    主要使用哈希的方法来加快查找。将字符串的递增排列作为key即可。
    36ms, 98.30%; 17.6MB, 84.48%;
    '''
    def groupAnagrams(self, strs):
        appear = {}
        rtn = []
        for s in strs:
            standard = ''.join(sorted(s))
            if standard not in appear:
                appear[standard] = [s]
            else: 
                appear[standard].append(s)
        for key in appear:
            rtn.append(appear[key])
        
        return rtn
