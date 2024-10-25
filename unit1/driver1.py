########################################################################################
#  Unit 1 Assignment 1 
#  Binary Search Two-way Comparison
#  Author: Markus Bernal
#  Date: 10/22/2024
#  Description: Driver file to compare two implementations of the binary search algorithm
#
#  Input:   No input file 
#  Output:  No output file. Console displays results of iterations between algorithms
#
########################################################################################


def binary_search(arr, x):
  # Description: binary search with two comparisons per iteration with an early
  #              return condition. 
  #              Time Complexity O(logN)
  # Input:  arr is expected to be an array of integers, x would be the value being searched for
  # Output: Prints iterations and the 
  low, high = 0, len(arr)-1
  iterations = 0
  while low <= high:
    iterations += 1
    mid = (low+high) // 2
    if arr[mid] < x: 
      low = mid+1
    elif arr[mid] > x:
      high = mid -1
    else:
      print("Two-way comparison binary search iterations: ",iterations)
      print("Total Comparisons: ", 2*iterations)
      return mid
  return -1 # Not found

def new_binary_search(arr, x):
  # Description: Binary search with one comparison. 
  #              Time Complexity O(logN)
  # Input: array of integers, x - value being searched for
  # Output:
  low, high = 0, len(arr)-1
  iterations = 0
  mid = (low+high) // 2
  while low < high:
    iterations += 1
    mid = (low+high) // 2
    if arr[mid] < x:
      low = mid+1
    else:
      high = mid
  print("One-way comparison binary search iterations: ",iterations)
  print("Total Comparisons: ", 2*iterations)
  
  # return position of value
  if(arr[mid] == x):
    return mid
  else:
    return -1 # Not found

if __name__ == "__main__":

  # Creating sorted array of size N
  sorted_arr = []
  for i in range(0,100001,1):
    sorted_arr.append(i)

  # Comparing binary search functions 
  binary_search(sorted_arr, 50000)
  new_binary_search(sorted_arr,50000)

  ########################################################################################
  # Answers
  # 1) Count of comparisons of the original binary_search algorithm is 2 per iteration. 
  #    Worst Case scenario would be 2*logN comparisons; however, this algorithm allows for
  #    early termination.
  # 
  # 2) Count of comparisons for the new binary_search algorithm is 1 per iteration, making
  #     the comparison count as logN. The only drawback with this algorithm is that is doesn't
  #     allow for early termination. This means the runtime will always be logN even if
  #     the number has been found
  #    
  ########################################################################################
   