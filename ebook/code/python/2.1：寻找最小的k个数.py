import heapq


def wrap(x):
    return -x


def unwrap(x):
    return -x


def topk(lst, k):
    h = []
    for i in lst[0:k]:
        heapq.heappush(h, wrap(i))
    for i in lst[k:]:
        heapq.heappushpop(h, wrap(i))
    return map(unwrap, h)


if __name__ == "__main__":
    l = [1, 9, 2, 4, 7, 6, 3]
    k = 3
    print topk(l, k)
