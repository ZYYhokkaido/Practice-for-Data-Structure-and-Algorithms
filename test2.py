n,k=map(int,input().split())
list1=list(map(int,input().split()))

list2=[]
for i in range(0,n-1):
    for j in range(i+1,n):
        temp=list1[i]*list1[j]
        list2.append(temp)

list2.sort()
print(list2[k-1])