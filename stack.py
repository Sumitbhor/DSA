class stack :
    def init (self):
        self.items = [None]*100 
        self.Top = -1

    def push(self, item ):
        if self.Top<len(self.item):
            self.Top= +1 
            self.items[self.Top]= item 
        else :
            print ("Stack Overflow")
            
    def pop(self ):
