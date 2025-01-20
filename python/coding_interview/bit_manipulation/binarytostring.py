def pb (num):
    if num >= 1 or num <= 0:
        return "Error"
    binary = ['.']
    fraction = .5
    while num > 0:
        if len(binary) >= 32:
            return "Error"
        # r = num * 2
        # if r >= 1:
        #     binary.append('1')
        #     num = r - 1
        # else:
        #     binary.append('0')
        #     num = r

        if num >= fraction:
            binary.append('1')
            num -= fraction
        else:
            binary.append('0')
        fraction /= 2
 
    return "".join(binary)

print(pb(.125))
        


