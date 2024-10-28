#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include "linearProbing.h"

using namespace std;

int nextPrime( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings


template <typename HashedObj>
class QuadraticHashTable
{
  public:
    explicit QuadraticHashTable( int size = 101 ) : array( nextPrime( size ) )
      { makeEmpty( ); collisions = 0; }

    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & entry : array )
            entry.info = EMPTY;
    }

    bool insert( const HashedObj & x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ].element = x;
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }
    
    bool insert( HashedObj && x )
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        array[ currentPos ] = std::move( x );
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        if( ++currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }

    bool find( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if ( !isActive( currentPos )){
            return false;
        }
        cout << "Found: " << array[currentPos].element.getValue(); 
        cout << " at " << currentPos << endl;
        return true;
    }

    int getCollisions(){ return collisions; }

    enum EntryType { ACTIVE, EMPTY, DELETED };

  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj{ }, EntryType i = EMPTY )
          : element{ e }, info{ i } { }
        
        HashEntry( HashedObj && e, EntryType i = EMPTY )
          : element{ std::move( e ) }, info{ i } { }
    };
    
    vector<HashEntry> array;
    int currentSize;
    int collisions;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }

    int findPos( const HashedObj & x ) 
    {
        int offset = 1;
        int currentPos = myhash( x );
        // function: (h1(k) + i^2) mod M
        //            Quadratic probing
        // Input: 
        // Output:
        // Author: Markus Bernal
        // Date: 10/28/2024

        while( array[ currentPos ].info != EMPTY &&
               array[ currentPos ].element != x )
        {
            collisions += 1;
            currentPos += offset*offset;  // Compute ith probe
            currentPos = currentPos % array.size();
            offset += 1;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    void rehash( ) {
        
        vector<HashEntry> oldArray = array;

            // Create new double-sized, empty table
        array.resize( nextPrime( 2 * oldArray.size( ) ) );
        for( auto & entry : array )
            entry.info = EMPTY;

            // Copy table over
        currentSize = 0;
        for( auto & entry : oldArray )
            if( entry.info == ACTIVE )
                insert( std::move( entry.element ) );
    }

    size_t myhash( const HashedObj & x ) const
    {
        static hash<HashedObj> hf;
        return hf( x ) % array.size( );
    }
};

#endif
