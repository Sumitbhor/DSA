# Node class for Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Stack class using Linked List
class Stack:
    def __init__(self):
        self.top = None

    # Push operation
    def push(self, data):
        new_node = Node(data)
        new_node.next = self.top
        self.top = new_node
        print(f"Pushed {data}")

    # Pop operation
    def pop(self):
        if self.is_empty():
            print("Stack Underflow! Cannot pop.")
            return None
        popped = self.top.data
        self.top = self.top.next
        print(f"Popped {popped}")
        return popped

    # Peek operation
    def peek(self):
        if self.is_empty():
            print("Stack is empty!")
            return None
        return self.top.data

    # Check if stack is empty
    def is_empty(self):
        return self.top is None

    # Display stack
    def display(self):
        temp = self.top
        if temp is None:
            print("Stack is empty")
            return
        print("Stack elements:")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.nextt
        print("None")


# ---- Driver code (sample execution) ----
s = Stack()
s.push(10)
s.push(20)
s.push(30)
s.display()

print("Top element:", s.peek())

s.pop()
s.display()