from LinkedList import LinkedList, uiManager

def main():
    list = LinkedList()
    ui_manager = uiManager()
    
    while True:
        ui_manager.menu()
        choice = ui_manager.getchoice()
        
        if choice == 1:
           list = ui_manager.insert(list)
        elif choice == 2 :
            ui_manager.search(list)
        elif choice == 3:
            list = ui_manager.delete(list)
        elif choice == 4:
            ui_manager.display(list)
        elif choice == 5:
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please try again.")

main()