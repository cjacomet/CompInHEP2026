import subprocess
import random
from concurrent.futures import ProcessPoolExecutor

def run_hello(i, input):
    try:
        with open(f"output_job{i+1}.txt", 'x') as f:
            subprocess.run(
            ["make", "run", f"ARG={input}"],
            stdout=f,
            text=True,
            check=True
        )
    except FileExistsError:
        with open(f"output_job{i+1}.txt", 'w') as f:
            subprocess.run(
            ["make", "run", f"ARG={input}"],
            stdout=f,
            text=True,
            check=True
        )
            

def wrapper(args):
    run_hello(*args)

if __name__=="__main__":
    n = 10
    input = random.sample(range(1,100), n) # Generate random input numbers
    subprocess.run(["make"], check=True) # Compile and link helloNr
    with ProcessPoolExecutor(max_workers=n) as executor:
        executor.map(wrapper, zip(range(n), input))
    