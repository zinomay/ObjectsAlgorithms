# Unit 1 Assignment 2
from heap_priority_queue import HeapPriorityQueue
from probe_hash_map import ProbeHashMap
from binarySearchTree import binarySearchTree
class Color:
    def __init__(self, color, value ):
        self._color = color
        self._value = value

    def __eq__(self,other):
        return (self._color == other)
    def __lt__(self,other):
        return (self._color < other)
    def __gt__(self,other):
        return (self._color > other)

# Driver 
if __name__ == "__main__":
   
  # ----------------- Part A -----------------
  colors = [
    ("orange",4), ("blue"   ,7), ("pink"  ,5), ("black" ,6), ("green" ,8), 
    ("yellow",1), ("brown" ,2), ("red"   ,3), ("purple" ,10), ("white" ,9)
    ]

  # Objects used for binary search tree
  orange = Color("orange",4)
  blue   = Color("blue",7)
  pink   = Color("pink",5)
  black  = Color("black",6)
  green  = Color("green",8)
  yellow = Color("yellow",1)
  brown  = Color("brown",2)
  red    = Color("red",3)
  purple = Color("purple",10)
  white  = Color("white",9)
  color_obj_list = [ orange, blue, pink, black,green,
  yellow, brown, red, purple, white ]

  # 1) Binary Max heap using rank as priority
  heap = HeapPriorityQueue()
  for color in colors:
    # Tuples, 0: color, 1: rank
    # Heap priority queue uses key for priority
    heap.add(color[1],color[0] )
   
  # Heap
  # 1) Search for rank 5
  print(heap.find(5))
  # 2) Search for rank 2
  print(heap.find(2))
  # 3) Search for rank 11
  print(heap.find(11))
  
  # 2) HashTable
  # Default size is 11
  hashTable = ProbeHashMap()
  for color in colors:
    hashTable.insert(color[0],color[1])
  
  # Search HashTable
  # 1) Search for "prink"
  print(hashTable.search("pink"))
  # 2) Search for "green"
  print(hashTable.search("green"))
  # 3) Search for "grey"
  print(hashTable.search("grey"))

  # 3) Binary Search Tree
  binaryTree = binarySearchTree(orange)
  for i in range(1,len(color_obj_list),1):
    binaryTree.insert(color_obj_list[i])
  
  print ("Search for white. Rank is ",binaryTree.find("white"))
  print ("Search for black. Rank is ",binaryTree.find("black"))
  print ("Search for violet. Rank is ",binaryTree.find("violet"))

  # ----------------- Part B -----------------
  with open('PatriotAct.txt') as iFile:
    file_lines = iFile.readlines()
    word_count = {}
    for line in file_lines:
      line = line.replace(',','') 
      line = line.replace('-','') 
      line = line.replace("'s",'') 
      line = line.replace('.','')
      line = line.replace('(','')
      line = line.replace(')','')
      line = line.replace(':','')
      for word in line.split():
        if word in word_count:
          word_count[word] = word_count[word]+1
        else: 
          word_count[word] = 1 

    file_heap = HeapPriorityQueue() 
    file_table = ProbeHashMap()
    #for key,value in word_count.items():
    #    file_heap.add(value,key)
    #    file_table.insert(key,value)
    
    #file_heap.find_word("terrorists")
    #file_table.search("terrorists")