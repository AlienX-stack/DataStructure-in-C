# Method 1
# def power(m, n):
#     if n == 0:
#         return 1
#     else:
#         return power(m, n - 1) * m


# Method 2
def power(m, n):
    if n == 0:
        return 1
    elif n % 2 == 0:
        return power(m * m, n // 2)
    elif n % 2 != 0:
        return m * power(m * m, n // 2)


m, n = list(map(int, input().split()))
result = power(m, n)
print(f"Power of {m}^{n} -> {result}")
