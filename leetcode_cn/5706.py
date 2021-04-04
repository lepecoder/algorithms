class Solution:
    def areSentencesSimilar(self, sentence1: str, sentence2: str) -> bool:
        sent1 = sentence1.split(' ')
        sent2 = sentence2.split(' ')
        if len(sent1) > len(sent2):
            sent1, sent2 = sent2, sent1
        # sent1总是短的
        print(sent1)
        print(sent2)
        for x in sent1:
            if x in sent2:
                idx = sent2.index(x)
                sent2[idx] = '-'
                # sent2.remove(x)
            else:
                return False

        # 非-必须是连续的、
        i = 0
        print(sent2)
        while i < len(sent2) and sent2[i] == '-':
            i += 1
        while i < len(sent2) and sent2[i] != '-':
            i += 1
        while i < len(sent2) and sent2[i] == '-':
            i += 1
        return i == len(sent2)

        # # 找到第一个‘-’
        # start = sent2.index('-')
        # # 找到最后一个
        # sent2.reverse()
        # end = sent2.index('-')
        # sent2.reverse()
        # end = len(sent2) - end
        # # 开始和结束至少有一个在开头而且中间没有非-
        # if start != 0 and end != len(sent2):
        #     return False
        # if start ==0 and end == len()
        # for i in range(start, end):
        #     if sent2[i] != '-':
        #         return False
        # return True


so = Solution()
s1 = "My a Haley"
s2 = "My Haley"
print(so.areSentencesSimilar(s1, s2))
