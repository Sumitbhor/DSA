from .LinkedList import LinkedList
class uiManager:
    def menu(self):
        print("1. Insert")
        print("2. Search")
        print("3. Delete")
        print("4. Display")
        print("5. Exit")

    def getchoice(self):
        return int(input("Enter your choice: "))

    def insert(self, list):
        item = input("Enter item to insert: ")
        list.insert(item)
        print(f"{item} inserted.")
        return list
    
    def search(self, list):
        item = input("Enter item to search: ")
        found = list.search(item)
        if found:
            print(f"{item} found in the list.")
        else:
            print(f"{item} not found in the list.")

    def delete(self, list):
        item = input("Enter item to delete: ")
        list.delete(item)
        print(f"{item} deleted if it was present.")
        return list

    def display(self, list):
        print("Linked List contents:")
        list.display()


        