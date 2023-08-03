class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if(digits==""):
            return []
        dict={
            '2':["a","b","c"],
            '3':["d","e","f"],
            '4':["g","h","i"],
            '5':["j","k","l"],
            '6':["m","n","o"],
            '7':["p","q","r","s"],
            '8':["t","u","v"],
            '9':["w","x","y","z"]
        }
        intial=dict[digits[0]]
        def ret(val):
            nonlocal intial
            temp=[]
            for i in range(len(intial)):
                for j in range(len(dict[val])):
                    temp.append(intial[i]+dict[val][j])
            intial=temp
        for i in range(1,len(digits),1):
            ret(digits[i])
        return intial