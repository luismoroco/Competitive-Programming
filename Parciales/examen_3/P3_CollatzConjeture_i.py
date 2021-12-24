# https://open.kattis.com/problems/collatz

def FIRST_FUNCTION(n, visited):
    ANS = 0
    while n > 1:
        ANS += 1
        n = 3 * n + 1 if n & 1 else n >> 1
        if n not in visited:
            visited[n] = ANS


def AUXILIAR_FUNCTION(n, other):
    ANS = 0
    if n not in other:
        while n > 1:
            ANS += 1
            n = 3 * n + 1 if n & 1 else n >> 1
            if n in other:
                return n, ANS
    return n, ANS

while True:
    DATA = input().split()
    a = int(DATA[0])
    b = int(DATA[1])
    if a == 0 or b == 0:
        break
    visitedA = {a: 0}
    FIRST_FUNCTION(a, visitedA)
    nc = AUXILIAR_FUNCTION(b, visitedA)
    n = nc[0]
    c = nc[1]
    print("{:d} needs {:d} steps, {:d} needs {:d} steps, they meet at {:d}".format(a, visitedA[n], b, c, n))
