# Taylor Series Using Recursion


def taylor_Recr(x, n):
    p, f = 1, 1
    r = 0
    if n == 0:
        return 1
    else:
        r = taylor_Recr(x, n - 1)
        p = p * x
        f *= n
    return r + p // f


x, n = list(map(int, input().split()))
res = taylor_Recr(x, n)
print(res)