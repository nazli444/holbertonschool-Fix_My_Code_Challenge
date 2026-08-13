#!/usr/bin/python3
"""
Fix My Code Challenge - FizzBuzz
"""
import sys


def fizzbuzz(n):
    """
    FizzBuzz function prints numbers from 1 to n separated by a space.
    - multiples of 3 printed as 'Fizz'
    - multiples of 5 printed as 'Buzz'
    - multiples of both 3 and 5 printed as 'FizzBuzz'
    """
    if n < 1:
        return

    tmp_result = []
    for i in range(1, n + 1):
        if i % 15 == 0:
            tmp_result.append("FizzBuzz")
        elif i % 3 == 0:
            tmp_result.append("Fizz")
        elif i % 5 == 0:
            tmp_result.append("Buzz")
        else:
            tmp_result.append(str(i))

    print(" ".join(tmp_result))


if __name__ == "__main__":
    if len(sys.argv) <= 1:
        print("Missing number")
        sys.exit(1)

    fizzbuzz(int(sys.argv[1]))
