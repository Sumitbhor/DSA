from stack import Book ,Shelf, Filemanager 

def main():
    theshelf= Shelf()
    mgr = Filemanager()
    theshelf= mgr.deserialize()
    while True:
        print("***** Menu *****")
        print("1.add book to shelf")
        print("2.remove book from shelf ")
        print("3.display books ")
        print("4. save data to file ")
        print("5.Exit")

        choice= int(input("enter your choice :  "))

        if choice == 1 :
            title = input("enter title of the book ")
            author= input("enter author of the book ")
            book= Book(title, author)
            theshelf.push(book)

        elif choice== 2:
            theshelf.pop()
        elif choice==3 : 
            theshelf.display()
        elif choice == 4 :
            mgr.serialize(theshelf)
        elif choice == 5 :
            exit()
        else : 
            print("invalid choice ")

main()