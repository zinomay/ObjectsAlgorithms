######################################
# Author: Markus Bernal
# Date: 10/22/2024
######################################


def binary_search(arr, x):
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
      print("iterations: ",iterations)
      return mid
  return -1 # Not found

def new_binary_search(arr, x):
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
  print("iterations: ",iterations)
  if(arr[mid] == x):
    return mid
  else:
    return -1 # Not found



if __name__ == "__main__":
  sorted_arr = [0,1,2,3,4,5,6,7,8,9]
  binary_search(sorted_arr, 2)
  new_binary_search(sorted_arr, 2)