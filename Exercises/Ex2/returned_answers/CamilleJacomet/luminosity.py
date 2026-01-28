import re


def read_lines(file):
    with open(file) as f:
        lines = f.readlines()
    
    return lines


def find_column(lines, colname):
    for i, line in enumerate(lines):
        # Match a pipe-separated header line
        if re.search(rf"{re.escape(colname)}", line):
            headers = [h.strip() for h in line.split("|")]
            col_index = headers.index(colname)
            return i, col_index
    return None


def find_val(file, colname):
    lines = read_lines(file)
    indices = find_column(lines, colname)
    if indices:
        line_index, col_index = indices
        
        # Two rows below the header
        data_line = lines[line_index + 2]
        values = [v.strip() for v in data_line.split("|")]

        target_value = values[col_index]
        return float(target_value)
    return None


if __name__=="__main__":
    lum = find_val("brilcalc.log", "totrecorded(/pb)") #summary luminosity in /pb
    lum *= 1e-3 #convert to /fb
    print(f"{lum:.1f} /fb")
