

class binarySearchTree:

    # Node class Abstract class meant to be overridden
    class Node:

        def __init__(self):
            raise NotImplementedError()
        def __eq__(self,other):
            raise NotImplementedError()
        def __nq__(self,other):
            raise NotImplementedError()
        def __lt__(self,other):
            raise NotImplementedError()
        def __gt__(self,other):
            raise NotImplementedError()

    def __init__( self, node):
        self._left  = None
        self._right = None
        self._node = node

    def insert(self, node):
        if node < self._node:
            if self._left is None:
                self._left = binarySearchTree(node)
            else:
                self._left.insert(node)
        else:
            if self._right is None:
                self._right = binarySearchTree(node)
            else:
                self._right.insert(node)
    
    def find(self, color): 
        if color < self._node:
            if self._left is None:
                return -1
            else:
                return self._left.find(color)
        elif color > self._node:
            if self._right is None:
                return -1
            else:
                return self._right.find(color)
        else:
            return self._node._value
