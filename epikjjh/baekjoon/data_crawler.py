import os
from sys import argv
import requests
from bs4 import BeautifulSoup


class CrawlData:
    def __init__(self, argv):
        self.argv = argv
        # Parse problem number
        try:
            self.problem_file = self.argv[1]
        except IndexError:
            print("Write test file name")
            exit()
        else:
            self.problem_number = self.problem_file.split(".")[0]
        # Set url & Get response data
        self.url = "https://www.acmicpc.net/problem/" + self.problem_number

        
    def get_html(self):
            ret = requests.get(self.url)
            if ret.status_code == 200:
                return ret.text
            else:
                print("Invalid url")
                exit()            


    def set_data(self):
        response = self.get_html()
        soup = BeautifulSoup(response, 'html.parser')
        sample_data = [list(filter(None, elem.get_text().split("\r\n"))) for elem in soup.find_all("pre", {"class": "sampledata"})]
        self.input_data = sample_data[0::2]
        output_data = sample_data[1::2]
        output_data = [[e.rstrip()] for elem in output_data for e in elem]
        self.output_data = output_data
        