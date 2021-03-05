#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>


/*
   The DynamicArray class serves as a linear container of items. Just like a
   Python list, there is a first, a second, a last, and so on. This means that
   the list is ordered but not necessarily sorted. The DynamicArray supports
   access of items with the square bracket indexing operators [] and has common
   push_back/pop_back functionality. The DynamicArray is templated and can
   therefore contain any type of data.

   The data is stored internally within an array allocated on the heap. As the
   array fills, we dynamically allocate a new, bigger array and copy the
   contents over to it.
*/
template <typename T>
class DynamicArray {
private:
  //////////////////////////////
  // Private Member Variables //
  //////////////////////////////

  T* data;          // The pointer to the array data
  int arrSize;      // Represents the number of items stored within the DA
  int arrCapacity;  // The size of the underlying array that holds our data

  //TODO: List any additional private member variables you want here

public:

  //////////////////
  // Constructors //
  //////////////////

  /*
     The default constructor allocates a new array with a capacity of 8 and the
     array is to be considered empty.
  */
  DynamicArray() {
    // TODO: Initialize member variables
    arrSize = 0;
    arrCapacity = 8;
    data = new T[arrCapacity];
  };



  /*
     This constructor takes in an initial size which represents the number of
     items the DynamicArray will hold immediately. Note that this does not
     represent the capacity, it represents actual items that are contained
     within the DynamicArray. Since we don't specify a default value, those
     items just keep their junk/garbage/uninitialized values. To support growth
     potential, we set the capacity to be double the initial size. We therefore
     allocate a new array that has a capacity twice that of the initial size.

     initialSize - The initial size (not capacity) of the DynamicArray
  */
  DynamicArray(int initialSize) {

    if (initialSize > 0){
            arrCapacity = initialSize * 2;
            data = new T[arrCapacity];
            arrSize = 0;
    }

};



  /*
     This constructor takes in an initial size which represents the number of
     items the DynamicArray will hold immediately. Note that this does not
     represent the constructor, it represents actual items that are contained
     within the DynamicArray. Each value in the Dynamic Array would take on the
     value of the item passed in as defaultValue. To support growth potential,
     we set the capacity to be double the initial size. We therefore allocate
     a new array that has a capacity twice that of the initial size.

     initialSize  - The initial size (not capacity) of the DynamicArray
     defaultValue - The value to be assigned to the first initialSize items
  */
  DynamicArray(int initialSize, T defaultValue) {
    if (initialSize > 0){
            arrCapacity = initialSize * 2;
            data = new T[arrCapacity];
            data[0] = defaultValue;
            arrSize = 1;
    }

};




  /*
     This "copy constructor" takes in a reference to another DynamicArray. We
     are to copy the contents of that array into this newly created object.
     Therefore this constructor allocates a new array with a matching capacity
     and copies the contents of the provided DynamicArray into the new local
     array. Note that we treat the input array (daToCopy) as a const reference
     (&) so that we confirm that the provided array will not be modified and to
     gain the optimization benefit of passing by reference rather than creating
     an extra, intermediate copy.

     daToCopy - The provided array that we are intended to copy
  */
  DynamicArray(const DynamicArray<T> &daToCopy) {

    // Initialize member variables w.r.t. daToCopy
    arrSize = daToCopy.arrSize;
    arrCapacity = daToCopy.arrCapacity;

    // Allocate memory for array data
    data = new T[arrCapacity];

    // Copy contents of daToCopy into local array data
    for(int i=0; i < arrSize; i++)
      data[i] = daToCopy.data[i];
  }


  ////////////////
  // Destructor //
  ////////////////

  /*
     This destructor serves to de-allocate the heap-stored array so that the
     operating system can reclaim and use it with future calls to "new". The
     destructor is called immediately and automaticallywhen the object loses
     scope.
  */
  ~DynamicArray() {
    // Free up (delete) the heap-allocated data
    if (data != NULL)
      delete[] data;
  }



  //////////////////////////
  // Overloaded Operators //
  //////////////////////////

  /*
     This is the "assignment" operator. It allows us to assign the contents of
     one DynamicArray to another. For example, consider the following code:
        DynamicArray<int> da1;
        da1.push_back(1);
        da1.push_back(2);

        DynamicArray<int> da2;
        da2.push_back(3);

        da1 = da2; // This invokes the assignment operator to replace the
                   // original contents of da1 with a copy of the contents
                   // of da2

     daToAssign - The DynamicArray that we want to copy onto the current DA
  */
  DynamicArray<T>& operator= (const DynamicArray<T> &daToAssign) {
    // Free up (delete) the previous heap-allocated data
    delete[] data;

    // Initialize member variables w.r.t. daToAssign
    arrSize = daToAssign.arrSize;
    arrCapacity = daToAssign.arrCapacity;

    // Allocate memory for array data
    data = new T[arrCapacity];
    // Copy contents of daToAssign into local array data
    for(int i=0; i < arrSize; i++)
      data[i] = daToAssign.data[i];

    // Return the current object itself. "this" is a keyword that acts as a
    // pointer to the current object. By dereferencing (*) "this", we get the
    // actual value of the object itself.
    return *this;
  }



  /*
     This is the "subscript" operator that allows us to easily index into and
     return the items within the inner heap-allocated array. You pass in the
     index and receive the value from the internal array. This works like so:
         DynamicArray<int> da;
         da.push_back(10);
         da.push_back(20);
         da.push_back(30);

         int middleVal = da[1];

     We return a reference (return type: "T&") to the item so that we can also
     change that value through assignment. Consider the following:
         DynamicArray<int> da;
         da.push_back(10);
         da.push_back(50);
         da.push_back(30);

         da[1] = 20;

     index - An integer representing the position of the item to return
  */
  T& operator[] (int index) {
    return data[index];
  }



  /////////////////////////////////
  // Additional Member Functions //
  /////////////////////////////////

  /*
     The push_back method takes an item and adds it to the collection. This
     will add it to the internal array, expanding to a larger array if there
     is not enough room.

     item - The item the user wishes to add to the collection.
  */
  void push_back(T item) {

      if (arrSize + 1 >= arrCapacity){
        grow();
        std::cout<< "GROW" << std::endl;
      }
      if(arrSize < arrCapacity){
        data[arrSize] = item;
        arrSize++;
      }
  }



  /*
     The pop_back method is invoked to inform us that the user no longer wants
     the last item in the container any longer. Consider this removing the last
     item in the DynamicArray.
  */
  void pop_back() {

    if(arrSize > 0){
            arrSize -= 1;
    }
};



  /*
     This size method returns the size of the DynamicArray. That is, the number
     of items that are stored within the DynamicArray container.
  */
  int size() {
    return arrSize; // <-- FIXME: Change this to reflect actual size
  }



  /*
     The capacity method returns an integer representing the current size of
     the internal heap-allocated array. This does not represent the number of
     items stored within the DynamicArray container, it represents the total
     number of items that can be stored within it before it is necessary to
     grow the internal array again.
  */
  int capacity() {
    return arrCapacity; // <-- FIXME: Change this to reflect actual capacity
  }



  /*
     The clear method empties the container. If the user calls .size() after
     this, then it would return zero.
  */
  void clear() {
    arrSize = 0;
      }



  /*
     The reverse method reverses the order of the contents of the DynamicArray.
     Consider the physical representation below:
        Before a call to reverse
        Inner Array Data: [1, 2, 3, 4, 5, ?, ?, ?]  <-- ? represents junk
        arrSize: 5
        arrCapacity: 8

        After a call to reverse
        Inner Array Data: [5, 4, 3, 2, 1, ?, ?, ?]  <-- ? represents junk
        arrSize: 5
        arrCapacity: 8
  */
  void reverse() {
        if (arrSize > 1){
            T* reversearr = new T [arrCapacity]; //reversearr = reverse array
            int reversepos= 0; // reversepos = reverse position
            for(int i = arrSize -1; i >= 0; i-- ){
                reversearr[reversepos] = data[i];
                reversepos++;
            }
        delete[] data;
        data = reversearr;
        }
  };
    void grow(){
      T* data2 = new T [arrCapacity * 2]; //Make a new array
      //std::cout<< "ARRAY IS DOUBLE THE CAPICITY" << std::endl;
      for(int i = 0; i < arrSize; i++){
        data2[i] = data[i]; //copy the new data to data2
        //std::cout <<"COPY" << std:: endl;
      }
    delete[] data; //Delete the original array
    data = data2;// SCREW DATA2, DATA IS NOW THE CAPTAIN (assign the name data to equal data2)
    arrCapacity = arrCapacity * 2; //double the arrCapacity number

  };//

private:
  //////////////////////////////
  // Private Member Functions //
  //////////////////////////////

  //TODO: Provide any private methods (helper functions) you want here.
  //      Note that these are NOT necessary but you can add things here
  //      if you think something would be useful to your implementation.


};


#endif
