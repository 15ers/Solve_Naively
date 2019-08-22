import os
from sys import argv
from data_crawler import CrawlData


data = CrawlData(argv)
data.set_data()
for elem in data.input_data:
    stream = "\n".join(elem)
    input_stream = "FILE >> result.txt\n" + stream + "\nFILE\n"
    order = "python3 " + data.problem_file + " << " + input_stream
    os.system(order)
with open("result.txt", "r") as f:
    output = f.read().rstrip()
    answer = ""
    for elem in data.output_data:
        stream = "\n".join(elem)
        answer += stream + "\n"
    answer = answer.rstrip()
    if output == answer:
        print("Answer correctly")
    else:
        print("Wrong answer!")
        print("Your answer:\n" + output)
        print("Answer: \n" + answer)
os.remove("result.txt")