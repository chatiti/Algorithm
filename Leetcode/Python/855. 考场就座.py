class ExamRoom:

    def __init__(self, n: int):
        self.seats = []
        self.n = n
        
    def find(self,value:int)->int:
        low,high=0,len(self.seats)
        while low<high:
            mid=(low+high)//2
            if self.seats[mid]<value:
                low=mid+1
            else:
                high=mid
        return low  
    
    def seat(self) -> int:
        if not self.seats:
            self.seats.append(0)
            return 0

        max_distance = self.seats[0]
        p = 0        
        for i in range(1, len(self.seats)):
            left = self.seats[i-1]
            right = self.seats[i]
            distance = (right-left)//2
            if distance > max_distance:
                max_distance = distance
                p = distance + left

        if self.n - 1 - self.seats[-1] > max_distance:
            p  = self.n - 1
        insert_p = self.find(p)
        self.seats.insert(insert_p, p)
        return p
        
            
    def leave(self, p: int) -> None:
        self.seats.remove(p)
    
    
# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(n)
# param_1 = obj.seat()
# obj.leave(p)