'''
Suppose a,b are 258 long.
a = a1*10^128 + a0 (a1, a0 are each 128 long. -> High, Low)
b = b1*10^128 + b0 (b1, b0 are each 128 long. -> High, Low)
a*b = a1*b1*10^256 + (a1*b0 + a0*b1)*10^128 + a0*b0
z0 = a0*b0
z1 = a1*b0 + a0*b1 = (a0+a1) * (b0+b1) - z0 - z2
z2 = a1*b1
(a0+a1) * (b0+b1) = z0 + z1 + z2
'''


def normalize(c: list)-> list:
    c.append(0)
    for i in range(len(c)-1):
        if c[i] < 0:
            borrow = (abs(c[i])+9) // 10
            c[i+1] -= borrow
            c[i] += borrow*10
        else:
            c[i+1] += c[i] // 10
            c[i] %= 10
    while len(c) > 1 and c[-1] == 0:
        c.pop()
    return c

        
def multiply(a: list, b: list)->list:
    c = [0]*(len(a)+len(b)+1)
    for i in range(len(a)):
        for j in range(len(b)):
            c[i+j] += a[i]*b[j]
    normalize(c)
    return c


def addTo(a: list, b: list, k: int)-> list:
    if b == [0]:
        return a
    elif len(a) > len(b) + k:
        for i in range(len(b)):
            a[i+k] += b[i]
    else:
        c = [0]*(len(b)+k)
        c[:len(a)] = a[:]
        for i in range(len(b)):
            c[i+k] += b[i]
        a[:] = c
    normalize(a)
    return a


def subFrom(a: list, b: list)-> list:
    for i in range(len(b)):
        a[i] -= b[i]
    normalize(a)
    return a
      

def karatsuba(a: list, b: list)->list:
    an = len(a)
    bn = len(b)
    
    if an < bn:
        return karatsuba(b, a)
    if an == 0 or bn == 0 or (an == 1 and a[0] == 0) or (bn == 1 and b[0] == 0):
        return [0]
    if an <= 50:
        return multiply(a, b)
    half = an // 2
    a0 = a[:half]
    a1 = a[half:] if a[half:] or an > 1 else [0]
    b0 = b[:half]
    b1 = b[half:] if b[half:] or bn > 1 else [0]
    z0 = karatsuba(a0, b0)
    z2 = karatsuba(a1, b1)
    addTo(a0, a1, 0)
    addTo(b0, b1, 0)
    z1 = karatsuba(a0, b0)
    subFrom(z1, z0)
    subFrom(z1, z2)
    ret = []
    addTo(ret, z0, 0)
    addTo(ret, z1, half)
    addTo(ret, z2, half*2)
    return ret
