```
Contents 
Assignment 1: Solvability of the NxN sliding tile puzzle
1. 1. Input format
2. In the case of incorrect input
3. In the case of correct input
4. Design
5. Marking
6. Submission
7. Testing
```
# Solvability of the NxN sliding

# Tile puzzle

The sliding tile puzzle is a game that requires you to move tiles on a board. The board is
NxN, and there are N-1 tiles numbered from 1..N-1 that occupy the board. There is hence 1
location on the board that is empty (referred to as a blank).

There is some (arbitrary) start configuration of the numbered tiles on the board. Starting with
this configuration, the aim is to move tiles until some chosen goal configuration is reached,
and to do this in the least possible number of moves. You may only move a tile into the blank
if the tile neighbours the blank. Moves can be only be in the horizontal and vertical directions
(not diagonal).

The sliding-tile puzzle also has other names, such as the 8 Puzzle (for the special case of a
3x3 board) or 15 Puzzle (a 4x4 board) and so on. Sometimes the name N Puzzle is used
(indicating an NxN board).

In this assignment you are asked to write a C program that determines whether a given puzzle
is solvable. (Note that you do not have to actually solve the puzzle.)

There are some conditions that you should strictly adhere to:

```
1. the program reads text from stdin with a format described below (we will be auto-
testing your program with our input so you must conform to this format)
2. your program should be able to handle any sized board, starting with 2x
note that the size of the board is determined by the number of tiles on the input
3. if the input is correct and the goal configuration is:
reachable from the start configuration, your program should generate the output
text solvable (to stdout )
not reachable from the start configuration, your program should generate the
output text unsolvable (to stdout )
4. if the input is not correct, your program should generate an error message (to stdout )
5. if a system call fails in your program, the program should generate an error message (to
stderr )
6. design and programming restrictions:
you are not allowed to use any arrays
you are not allowed to use linked lists/trees/graphs
you should use an ADT to represent the board and operations on the board
```
## Input format

Two lines of text on _stdin_ specifies the start and goal configurations, read from left to right,
top to bottom. Each line consists of a sequence of integers, separated by any number (>0) of
blanks and/or tabs, that represent the tile numbers, and a single letter _b_ to represent the blank
space on the board. These integers should of course be in the range 1..N-1 where the board is
of size NxN. The first line specifies the start board, the second line the goal board. For
example:

```
9 12 5 4 2 b 7 11 3 6 10 13 14 1 8 15
1 2 3 4 5 6 7 8 9 10 11 12 13 14 b 15
```
represents a sliding-tile puzzle on a _4x4_ board with the tiles initially placed on the board as
shown in the image at the top of page. The goal configuration has the tiles ordered row by
row.

## In the case of incorrect input

Checking the correctness of each configuration is vital. For example, an input line may not
represent an NxN board, or the blank may be missing, or one or more of the tile numbers 1..N
may be missing, or the 2 boards may not be the same size or the input contains something
other than a number or _b_. There may be more possibilities.

If the configuration is erroneous, your program must generate an appropriate error message
(to _stdout_ ). Note that it is possible to have more than one error, and in that case you only need
to generate a single error message. For example, consider the configuration _1 2 b 1_. There are
2 errors in this configuration: the tile 3 is missing, and the tile 1 is duplicated. It does not
matter which error is detected by your program, just as long as the error is correct. When an
error is detected and reported, your program should exit gracefully, with status
_EXIT_FAILURE_. The text you use in error messages should be informative, but please keep it
brief.

## In the case of correct input

If the input is correct, the program should write the following 3 lines to _stdout_ :

```
the text start: followed by the start configuration
the text goal: followed by the goal configuration
the text solvable or unsolvable as appropriate
```

The output for the 4x4 game above is for example:

```
start: 9 12 5 4 2 b 7 11 3 6 10 13 14 1 8 15
goal: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 b 15
solvable
```
The output for a game on a 2x2 board that happens to be unsolvable is:

```
start: 2 1 3 b
goal: 1 2 3 b
unsolvable
```
If the input is correct the program should exit with _EXIT_SUCCESS_.

## Design

You should make an ADT to implement the puzzle. The _client_ , which is the main program,
calls functions in the ADT to read the input, check for correctness and determine solvability.
The interface between the client and the ADT is a header file.

## Marking

Marks will be deducted if you fail any of our tests for incorrect input, or incorrectly determine
the solvability of the puzzle. Marks will also be deducted for poor design (e.g. not using an
ADT), poor programming practice or violating any of the rules above.

The assignment is worth 10 marks.

## Submission

You should submit exactly 4 files:

```
1. a Makefile that generates the executable puzzle (you should use the dcc compiler)
2. the C source code of the ADT (call it boardADT.c )
3. the header file of the ADT ( boardADT.h )
4. the main program ( puzzle.c )
```
Before submission make sure your _Makefile_ is working correctly: the command _make_ should
generate the target executable _puzzle_ using the 3 source files _boardADT.c_ , _boardADT.h_ and
_puzzle.c_.

To submit, simply click on the _Make Submission_ button above. You should submit exactly 4
files: _Makefile_ and the 3 source files.

## Testing

The following describes a simple _test harness_ (is it's called) that will help you organise and
run your test cases. The basic idea is to separate your test cases into good boards that are
solvable, those that are unsolvable, and bad boards. A test case is simply a file containing
puzzle input of course. Carry to the following steps:


STEP 1 Create a directory, Tests say, to house all your test input. Each file in this directory is a
test case. Name the files systematically, so for example, the following input

```
1 2 3 1
1 2 3 b
```
could be called bad01.inp. Another 'bad' input file would be called bad02.inp.
Likewise, create files sol01.inp , sol02.inp etc to represent solvable boards, and
unsol01.inp , unsol02.inp etc for unsolvable boards. All these files are in the Tests
directory. You could also make the names even more meaningful by coding in the board
size into the name: e.g the prefix of all the 2x2 'bad' boards could be bad2 , and of 3x
boards bad3 etc, and similarly for sol and unsol.
STEP 2 In the parent directory, which should contain your puzzle executable, create a file called
Testrun containing the following shell script

```
#!/bin/sh
PROG=./puzzle
case $1 in
1) T=Tests/bad* ;;
2) T=Tests/sol* ;;
3) T=Tests/unsol* ;;
esac
if [ A$T != A ]
then
for i in $T
do
echo ================= $i ==================
$PROG < $i
done
else
echo Usage $0 "[1|2|3]"
fi
```
which assumes you have used my naming convention in part 1.
STEP 3 To run all the bad-board tests in one go, simply run the corresponding script:

```
sh Testrun 1
```

and similarly sh Testrun 2 and sh Testrun 3.

The advantage of the separating into different kinds is that is makes it easy to see that the
program is behaving correctly for all the tests with the same kind of input (bad, solvable and
unsolvable). It is also easy to add new test input to the _Tests_ directory.

You can make this script much fancier of course. You could for example add a 4th case to test
bigger boards if that is where you want to focus on at a particular stage in the development.

```
Contents
1. Tutorial for the Sliding-Tile
Puzzle
1. First set of exercises
2. Solvability
1. Second set of exercises
```
# Tutorial for the Sliding-Tile Puzzle

In the N^2 sliding-tile puzzle, there are N^2 squares, and N^2 -1 tiles, numbered from 1 to N^2 -1.
These tiles are placed on the board leaving one square blank. Given some start configuration
of numbered tiles on the squares, the aim is to move tiles, one at a time, until some given goal
configuration is reached. A move involves placing one of the tiles that neighbours the blank
square into that space, excluding the tile that was previously on the square. (You can only
move in the horizontal and vertical directions of course.) The aim is to reach the goal
configuration with a minimum number of tile moves.

The puzzle was first created in the late 19th century. It became a craze in the USA in 1880,
and 'everybody' played it. Here's a cartoon about the difficult in choosing the republican
candidate at the 1880 U.S. presidential elections.

## First set of exercises


1. Consider a 2^2 puzzle.
a. How many different possible configurations of tiles are there?
b. Generate all possible configurations given:
i. start configuration
1 2
3
ii. start configuration
2 1
3
iii. A configuration is called reachable if it can be reached from a given start
configuration. How many reachable configurations were there from each of
the two start configurations, and how does that related to the total number
in the puzzle?
c. Given the start configuration:
1 2
3
and goal configuration
1 3
2
can you solve the puzzle?
2. How many different possible configurations of tiles are there in the:
a. 32 puzzle?
b. 42 puzzle?
c. n^2 puzzle?
3. Given the 3^2 puzzle goal configuration:
1 2 3
8 4
7 6 5
and start configuration:
8 3 5
4 1 6
2 7
draw the solution tree that represents every configuration by a vertex and every move
by an edge. Do not repeat configurations, and go no deeper than level 3 (where level 0
is the root vertex).

# Solvability

It is not always possible to reach a given goal state from some given start state. This was
realised very soon after the game was 'invented' (about 1879).

There is an algorithm to determine whether two states are reachable. This algorithm involves
differentiating between even-sized boards, 2^2 , 4^2 , 6^2 etc, and odd-sized boards, 3^2 , 5^2 etc.

We also need to define the **disorder** of a tile, and of a board:


the disorder of a tile is the number of lower-numbered tiles that appear after it in left-
right top-down order
the disorder of a board is:
odd-sized board : the sum of the tile disorders
even-sized board : the sum of the tile disorders plus the row number of the blank
(row numbers start with 1)

Finally we can define the **parity** of a board:


the parity is even if the board disorder is even
the parity is odd if the board disorder is odd
A goal board is reachable from a start board if and only if both boards
have the same parity.


For example, if you have a goal board:

```
1 2
3
```
we note that:

```
tile '1': disorder = 0 (in its correct position)
tile '2': disorder = 0 (correct position)
tile '3': disorder = 0 (correct position)
blank is in row 2
```
so the disorder of this board is 0+0+0+2, hence the board has even parity.

If you have the start board:

```
3 2
1
```
the disorders are:

```
tile '3': disorder = 2 (tiles '2' and '1' appear after it)
tile '2': disorder = 1 (tile '1' appears after it)
blank is in row 2
tile '1': disorder = 0
```
so the start board has disorder 2+1+2+0 = 5. The parity of this board is hence odd, which is
different to the parity of the goal board, hence you cannot reach the goal board from this start
board. Hence the game cannot be solved.

A different start board:

```
1
3 2
```
yields 1+0+1+0 = 2, where the 1's come from the blank and tile 3. The disorder is hence even,
which is the same parity as the goal board, hence you can reach that goal board from this
board, and the game is solvable.

Another example, this time a 3x3 goal board:

```
1 2 3
4 5 6
7 8
```
This board is odd-sized, and we can see all tiles are in the correct position, hence the parity is
even.

Computing the disorder of the following start board:

```
8 7 6
5 4 3
2 1
```

yields disorder = 7+6+5+4+3+2+1+0 = 28. The parity of the start and goal boards are both
even, hence the game is solvable.

Sometimes board configurations are written sequentially: e.g. the previous start board can be
written _8 7 6 5 4 3 2 1 b_ , where _b_ is the blank square and the rows are written sequentially
from top to bottom.

## Second set of exercises

```
1. a. Show that the disorders of all the boards reachable from the start board 1 2 3 b
are even.
b. Show that the disorders of all the boards reachable from the start board 2 1 3 b
are odd.
2. a. What is the parity of the following goal board?
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15
b. Is that goal board reachable from the following start board?
1 2 3 4
5 6 7 8
9 10 11
12 13 14 15
If the goal is reachable, how many moves are required?
c. Is that goal board reachable from the following start board?
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15
If the goal is reachable, how many moves are required?
3. Is the puzzle with start board 1 6 7 2 5 8 3 4 b and goal board 1 2 3 8 b 4 7 6 5
solvable?
```





