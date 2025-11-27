from collection import LinkedList, UIManager, FileManager
# Main function to run the LinkedList UI
def main():
    
    mgr = FileManager()
    ui_manager = UIManager()

    list = LinkedList()

    # Attempt to deserialize existing list from file
    list = mgr.deserialize("data/list.txt")


    while True:

        ui_manager.showMenu()
        choice = ui_manager.acceptChoice()
        
        match choice:
                case 1:
                    item = input("Enter item to insert: ")
                    list.insert(item)

                case 2:
                    item = input("Enter item to search: ")
                    found = list.search(item)
                    if found:
                        print(f"{item} found in the list.")
                    else:
                        print(f"{item} not found in the list.")

                case 3:
                    item = input("Enter item to delete: ")
                    list.delete(item)
                    print(f"{item} deleted if it was present.")

                case 4:
                    list.display()

                case 5:
                    mgr = FileManager()
                    mgr.serialize("datalist.txt",list)
                    exit(0)
                case _:
                    print("Invalid choice. Please try again.")
# Run the main function
main()
