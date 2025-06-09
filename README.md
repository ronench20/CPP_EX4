# CPP_EX4
### In this project, I implemented a dynamic container that can hold a collection of objects of any type, using templates.
### Also, I implemented iterators for the container, which allow iterating over the elements in the container.

## compilation
to compile the project, you can use the following command:
```bash
make                #compile the project
make test           #compiles the tests executable and runs the tests
make Main           #runs the main program
make valgrind       #runs valgrind on the main program
make valgrind-test  #runs valgrind on the tests
make clean          #Deletes all .o files
```

### The iterators that I implemented are:
- "AscendingOrder" —This iterator sorts the elements in ascending order.
- "DescendingOrder" —This iterator sorts the elements in descending order.
- "MiddleOutOrder" —This iterator sorts the elements by that it starts from the middle of the container and goes outwards.
- "Order" —This iterator sorts the elements in the order they were added to the container.
- "ReverseOrder" —This iterator sorts the elements in reverse order of the order they were added to the container.


## Author
- Name: Ronen Chereshnya
- ID: 207304338
- Email: ronen.chereshn@msmail.ariel.ac.il