import re


def find_value(file, colname):
    with open(file) as f:
        lines = f.readlines()

    for i, line in enumerate(lines):
        # Match a pipe-separated header line
        if re.search(rf"\b{re.escape(colname)}\b", line):
            headers = [h.strip() for h in line.split("|")]
            col_index = headers.index(colname)

            # Two rows below the header
            data_line = lines[i + 2]
            values = [v.strip() for v in data_line.split("|")]

            target_value = values[col_index]
            return target_value
    
    return None


if __name__=="__main__":
    lum = find_value("brilcalc.log", "totrecorded(/pb)") #summary luminosity in /pb
    lum *= 1e-3 #convert to /fb
    print(f"{lum:.1f}")
