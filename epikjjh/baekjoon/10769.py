import sys

input = sys.stdin.readline().rstrip
target = input()

happy = ":-)"
sad = ":-("

happy_num = target.count(happy)
sad_num = target.count(sad)

print("none" if not happy_num and not sad_num else "unsure" if happy_num==sad_num else "happy" if happy_num>sad_num else "sad")
