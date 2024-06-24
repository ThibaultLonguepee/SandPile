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
        print(f"\t[{BLUE}==={RESET}] Running test: {BOLD}{self.input}{RESET}")

        status = system(f"./sandpile {self.input} {self.params} > /tmp/sandpile_out")
        if status != 0:
            print(f"\t[{RED}FAIL{RESET}] {BOLD}Program Failed. Stopping.{RESET}")
            return False

        status = system(f"diff /tmp/sandpile_out {self.expected} > /dev/null")
        if status != 0:
            print(f"\t[{RED}==={RESET}] {BOLD}Output differs. Stopping.{RESET}")
            return False
        print(f"\t[{GREEN}==={RESET}] {BOLD}Test success!{RESET}")
        return True

class Build:

    target = ""

    def __init__(self, target) -> None:
        self.target = target

    def build(self) -> bool:
        print(f"[{BLUE}==={RESET}] Building for: {BOLD}{self.target}{RESET}")
        status = system(f"make {self.target} > /dev/null")
        if status != 0:
            print(f"[{RED}==={RESET}] {BOLD}Build failed.{RESET}")
        return status == 0

    def clean(self) -> None:
        system("make fclean > /dev/null")

if __name__ == '__main__':
    builds = [
        Build("DEFAULT"),
        Build("COPY_COLLAPSE"),
        Build("SELF_COLLAPSE"),
    ]
    tests = [
        Test('simple_numerals', ['0123', '2']),
    ]
    for build in builds:
        print('')
        if not build.build():
            exit(1)
        for test in tests:
            test.run()
        build.clean()
