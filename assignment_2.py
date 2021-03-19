'''
Pseudo code:
class StringOperations:
    Algorithm __init__(self, sentence):
        {self.sentence = sentence}

    Algorithm length(self):
     {   count := 0
        for _ in self.sentence:
            count ++
        return count
        }

    Algorithm separate_words(self):
     {   words := []
        indexes := []

        for i in range 0 to self.length():
            if self.sentence[i] == " ":
                indexes.append(i)

        words.append(self.sentence[:indexes[0]])  # first word
        for i in range 0 to self.length_2(indexes) - 1 :
            words.append(self.sentence[(indexes[i] + 1):(indexes[i + 1])])
        words.append(self.sentence[(indexes[-1] + 1):])  # last word
        return words
        }

    Algorithm longest_word(self):
    {   dict_words := {}
        for i in self.separate_words():
            dict_words[i] = self.length_2(i)
        return max(dict_words, key=dict_words.get)
        }

    Algorithm chars(self, character):
      {  counter := 0
        for _ in range 0 to self.length():
            if self.sentence[_] == character:
                counter ++
        return counter
        }

    Algorithm palindrome(self):
        {counter := 0
        j := self.length()
        for _ in range 0 to self.length():
            j --
            if self.sentence[_] == self.sentence[j] then counter ++ else break
            if counter == self.length() then return "Is a palindrome" else  return "Not a palindrome"
         }

    Algorithm index(self, substring):
        {start := 0  # variable to traverse the sentence
        end := 0  # variable to traverse the substring
        while start < self.length():
            if self.sentence[start + end] != substring[end] then start += 1 end = 0 continue
            end += 1
            if end == self.length_2(substring) then return start
        return "Not present"
        }

 Algorithm index(self, substring):
        {start := 0  # variable to traverse the sentence
        end := 0  # variable to traverse the substring
        while start < self.length():
            if self.sentence[start + end] != substring[end] then start += 1 end = 0 continue end += 1
            if end == self.length_2(substring) then return start
        return "Not present"
        }

    Algorithm occurrences(self):
        {words := self.separate_words()
        words_frequency := {}
        for _ in words:
            counter := 0
            for word in words:
                if _ == word:
                    counter ++
            words_frequency[_] := counter
        return words_frequency}
'''

# Write a Python program to compute following operations on String:
# a) To display word with the longest length
# b) To determines the frequency of occurrence of particular character in the string
# c) To check whether given string is palindrome or not
# d) To display index of first appearance of the substring
# e) To count the occurrences of each word in a given string

# for separating the words from a string
# assuming that the sentence does not start and end with a whitespace
# assuming that the sentence does not end with a full stop

class StringOperations:
    def __init__(self, sentence):
        self.sentence = sentence

    # length of the sentence
    def length(self):
        count = 0
        for _ in self.sentence:
            count += 1
        return count

    # length of the word
    def length_2(self, word):
        count = 0
        for _ in word:
            count += 1
        return count

    # separating words from a sentence
    def separate_words(self):
        words = []
        indexes = []

        for i in range(0, self.length()):
            if self.sentence[i] == " ":
                indexes.append(i)

        words.append(self.sentence[:indexes[0]])  # first word
        for i in range(0, self.length_2(indexes) - 1):
            words.append(self.sentence[(indexes[i] + 1):(indexes[i + 1])])
        words.append(self.sentence[(indexes[-1] + 1):])  # last word
        return words

    # display word with the longest length
    def longest_word(self):
        dict_words = {}
        for i in self.separate_words():
            dict_words[i] = self.length_2(i)
        return max(dict_words, key=dict_words.get)

    # frequency of a character in the string
    def chars(self, character):
        counter = 0
        for _ in range(0, self.length()):
            if self.sentence[_] == character:
                counter += 1
        return counter

    # to check whether sentence is palindrome
    def palindrome(self):
        counter = 0
        j = self.length()
        for _ in range(0, self.length()):
            j -= 1
            if self.sentence[_] == self.sentence[j]:
                counter += 1
            else:
                break
        if counter == self.length():
            return "Is a palindrome"
        else:
            return "Not a palindrome"

    def index(self, substring):
        start = 0  # variable to traverse the sentence
        end = 0  # variable to traverse the substring
        while start < self.length():
            if self.sentence[start + end] != substring[end]:
                start += 1
                end = 0
                continue
            end += 1
            if end == self.length_2(substring):
                return start
        return "Not present"

    def occurrences(self):
        words = self.separate_words()
        words_frequency = {}
        for _ in words:
            counter = 0
            for word in words:
                if _ == word:
                    counter += 1
            words_frequency[_] = counter
        return words_frequency


# menu driven program
# taking the sentence
enter_sentence = input('Enter a sentence:')

obj1 = StringOperations(enter_sentence)  # object creation

# choose an option

n = 0
while n != 6:
    print("Choose an option:\n 1.Display word with the longest length.")
    print(" 2.Determine the frequency of occurrence of particular character in the string.")
    print(" 3.Check whether given string is palindrome or not")
    print(" 4.Display index of first appearance of the substring")
    print(" 5.Count the occurrences of each word in a given string")
    print(" 6.Exit ")
    n = int(input())

    if n == 1:
        print(obj1.longest_word())

    if n == 2:
        character = input("Enter a character:")
        print(obj1.chars(character))

    if n == 3:
        print(obj1.palindrome())

    if n == 4:
        substring = input("Enter the substring:")
        print(obj1.index(substring))

    if n == 5:
        print(obj1.occurrences())

print("Byee")







