# [Altair Manual Part 1](https://ubuntourist.codeberg.page/Altair-8800/part-1.html)

## INTRODUCTION

-   Uses Intel 8080 chip
-   78 machine language instructions
-   Part 1 is about computers in general, part 2 and 3 are about the ALTAIR 8800 in general. Part 4 is a manual on all of the instructions.

## A. LOGIC

-   George Boole created the system of logic (Boolean algebra) that is used by all computers. We learned this last year.
-   On=true, off=false
-   AND = **all** conditions true
-   OR = **any** conditions true
-   NOT = reverse value of condition

| In              | Out   |
| --------------- | ----- |
| False AND FALSE | False |
| False AND True  | False |
| True AND False  | False |
| True AND True   | True  |

This works like a circuit where OFF is a break of the circuit and ON is a connection.

False=0, True=1.

-   Using this, you can form a truth table (we did this last year)

AND:

| A   | B   | Out |
| --- | --- | --- |
| 0   | 0   | 0   |
| 0   | 1   | 0   |
| 1   | 0   | 0   |
| 1   | 1   | 1   |

OR:

| A   | B   | Out |
| --- | --- | --- |
| 0   | 0   | 0   |
| 0   | 1   | 1   |
| 1   | 0   | 1   |
| 1   | 1   | 1   |

NOT:

| A   | Out |
| --- | --- |
| 0   | 1   |
| 1   | 0   |

## B. ELECTRONIC LOGIC

-   The basic AND, OR, and NOT gates are created with circuits using transistors
-   They can be combined with each other to form more complex circuits
-   NAND = NOT AND

| A   | B   | Out |
| --- | --- | --- |
| 0   | 0   | 1   |
| 0   | 1   | 1   |
| 1   | 0   | 1   |
| 1   | 1   | 0   |

-   NOR = NOT OR

| A   | B   | Out |
| --- | --- | --- |
| 0   | 0   | 1   |
| 0   | 1   | 0   |
| 1   | 0   | 0   |
| 1   | 1   | 0   |

-   XOR = Exclusive OR (only one or the other, not both)
-   Also called a binary adder

| A   | B   | Out |
| --- | --- | --- |
| 0   | 0   | 0   |
| 0   | 1   | 1   |
| 1   | 0   | 1   |
| 1   | 1   | 0   |

-   Two NANDs can be combined to form a flip-flop, acing as memory

## C. NUMBER SYSTEMS

## D. THE BINARY SYSTEM
