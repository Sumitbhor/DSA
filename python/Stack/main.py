from stack import Book ,Shelf, Filemanager , Uimanager

def main():
    theshelf= Shelf()
    mgr = Filemanager()
    uimgr= Uimanager()
    theshelf= mgr.deserialize()
    
    while True:
        uimgr .menu()
        choice= uimgr.getchoice()
        if choice==1:
            tittle= input("enter book title : ")
            author= input("enter book author : ")
            book= Book(tittle, author)
            theshelf.push(book)
        elif choice==2:
            tittle= input("enter book title to remove : ")
            theshelf.pop(tittle)
        elif choice==3:
            theshelf.display()
        elif choice==4:
            mgr.serialize(theshelf)
        elif choice==5:
            print("Exiting the program.")
            break
        else:
            print("invalid choice , please try again ")
if __name__ == "__main__":
    main()