def swap_a(a):
    if len(a) <= 1:
        return a
    a[0], a[1] = a[1], a[0]

def swap_b(b):
    if len(b) <= 1:
        return b
    b[0], b[1] = b[1], b[0]

def ss(a, b):
    swap_a(a)
    swap_b(b)

def push_a(a, b):
    pass

a = [1, 2, 3]
b = [1, 2, 3]

swap_a(b)

