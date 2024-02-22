def resistors(seq, R):
    n= len(seq) - 1
    value =0
    for i in range(0,n):
        for v in range(i+1,n):
            value= seq[i]+seq[v]
            if value == R:
                return 1
    return 0