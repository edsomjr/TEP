from math import *


class Vector:

    def __init__(self, x, y, label):
        self.x = x
        self.y = y
        self.label = label
        
        if x >= 0 and y > 0:
            self.quad = 1;
        elif x < 0 and y >= 0:
            self.quad = 2;
        elif x <= 0 and y < 0:
            self.quad = 3;
        else:
            self.quad = 4;

    def __lt__(self, v):
        if self.quad != v.quad:
            return self.quad < v.quad

        return self.y * v.x < self.x * v.y 


def non_oriented_angle(a, b):

    num = a.x * b.x + a.y * b.y
    signal = 1

    if num < 0:
        signal = -1;

    d1 = a.x * a.x + a.y * a.y
    d2 = b.x * b.x + b.y * b.y

    return (signal * num * num, d1 * d2)


def solve(vs, N):

    vs.sort()
    vs.append(vs[0])

    min_angle = (-10, 1)
    a = -1
    b = -1

    for i in xrange(N):
        angle = non_oriented_angle(vs[i], vs[i + 1])
 
        if angle[0] * min_angle[1] > angle[1] * min_angle[0]:
            min_angle = angle
            a = vs[i].label
            b = vs[i + 1].label

    print '{} {}'.format(a, b)


if __name__ == '__main__':

    N = int(raw_input())

    vs = []

    for i in xrange(N):
        x, y = [int(k) for k in raw_input().split()]
        vs.append(Vector(x, y, i + 1))

    solve(vs, N)
