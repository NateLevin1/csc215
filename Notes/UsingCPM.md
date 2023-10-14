# Chapter 5: Using CPM (Organization Of CP/M)

-   "driver routines" used to access hardware, must be supplied before CPM can run

## Disk and I/O access primitives

-   Loader used to "warm start" the OS
-   Uses the currently selected disk drive
-   Doesn't make changes in the logical to physical device mapping as defined by the contents of the IOBYT
-   Warm start used to reload CP/M or after aborting a program
-   The CBIOS is a region of disk that has the the complete I/O device access primitives in CP/M, dependent on your machine. These are vectors.
    -   See pages 46-48 for a diagram of how this works
-   Each vector is a three byte jump - like JMP BOOT, JMP WBOOT.
-   BOOT is the cold start routine - shows a login message etc, WBOOT is the warm start routine - just to reload w/same IOBYT.
-   Console Command Processor (CCP) is the "command line", that gives you the `>` prompt.
-   Other vectors are used for I/O communication and disk access

Very funny:

> An operator is still required to put the right disk in the right drive, right side up. Humans can’t all be replaced by machines.

-   All that is required to adapt CP/M to a new computer is to provide the loader in PROM and the 15 routines to be accessed through these vectors.

## BDOS: The Basic Disk Operating System

-   Some basic info on how disks work internally in CP/M
-   Programs can read files into RAM, write to them from RAM, and delete them.
-   The operator can also read&write files with the `PIP` and `CCP` commands
-   File read errors look like `BDOS ERR ON B: BAD SECTOR`
-   If you get a `BDOS ERR ON R: SELECT` error, you should restart immediately - the program is lost

## CBIOS: The Customized Basic Input/Output System

-   All the adapting of CP/M to work specifically on your machine is in the CBIOS
-   CBIOS and BIOS will be used interchangeably
-   The CBIOS contains all the drivers and handles the IOBYT

Here is a diagram of the memory map of CP/M:
![Memory map](https://i.ibb.co/7r3vNbN/image.png)

Here is a diagram of how the IOBYT works:

![IOBYT diagram](https://i.ibb.co/F7rfNmM/image.png)

-   The program `STAT VAL:` lists the devices. The names are holdovers from original versions of CP/M
-   The `SUBMIT` program allows you to write a list of commands to disk that will be executed in order.

## CCP: The Console Command Processor

-   This is the CLI of CP/M - the word CLI must not have been standardized yet?
-   The CCP prompt is the drive symbol followed by a `>`
-   A command is either the name of a built in function or the filename of a .COM file (binary program to run)
    -   e.g. B:MYFILE.COM will run the program MYFILE.COM on drive B
    -   Options to .COM programs are specified like on unix, separated by spaces
        -   CCP sets up a default file control block containing the properly formatted names of one or two files specified in the command line and a RAM buffer containing the entire text of the command line - somewhat like `argv`

## CPM's Built In Functions

![Figure listing all of CPM's built in functions, both transient and resident](https://i.ibb.co/zGKTXs1/image.png)

### Resident Functions

-   Always loaded into RAM, unlike transients that are stored on disk and then loaded into RAM when needed
-   E.g. `DIR` which lists all of the files on the current disk. Also can be used to verify that a file exists `DIR FILENAME.EXT` or list the contents of a different disk `DIR A`
    -   `ERA` uses the same options format as `DIR`

Fun historical note:

> “ERA” stands for “erase,” of course, and has nothing to do with political activities.

The author is referring to the Equal Rights Act, which was a major political issue at the time of the book's writing. Nowadays, it isn't mentioned much.

-   `REN` is used to rename files - `REN B:GOODPROG.COM=B:TEST.COM`
-   `TYPE` is used to print the contents of a file to the screen - `TYPE B:TEST.COM`

    -   Like `cat` on unix

-   Ctrl+P will toggle echoing of all output to the line printer
-   Ctrl+S pauses/unpauses execution of the current program

### Transient Utilities

-   `STAT` is most often used to see how much space is left on a disk

    -   `STAT VAL:` shows all IO devices, `STAT DEV:` shows the IOBYT
    -   Can also be used to change IOBYT, e.g. `STAT LST:=LPT:`

-   Other transient utilities will be discussed in later chapters

## User Programs

-   No real difference in form between a “CCP transient command” and a user program.
    -   Transient utilities are really just .COM files on disk
-   We will run our own programs in the same way as the transient ones
-   CCP will parse the command line for us in our programs:
    -   If it contains one or two file names, will load them into the default file control block.
    -   Other entries in the command line will be saved for our program in TBUFF.

# Chapter 6. Interfacing With CP/M

-   All I/O requests go through the BDOS call vector at memory offset 5
-   Allows many different types of I/O - e.g. writing a single character or reading a a whole line
-   It's best to limit use of BDOS functions to any of the following:
    ![BDOS functions](https://i.ibb.co/rdsjYJ2/image.png)
