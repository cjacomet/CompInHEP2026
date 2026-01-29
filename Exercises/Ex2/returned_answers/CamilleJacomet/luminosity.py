import re


def read_lines(file):
    with open(file) as f:
        return f.readlines()


def find_column(lines, colname):
    for i, line in enumerate(lines):
        # Match a pipe-separated header line
        if re.search(rf"\b{colname}\b", line):
            headers = [h.strip() for h in line.split("|")]
            col_index = next(i for i, h in enumerate(headers) if colname in h)
            return i, col_index
    return None


def find_val(file, colname):
    lines = read_lines(file)
    indices = find_column(lines, colname)
    if indices:
        line_index, col_index = indices
        
        data_line = lines[line_index + 2] # Two rows below the header
        values = [v.strip() for v in data_line.split("|")]

        target_value = values[col_index]
        return float(target_value)
    return None


def sum_vals(file, colname):
    lines = read_lines(file)
    indices = find_column(lines, colname)
    if indices:
        line_index, col_index = indices
        line_index += 2 # Two rows below the header
        sum = 0.0
        while '|' in lines[line_index]:
            data_line = lines[line_index]
            values = [v.strip() for v in data_line.split("|")]
            sum += float(values[col_index])
            line_index += 1
        return sum
    return None


if __name__=="__main__":
    lum = find_val("brilcalc.log", "totrecorded")
    lum = round(lum * 1e-3, 1) #convert to /fb and round to 1 decimal
    print(f"totrecorded (/fb): {lum:.1f}")
    sum_lum = sum_vals("brilcalc.log", "recorded")
    sum_lum = round(sum_lum * 1e-3, 1) #convert to /fb and round to 1 decimal
    print(f"sum of recorded (/fb): {sum_lum:.1f}")
    print(f"sum recorded {'=' if lum == sum_lum else 'does not equal'} totrecorded")
