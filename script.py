def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


def sum_of_first_n_primes(n):
    count = 0
    num = 2
    total = 0
    itr = 0
    while count < n:
        itr = itr + 1
        if is_prime(num):
            total += num
            count += 1
        num += 1
    print("itr: ", itr < 10000000)
    return total


# Example:
print(sum_of_first_n_primes(500000))  # Output: 129
