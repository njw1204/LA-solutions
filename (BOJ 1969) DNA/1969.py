n,m = map(int,input().split())
cnt = [{'A':0,'C':0,'G':0,'T':0} for i in range(m)]
for i in range(n):
  dna = input()
  for j in range(m):
    cnt[j][dna[j]] += 1

ans,ans2 = [],0
for i in cnt:
  r = sorted(i.items(),key = lambda x:(-x[1],x[0]))[0]
  ans.append(r[0])
  ans2 += n - r[1]

print(''.join(ans),ans2,sep='\n')