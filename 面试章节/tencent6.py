import sys

if __name__ == "__main__":
    # 读取第一行的n
    T = int(sys.stdin.readline().strip())
    for t in range(T):
        n = int(sys.stdin.readline().strip())
        relation = {}
        for a in range(n):
            x, y = list(map(int, sys.stdin.readline().strip().split()))
            if relation.get(x) == None:
                if relation.get(y) == None:
                    relation.setdefault(x, set())
                    relation[y] = relation[x]
                else:
                    relation.setdefault(x, relation[y])
                relation[x].add(y)
                relation[y].add(x)
            else:
                if relation.get(y) == None:
                    relation.setdefault(y, relation[x])
                else:
                    tmp = relation[y]
                    relation[x].update(relation[y])
                    for q in tmp:
                        relation[q] = relation[x]
                relation[x].add(y)
                relation[y].add(x)
            #print(relation)
            #print(id(relation[1]))
            #print(id(relation[2]))
        sizes = list(map(len, relation.values()))
        print(max(sizes))
