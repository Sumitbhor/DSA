from stack import Book ,Shelf, Filemanager , Uimanager

def main():
    theshelf= Shelf()
    mgr = Filemanager()
    uimgr= Uimanager()
    theshelf= mgr.deserialize()
    
    while True:
        uimgr .menu()
        choice= uimgr.getchoice()
        if choice == 1:
            theshelf = uimgr.addbook(theshelf)
        elif choice == 2:
            theshelf = uimgr.removebook(theshelf)
        elif choice == 3:
            theshelf.display()
        elif choice == 4:
            uimgr.savedata(mgr, theshelf)
        elif choice == 5:
            uimgr.exit()
        else:
            print("invalid choice ")
          


main()