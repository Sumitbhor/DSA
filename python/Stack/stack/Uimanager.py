from .Book import Book
from .Shelf import Shelf
from .filemanager import Filemanager

class Uimanager:
    def menu(self):
        print("***** Menu *****")
        print("1.add book to shelf")
        print("2.remove book from shelf ")
        print("3.display books ")
        print("4. save data to file ")
        print("5.Exit")

    def getchoice(self):
        choice= int(input("enter your choice :  "))
        return choice 
    def addbook(self,theshelf):
        title = input("enter title of the book ")
        author= input("enter author of the book ")
        book= Book(title, author)
        theshelf.push(book)
        return theshelf
    
    def removebook(self, theshelf):
        theshelf.pop()
        return theshelf

    def savedata(self, mgr, theshelf ):
        mgr.serialize(theshelf)
    
    def exit():
        exit()


    