import math

class AreaCalc:
    # TODO: Implement calculate method
    @staticmethod
    def calculate(length,width=None):
        if width:
            return length * width
        return round(math.pi*length*length,2)
        
    
# Don't modify the following code
calc = AreaCalc()
print(calc.calculate(5))    
print(calc.calculate(4, 6))
