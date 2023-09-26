# c is the index in memory that the accumulator is stored at
# it is incremented each loop
# load initial accumulator from memory address 50
3A
50
00
# set register c = 50
0E
50
# loop_start: store the accumulator at the location specified by register c
02
# sum++
3C
# c++
0C
# temporarily store accumulator at 40 so we can use accumulator for comparison
32
40
00
# set acc to 5A (the stopping point)
3E
5A
# check if c = acc (check if we've reached the stopping point; sets zero bit)
B9
# load acc from 40 (because we had to change it to 5A for the comparison)
3A
40
00
# jump to loop_start if not zero (if we haven't reached the stopping point)
C2
05
00
# loop forever
C3
15
00
===
40:00
41:00
50:0A