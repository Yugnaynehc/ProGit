import math

class Circle():
    
    def __init__(self, radius):
        self.radius = radius

    def setRadius(self, radius):
        self.radius = radius
        
    @property
    def area(self):
        return math.pi*self.radius**2

    def getArea(self):
        return math.pi*self.radius**2


if  __name__ == "__main__":

    a = Circle(10)
    print a.area
    
    a.setRadius(100)
    print a.area
    print a.getArea()

    
    
