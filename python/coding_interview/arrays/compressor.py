def compressor(original):
    compressed = "" + original[0]
    counter = 1
    for i in range(len(original)):
        if i == len(original) - 1:
            if counter > 1:
                compressed += str(counter)
            return compressed
        else:
            if original[i] == original[i+1]:
                counter += 1
            else:
                if counter > 1:
                    compressed += str(counter)
                    counter = 1
                compressed += original[i+1]

def checker(original, compressed):
    if len(original) <= len(compressed):
        return original 
    else:
        return compressed

original = "aaaba"
# print(compressor(original))
print(checker(original, compressor(original)))


