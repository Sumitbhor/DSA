import json
from .Shelf import Shelf 
from .Book import Book
class Filemanager:
    def serialize(self, theshelf ):
        datalist = []
        for i in range (0, theshelf.top+1):
            data = {
                "title": theshelf.books[i].title,
                "author": theshelf.books[i].author
            }
            datalist.append(data)
        with open("data.json", "w") as file:
            json.dump(datalist, file)

    def deserialize(self):
        theself = Shelf()
        with open("data.json", "r") as file:
            datalist = json.load(file)
            for data in datalist:
                book = Book(data["title"], data["author"])
                theself.push(book)
        return theself                
        