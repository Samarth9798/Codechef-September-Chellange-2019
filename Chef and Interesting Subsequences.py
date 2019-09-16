# cook your dish here
T = int(input())
def nCr(n,r):
    fact = [0]*(n+1)
    fact[0] = 1
    for i in range(1, n+1):
        fact[i] = fact[i-1] * i
    
    p = fact[n]
    q = fact[r] * fact[n-r]
    return (p//q)
    
while T:
    T-=1
    n,k = map(int, input().split())
    a = list(map(int, input().split()))
    
    m = dict()
    for i in range(0, n):
        if a[i] in m:
            m[a[i]] += 1
        else:
            m[a[i]] = 1
    
    a.sort()
    x = a[k-1]
    r = 0
    for i in range(k-1, -1, -1):
        if a[i] != x:
            break
        r += 1
    total = m[x]
    ans = nCr(total, r)
    print(ans)
        
        
    
