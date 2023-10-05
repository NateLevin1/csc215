# 2. Software Components Of the Computer System

-   Before mid-70s, memory used magnetic cores. This means that a small programming error could result in your whole system being bricked - you'd have to re-enter in the loader/OS by hand.
-   Because you had to put the loader in by hand, it was as short as possible with no error checking
-   Minimum loader was called a bootstrap loader.
-   Semiconductor memory (RAM) then replaced magnetic core memory, which had the drawback of losing all information when the power cuts.
-   Manufacturers then started to put a bootstrap loader in EPROM (erasable programmable read-only memory) which was non-volatile.
-   "Firmware" is called such because it is software that is "made harder" by being put it ROM

## 2.1 Firmware Monitor

-   The 8080 begins by executing the first instruction in memory, but that would be in (empty) volatile RAM storage, so there is a bootup circuit, activated by the reset button, that loads some instructions from PROM, substituting it for the RAM. The computer then disconnects the "shadow PROM"
-   The first instruction in the PROM is a jump to the monitor program, which is a program that uses the console to communicate with the operator, and provides routines that enable them to interact intimately with the computer hardware,
-   **Address Bus** = set of sixteen signals that carry the address of the memory location to be accessed. The last bit is used to remove shadow PROM

I got a laugh out of this paragraph:

> We do not have to hit the reset switch. It is sufficient to press it gently. But when a program blows up and manual reset is necessary it is customary to want to hit something, so these switches get a real workout.

![CP/M boot sequence diagram](https://i.ibb.co/NnDZ6yH/image.png)

-   Monitor may be useful if a program goes wrong, but DDT also allows debugging in these cases so it's not necessary
-   Monitors also may provide a way to call device drivers for I/O, but CP/M does this for us as well
-   The entire boot process should be invisible, as long as everything is configured correctly - with CP/M in drive 0

## 2.2 The operating system

-   The OS is CP/M in our computer
-   Has been ported to many different chips, written in 8080 instruction set
-   IO ports are not standardized - drivers must test the status of different ports to determine what device is connected
    -   The port used will differ from one computer to another
    -   So will the Busy indicator
    -   CP/M solves this by abstracting over the hardware
-   Mass storage devices are even more complex, but CP/M abstracts over this as well!

## 2.3 Customizing CP/M

-   All disk and I/O accesses are passed through a single entry point into CP/M.
    -   This is done by passing function codes in one register, and the data or buffer address passed in other registers.
    -   Through this, it is possible to write programs that will run on any hardware without modification.
    -   It will never be necessary to use hardware-specific addresses in the programs we make, making them portable

## 2.4 Application programs

-   Firmware monitor, special RAM areas, and CP/M take up some memory (CP/M about 6k)
-   The rest of the memory is available for application programs - this area of ram is the "Transient program area" / TPA. It begins at a fixed address and has all the RAM not explicitly needed by CP/M
-   Application program = non-system software
-   CP/M editor = `ed`, assembler = `asm`, loader = `LOAD`, debugger = `DDT`
    -   `DDT` will be loaded along with our apps until they don't need further debugging

## 2.5 Special memory areas

-   The lowest addresses of RAM are reserved for "vectors", which are unconditional jump instructions for hardware interrupts
    -   We don't need to be worried about these for now - just take care not to overwrite them
-   Next, there are buffer areas we'll use for interfacing our program with the OS
-   Monitor functions may also be in a special place in RAM depending on the computer
    -   Leaving space for this was already done by the person who ported CP/M to the computer you are using

![Simplified Diagram of an example CP/M Computer](https://i.ibb.co/2gDv0B1/image.png)

-   This chapter has discussed the monitor, the operating system, and application programs. It also discussed how the mapping of memory gets all of these software elements into the CP/M computer.
