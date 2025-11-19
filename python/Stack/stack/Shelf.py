from .Book import Book
SIZE = 10
class Shelf:
    def __init__(self):
        
        self.top =-1
        self.books=[None]*SIZE
    
    def push(self, book):
        if self.top < SIZE:
            self.top += 1
            self.books[self.top]=book
        else:
            print("stack is full ")
    def pop(self):
        if self.top== -1 :
            print("stack is empty ")
        else :
            book = self.books[self.top]
            self.top -= 1
            return book
    def display(self):
        if self.top== -1 :
            print("stack is empty ") 
        else :
            for i in range (self.top , -1 , -1 ):
                print(f"title :{self.books[i].title}, author : {self.books[i].author}")
