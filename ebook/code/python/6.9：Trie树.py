from rcdtype import *

TrieNode = recordtype("TrieNode", ["Char", "Counter", "next"])

def newTrie():
    return TrieNode("root", 0, [])

def updateWord(t, word):
    ot = t
    tail = len(word) - 1
    for idx, c in enumerate(word):
        found = False
        for tn in t.next:
            if tn.Char == c:
                t = tn
                found = True
                if idx == tail:
                    t.Counter = t.Counter + 1
                break
        if found == False:
            cnt = 0 if idx != tail else 1
            new = TrieNode(c, cnt, [])
            t.next.append(new)
            t = new
    return ot

def getWord(t, word):
    tail = len(word) - 1
    for idx, c in enumerate(word):
        for tn in t.next:
            if tn.Char == c:
                t = tn
                if idx == tail:
                    return t.Counter
                break
    return 0

if __name__ == "__main__":
    trie = newTrie()
    words = ["inn", "int", "at", "age", "adv", "ant", "in", "in"]
    for w in words:
        print "add [%8s]" % (w)
        trie = updateWord(trie, w)
    print trie
    words = ["int", "in", "inv"]
    for w in words:
        print "search [%8s] coutner %d" % (w, getWord(trie, w))
