##################################################
#  Part of solution to question 8.9 - Parens
# 
#  Status: INCOMPLETE
##################################################


class DNode:
    def __init__(self, data):
        self.__prev = None
        self.__data = data
        self.__next = None

    def getPrev(self):
        return self.__prev

    def getData(self):
        return self.__data

    def getNext(self):
        return self.__next

    def setPrev(self, node):
        self.__prev = node

    def setNext(self, node):
        self.__next = node


class Stack:
    def __init__(self, data):
        self.__base = DNode(data)
        self.__top = self.__base
        self.__size = 1

    def __len__(self):
        return self.__size

    def push(self, data):
        node = DNode(data)          # Create node for new data
        node.setPrev(self.__top)    # Link to original top
        self.__top.setNext(node)    # Link from original top
        self.__top = node           # Set new top
        self.__size += 1            # Increase stack size

    def pop(self):
        data = self.__top.getData()         # Get original top data
        self.__size -= 1                    # Decrease stack size
        self.__top = self.__top.getPrev()   # Set top to node before top

        if self.__size > 0:
            self.__top.setNext(None)        # Unlink original top

        return data
