def get_longer_word(word1: str, word2: str) -> str:
    return max(word1,word2,key=len)



# do not modify below this line
print(get_longer_word("yellow", "orange"))
print(get_longer_word("red", "blue"))
print(get_longer_word("green", "blue"))
