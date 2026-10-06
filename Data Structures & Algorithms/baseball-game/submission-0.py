class Solution:
    def calPoints(self, operations: List[str]) -> int:
        result=[]
        for i in range (0,len(operations)):
            if operations[i] == '+':
                result.append(result[-1]+result[-2])
            elif operations[i] == 'D':
                result.append(result[-1]*2)
            elif operations[i] =='C':
                result.pop()
            else:
                result.append(int(operations[i]))
        sum= 0
        for i in result:
            sum+=i
        return sum            
        