test_num = int(input())
for test in range(test_num):
    block_num, quest_num = map(int, input().split())
    block = input()
    ans = 0
    # building frequency table
    stock = [[0 for i in range(26)] for i in range(len(block))]
    for i, each in enumerate(block):
        if i > 0:
            # copy from past index, if index > 0
            stock[i][:] = stock[i-1][:]
            stock[i][ord(each)-ord("A")] += 1
        else:
            stock[i][ord(each)-ord("A")] += 1
    for quest in range(quest_num):
        start, end = map(int, input().split())
        start -= 1
        end -= 1
        length = end - start + 1
        is_ans = 1
        # for even length case
        if length % 2 == 0:
            if start == 0:
                for i in range(26):
                    if stock[end][i] % 2 != 0:
                        is_ans = 0
            else:
                for i in range(26):
                    # use prefix sum
                    if (stock[end][i] - stock[start-1][i]) % 2 != 0:
                        is_ans = 0
        # for odd length case
        else:
            odd_mid = 0
            if start == 0:
                for i in range(26):
                    if stock[end][i] % 2 != 0:
                        odd_mid += 1
                if odd_mid != 1:
                    is_ans = 0
            else:
                for i in range(26):
                    # use prefix sum
                    if (stock[end][i] - stock[start-1][i]) % 2 != 0:
                        odd_mid += 1
                if odd_mid != 1:
                    is_ans = 0
        if is_ans:
            ans += 1
    print("Case #{0}: {1}".format(test+1, ans))