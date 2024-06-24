##
## EPITECH PROJECT, 2024
## SandPile
## File description:
## tester
##

from os import system

BOLD    = '\033[1m'
RED     = '\033[0;31m'
GREEN   = '\033[0;32m'
BLUE    = '\033[0;34m'
RESET   = '\033[0m'

class Test:

    input = ""
    expected = ""
    params = ""

    def __init__(self, file, params) -> None:
        self.input = "./tests/inputs/" + file
        self.expected = "./tests/expected/" + file
        self.params = ' '.join(params)

    def run(self) -> bool:
        print(f"[{BLUE}==={RESET}] Running test: {BOLD}{self.input}{RESET}")

        status = system(f"./sandpile {self.input} {self.params} > /tmp/sandpile_out")
        if status != 0:
            print(f"[{RED}FAIL{RESET}] {BOLD}Program Failed. Stopping.{RESET}")
            return False

        status = system(f"diff /tmp/sandpile_out {self.expected}")
        if status != 0:
            print(f"[{RED}==={RESET}] {BOLD}Output differs. Stopping.{RESET}")
            return False
        print(f"[{GREEN}==={RESET}] {BOLD}Test success!{RESET}")
        return True

if __name__ == '__main__':
    tests = [
        Test('simple_numerals', ['0123', '2'])
    ]
    for test in tests:
        if not test.run():
            exit(1)
