
# Iterator
This iterator, called Scan, fetches all of the tuples from a file, getting the tuples in the order that they are stored in the file.

The data files used by this iterator have the following properties:
>_a file is a sequence of N pages numbered 0..N-1_
>_a page contains a header and a sequence of M tuples, numbered 0..M-1_
>_a tuple is a sequence of characters, terminated by '\0' (i.e. a C string)_

A page is a 1024-byte block. (see Page.h for details)
>_a header consisting of a 4-byte counter followed by an array of 63 offsets_
>_an array of bytes, containing tuple strings_

The iterator has a main program which works as a tuple scanner. The main() function for the scanner takes a file name as a command-line argument, opens the file, starts the iterator and then fetches and prints all of the tuples in the file. The scanner also accesses the Scan data structure to print out the current page and current tuple number in the page of the fetched tuple.

# Run
If you run the make command, it will produce an executable file called scanner, which you could use to try to read the tuples from the test files using e.g.
```shell
$ ./scanner tests/t3
```
At this stage, the only output you'll get is "Cannot start scan". Once you have correctly implemented the iterator, you'll see the tuples instead.

Note that the data files are contained in a sub-directory called tests.
