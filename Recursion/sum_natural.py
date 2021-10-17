def sum_Natural(n):
    if n == 0:
        return 0
    else:
        return sum_Natural(n - 1) + n


n = int(input())
result = sum_Natural(n)
print(f"Sum of first {n} natural numbers -> {result}")
