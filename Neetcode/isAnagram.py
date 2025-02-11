#Purpose: IsAnagram(s,t) checks if two letters are anagrams or no
#isAnagram: Str, Str -> Bool

#Time complexity: O(n)
#Space complexity: O(n)

def isAnagram(s,t):
    s = s.lower()
    t = t.lower()

    if len(s) != len(t):
        return False
    
    seen = {}

    for char in s:
        if char in seen:
            seen[char] += 1
        else:
            seen[char] = 1

    for char in t:
        if char in seen:
            seen[char] -= 1
        else:
            seen[char] = 1

    for key in seen:
        if seen[key] != 0:
            return False
    return True

#edge cases
isAnagram("", " ") #False
isAnagram("carrace", "RaceCar") #True
isAnagram("a", "a") #True
isAnagram("a", "b") #False




