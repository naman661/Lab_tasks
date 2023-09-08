class Solution:
    def largestWordCount(self, messages: List[str], senders: List[str]) -> str:
        m = []
        n = len(messages)
        D = {}
        d["a"] = 0
        
        for i in range(n):
            s = messages[i]
            c = 0
            for j in s:
                if j == " ":
                    c+=1
            
 #           m.append([c,senders[i]])
        m.sort()
        m.reverse()
        w = m[0][0]
        a = []
        for i in range(n):
            if m[i][0] == w:
                a.append(m[i][1])
            else:
                break
        a.sort()
        return a[-1]



