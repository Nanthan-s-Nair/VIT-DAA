import random

def generate_random_points_file(n):
    filename = f"points_random_{n}.txt"
    with open(filename, "w") as fp:
        fp.write(f"{n}\n")
        for _ in range(n):
            x = random.randint(0, 1000)
            y = random.randint(0, 1000)
            fp.write(f"{x} {y}\n")

def generate_best_case_points_file(n):
    filename = f"points_best_{n}.txt"
    with open(filename, "w") as fp:
        fp.write(f"{n}\n")
        for i in range(n):
            x = i
            y = i
            fp.write(f"{x} {y}\n")

def generate_worst_case_points_file(n):
    filename = f"points_worst_{n}.txt"
    with open(filename, "w") as fp:
        fp.write(f"{n}\n")
        for i in range(n, 0, -1):
            x = i
            y = i
            fp.write(f"{x} {y}\n")

sizes = [100, 500, 1000, 2500, 3000, 4500, 5000, 6500, 7500, 10000]

for size in sizes:
    generate_random_points_file(size)
    generate_best_case_points_file(size)
    generate_worst_case_points_file(size)