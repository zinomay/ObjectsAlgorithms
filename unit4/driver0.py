# Author: Markus Bernal
# Date: 10/23/2024
# Unit 4 Assignment 1
# Collisions
# Hash methods : linear probing, quadratic probing, double hashing techniques
# 

# For all three use h1(k) = kmodM as initial hash value to store k
# For quadratic probing, ith value in probe would be (h1(k)+i^2)mod M
# For double hashing, ( h1(k)+i*h2(k) ) mod M,  h2(k) = 1+( k mod( M-1 ) )

if __name__=="__main__":
    # i) confirm correctness of the hashing techniques by testing the insertion and retrieval member functions
    # ii) 1000 insertions on hash table of size 1231
    
