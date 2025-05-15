import os

os.system("g++ -o run run.cpp")
os.system("g++ -o brute brute.cpp")

while True:
    os.system("python3 test.py > input.txt")
    os.system("./run < input.txt > output1.txt")
    os.system("./brute < input.txt > output2.txt")

    if os.system("diff output1.txt output2.txt"):
        print("Mismatch found! Check input.txt, output1.txt, and output2.txt")

        with open("input.txt", "r") as f:
            print("Input----->:")
            print(f.read())

        with open("output1.txt", "r") as f:
            print("Output 1 (run)---->:")
            print(f.read())

        with open("output2.txt", "r") as f:
            print("Output 2 (brute)---->:")
            print(f.read())

        break
    else:
        print("Test passed")

