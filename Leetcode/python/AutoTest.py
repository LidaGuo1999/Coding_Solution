class AutoTest:
    def __init__(self, solution, funcName, paramNum):
        self.solution = solution
        self.funcName = funcName
        self.paramNum = paramNum
        self.tab = '    '
    

    # 外部调用test方法进行自动测试
    def test(self, testCases, keyNames):
        '''
        param testCases: 测试数据，格式为{'cases': [], 'answers': []}
        param keyNames: 储存cases和answers中对应的key值名称，格式为[[], []]
        
        '''
        assert (isinstance(testCases, dict)) and ('cases' in testCases.keys() and 'answers' in testCases.keys()), 'Wrong Format! parameter \'testCases\' must be a dict which contains key \'cases\' and \'answers\'.'

        cases, answers = testCases['cases'], testCases['answers']
        assert (isinstance(cases, list) and isinstance(answers, list)) and (len(cases) == len(answers)) and (len(cases) > 0), 'Wrong format! \'cases\' and \'answers\' in \'testCases\' have to be two non-empty lists with same length.'

        flag = 1
        print('Begin testing.')
        cur = 0
        try:
            for i in range(0, len(cases)):
                cur = i
                params = []
                for j in range(self.paramNum):
                    params.append(cases[i][keyNames[0][j]])
                rtn = getattr(self.solution, self.funcName)(*params)
                try:
                    assert rtn == answers[i][keyNames[1]], self.tab+'case'+str(i+1)+' failed.'
                except AssertionError as ae:
                    print(ae)
                    flag = 0

        except Exception as e:
            print(self.tab+'case'+str(cur+1)+' error:', e)
            flag = 0

        if flag == 1: print(self.tab+'All passed.')




