import sys
input = sys.stdin.readline

n = int(input().rstrip())
time = [0]*n
price = [0]*n
for i in range(n):
    time_elem, price_elem = map(int, input().rstrip().split())
    time[i] = time_elem
    price[i] = price_elem

    
def find_max(cur_day, cur_price):
    if cur_day >= n:
        return cur_price
    if cur_day+time[cur_day] > n:
        cur_price = find_max(cur_day+1, cur_price)
    else:    
        cur_price = max(find_max(cur_day+1, cur_price), find_max(cur_day+time[cur_day], cur_price+price[cur_day]))
    return cur_price


print(find_max(0,0))