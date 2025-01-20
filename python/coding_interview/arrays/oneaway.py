def createHash(str1):
    strhash = {}
    for letter in str1:
        strhash[letter] = strhash.get(letter, 0) + 1
    return strhash

def substractFromHash(str1, str2):
    strhash = createHash(str1)
    for letter in str2:
        strhash[letter] = strhash.get(letter, 0) - 1
    return strhash

def checkHash(strhash):
    negFlag, posFlag = False, False
    for letter, count in strhash.items():
        if count == -1 and not negFlag:
            negFlag = True
        elif count == 1 and not posFlag:
            posFlag = True
        elif count != 0:
            return False
    return True


str1 = "aaaaa"
str2 = ""
print(checkHash(substractFromHash(str1, str2)))
