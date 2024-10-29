import random

def generate_random_file(n):
    filename = f"random_{n}.txt"
    with open(filename, "w") as fp:
        fp.write(str(n) + "\n")
        for _ in range(n):
            x = random.random()
            fp.write(str(int(x * n)) + "\n")

def generate_best_case_file(n):
    filename = f"best_case_{n}.txt"
    with open(filename, "w") as fp:
        fp.write(str(n) + "\n")
        for i in range(n):
            fp.write(str(i) + "\n")  

def generate_worst_case_file(n):
    filename = f"worst_case_{n}.txt"
    with open(filename, "w") as fp:
        fp.write(str(n) + "\n")
        for i in range(n, 0, -1):  
            fp.write(str(i) + "\n")
            
sizes = [100 ,500, 1000, 2500, 3000, 4500, 5000, 6500, 7500, 10000]  # List of different sizes

for size in sizes:
    generate_random_file(size)
    
for size in sizes:
    generate_best_case_file(size)
    

for size in sizes:
    generate_worst_case_file(size)