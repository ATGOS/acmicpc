#18111
import sys
input = sys.stdin.readline
n, m, b = map(int, input().split()) #n행 m열
l=[]
for _ in range(n):
    l.append(list(map(int, input().split())))

time = 1e9;h = 0
for i in range(257):
    temp_b = b;temp_time = 0
    for n1 in range(n):
        for m1 in range(m):
            if l[n1][m1] > i: #블럭을 깨야할 때
                temp_time+=(2*(l[n1][m1]-i))
            else: #블럭을 설치하거나, 아무것도 할 필요가 없을때
                temp_time+=(i-l[n1][m1])
            temp_b+=(l[n1][m1]-i)   #인벤토리에 블럭추가 or 블럭제거
    if temp_b < 0:  #인벤에 블럭이 음수개면 그 경우는 제외
        break
    if temp_time <= time:  #이 경우의 시간이 최소일 때
        # i(기준높이)를 증가시키면서 검사하므로 뒤에것이 언제나 더 크다
        time = temp_time
        h = i
print(time, h)