def main():
    total, detected = 0, 0

    with open("muons.out") as fIN:
        for line in fIN:
            if line.strip():
                p, e = map(float, line.split())
                total += 1

                if p > 5 and abs(e) < 2.5:
                    detected += 1

    prob = detected / total if total > 0 else 0

    print(f"The probability for the system to detect a muon is ~{prob*100:.2f}%")

if __name__ == "__main__":
    main()