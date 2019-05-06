import sys
import time
import random
from implementation import *

test_num = int(input("Insert test number : "))
for i in range(test_num):
    a = list(map(int, input("a : ")))
    b = list(map(int, input("b : ")))
    start_k = time.time()
    result = karatsuba(a[::-1], b[::-1])
    end_k = time.time()
    a = int("".join(map(str, a)))
    b = int("".join(map(str, b)))
    start_m = time.time()
    c = a*b
    end_m = time.time()
    result = result[::-1]
    c = list(map(int, str(c)))
    print("""Karatsuba : {0} / time : {1} 
          Normal : {2} / time : {3}""".format(result, end_k-start_k, c, end_m-start_m))
    assert c == result
