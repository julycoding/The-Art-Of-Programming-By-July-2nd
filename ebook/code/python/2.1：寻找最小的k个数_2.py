import heapq


class topk():
    # support for dynamic push
    def __init__(self, k):
        self.k = k
        self.h = []

    def push(self, val):
        val = -val
        if len(self.h) < self.k:
            heapq.heappush(self.h, val)
        else:
            heapq.heappushpop(self.h, val)

    def result(self):
        return map(lambda x: -x, self.h)


if __name__ == "__main__":
    l = [1, 9, 2, 4, 7, 6, 3]
    t = topk(3)
    for i in l:
        t.push(i)
    print t.result()
