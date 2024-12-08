e = []

with open("myAnswer", "r") as f:
    for line in f:
        if line == '-1':
            print('AC')
            exit()
        edge = line.split(' ')
        e.append(int(edge[0], int(edge[1])))


pref = [arr[0]]
for i in range(1,len(arr)):
    pref.append(pref[i-1]+arr[i])


suff = [arr[-1]]
for i in range(0,len(arr)-1, -1):
    suff.append(suff[i+1]+arr[i])
with open("input_file", "r") as f:
    t = int(f.readline())
    n,x,y = map(int, f.readline().split())

