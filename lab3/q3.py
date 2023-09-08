import copy


def largestRectangle(h):
    

    def next_smallest_index(a):
        n = len(a)
        b = copy.deepcopy(a)
        b.append(0)
        b.insert(0,0)
        c = []
        for i in range(n+2):
            c.append(0)
        c[-1] = n+2
        for i in range(1,n+2):
            #print(c)
            k = n+1-i
            if b[k]>b[k+1]:
                c[k] = k+1+1
                
            else:
                for j in range(k+1,n+2):
                    if b[k]>b[c[j]-1]:
                        c[k] = c[j]
                        break
        c[0] = n+2
        return c

    n = len(h)
    l = h
    s = copy.deepcopy(l)
    f = next_smallest_index(l)
    l.reverse()
    p = l;
    g = next_smallest_index(p)
    n = len(l)
    for i in range(n+2):
        g[i] = n+3 - g[i]
    g.reverse()
    q = g


    s.append(0)
    s.insert(0,0)
    for i in range(n+2):
        f[i] -=1

    t = []
    for i in range(n+2):
        t.append(s[i]*(f[i]-q[i]))
        
    return (max(t))