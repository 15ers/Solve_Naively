def translate(stream,option):
    if option != 2:
        split_index = [i for i in range(len(stream)) if ord(stream[i])<=90]
        lower_stream = "".join([e.lower() for e in stream])
    # camel
    if option == 1:
        camel = stream
        pascal = stream[0].upper()+stream[1:]
        split_index = [0] + split_index
        snake = [lower_stream[split_index[i]:split_index[i+1]] for i in range(len(split_index)-1)]
        snake += [lower_stream[split_index[-1]:]]
        snake = "_".join(snake)
    # snake
    elif option == 2:
        snake = stream
        table = stream.split("_")
        camel = "".join([elem.capitalize() if index!=0 else elem for index,elem in enumerate(table)])
        pascal = "".join([elem.capitalize() for index,elem in enumerate(table)])
    # pascal
    else:
        pascal = stream
        camel = stream[0].lower()+stream[1:]
        snake = [lower_stream[split_index[i]:split_index[i+1]] for i in range(len(split_index)-1)]
        snake += [lower_stream[split_index[-1]:]]
        snake = "_".join(snake)
    print(camel,snake,pascal, sep="\n")
op, stream = input().split()
op = int(op)
translate(stream,op)
"""
<beautiful solution!: from boj id jh05013>
def camelsplit(s):
    t = ''
    for c in s:
        if "A"<=c<="Z" and t: yield t.lower(); t = ''
        t+= c
    if t: yield t.lower()

mode, s = input().split()
word = list(camelsplit(s)) if mode != '2' else s.split('_')
print(''.join([word[0]] + [w.capitalize() for w in word[1:]]))
print('_'.join(word))
print(''.join(w.capitalize() for w in word))
"""