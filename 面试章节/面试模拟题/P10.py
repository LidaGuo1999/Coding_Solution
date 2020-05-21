'''
某个推荐系统会推荐出一系列的视频和图片结果，视频用V表示，图片用P表示，现在需要对推荐系统返回的结果进行打散，使得【图片P】的结果每N个里面最多出现1个，并且保证图片最早出现的位置不变，图片之前的相对顺序不变；
例如："V_0", "V_1", "V_2", "P_3", "P_4", "P_5", "V_6", "P_7", "V_8", "V_9"
表示： 10个结果中，位置 [0 1 2 6 8 9] 是 视频V的结果；位置 [3 4 5 7] 是 图片P的结果；
如果 要求 图片P 每3个里最多出1个，那么打散后的结果为： "V_0", "V_1", "V_2", "P_3", "V_6", "V_8", "P_4", "V_9" （P_5 和 P_7 满足不了打散要求 被删除）
如果 要求 图片P 每2个里最多出1个，那么打散后的结果为： "V_0", "V_1", "V_2", "P_3", "V_6", "P_4", "V_8", "P_5", "V_9", "P_7" 
'''
import sys

def handle(v, p, n):
    if len(p) == 0:
        return ['V_' + str(i) for i in v]
    if len(v) == 0 and n == 1:
        return ['P_' + str(i) for i in p]
    if len(v) == 0:
        return ['P_' + str(p[0])]

    ans = []
    j = 0
    i = 0
    while (i < len(v) and v[i] < p[j]):
        ans.append('V_' + str(v[i]))
        i += 1
    ans.append('P_' + str(p[j]))
    while (i < len(v) and j < len(p)):
        j += 1
        flag = 1
        for k in range(n-1):
            if i >= len(v):
                flag = 0
                break
            ans.append('V_' + str(v[i]))
            i += 1
        if flag == 0:
            break
        ans.append('P_' + str(p[j]))
    while i < len(v):
        ans.append('V_' + str(v[i]))
        i += 1


    return ans
    



if __name__ == '__main__':
    n = int(input().strip())
    m = int(input().strip())
    v = []
    p = []
    for i in range(m):
        tmp = input().strip()
        if tmp[0] == 'V':
            v.append(int(tmp[2:]))
        else:
            p.append(int(tmp[2:]))
    
    ans = handle(v, p, n)
    print(len(ans))
    for a in ans:
        print(a)



