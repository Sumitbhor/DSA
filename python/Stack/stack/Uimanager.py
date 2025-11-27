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
   


    