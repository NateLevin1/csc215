# About CPM: Chapters 3-4

## 3. The CP/M-Based Computer

-   This book assumes you are using CP/M version 1.4, 2.0, or 2.2. We are running version 2.2.

### Logical names and physical entities

-   The CRT is the video display terminal
-   When plugged into the correct port, it becomes the `CON:` logical device
-   Line printer is the `LPT:` device

### Selecting I/O devices

-   Disk drivers are just numbered (`0`, `1`, `2`, etc)
    -   The logical device names for these are `A:`, `B:`, `C:`, etc
-   There are 4 logical I/O devices
    -   `CON:` - the "console"
    -   `LPT:` - the line printer
    -   `RDR:` - general purpose reader
    -   `PUN:` - general purpose writer
-   Programs can control what physical device they are reading from - e.g. `RDR` can receive data from a card reader, paper tape reader, modem.
    -   The bit pattern is stored in IOBYT.
    -   This allows the operator to change the device without changing the program, or the program can change the device without the operator's intervention.
-   In our minimum system we won't change the IOBYT switches — only use CRT: as CON:, and LPT: as LST:.

## What the Operating System Provides

-   This section goes over how CP/M looks to an operator and programmer
-   We will try a few built in commands

### Named File Handling

-   Constraints on the name of a file:
    -   File name up to 8 characters
    -   3 character file type appended
    -   With DIR command, file type is not shown - space-padded to line everything up
-   Example file creation command: `SAVE 0 B:-WORK.001`
    -   This saves an empty file (0 blocks)
    -   The name is `-WORK`
        -   The `-` indicates it is a special file that doesn't contain information
    -   Filetype is `001`
    -   Disk drive is `B:`
    -   This file indicates that disk B is your first working disk (working disk 001)
-   Common Filetypes:

    | Filetype                               | Description |
    | -------------------------------------- | ----------- |
    | Binary program image (Command)         | .COM        |
    | Assembly language source program       | .ASM        |
    | Assembler program output (hexadecimal) | .HEX        |
    | Assembler list output (print)          | .PRN        |
    | Editor input—saved (backup)            | .BAK        |
    | Temporary scratch file                 | .$$$        |
    | Submit command file                    | .SUB        |
    | BASIC language program                 | .BAS        |
    | BASIC compiled program (intermediate)  | .INT        |
    | Fortran source                         | .FOR        |
    | Macro assembler source program         | .MAC        |
    | Relocatable compiler output            | .REL        |
    | Data file                              | .DAT        |

-   It's recommended to name each of disk with this kind of empty file that will create a directory entry to provide identification
-   Programs can create, delete, read, and write to files as well

### Wildcards in file names

-   Like bash - Running `DIR *.COM` will list all files with filetype `.COM`
-   You can also use `?` as a wildcard for a single character - e.g. `??a.001`
-   \*.\* is a wildcard used for all files
    -   For example, `PIP B:=A:*.*` uses the Peripheral Interchange Program to copy all files from disk A to disk B
-   These wildcards can be used throughout the whole OS

### Logical Unit Access

-   Logical units can be used in place of files
    -   E.g: `PIP PUN:=FILENAME.TYP` sends `FILENAME.TYP` to the `PUN:` logical device
-   Chapter 6 will talk about how to do this in code

### Line Editing

-   The stuff you are used to on the command line
-   Instead of ctrl+c to quit entering a command, use ctrl+x
