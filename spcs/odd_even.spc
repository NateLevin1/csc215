3A # Load from 47 into acc
47
00
06 # MVI B, 01
01
A0 # AND acc with B
3A # Load from 47 into acc
47
00
# Jump to EVEN if 0
CA
11
00
# ODD:
07 # Rotate accumulator left
32 # Store accumulator in 47
47
00
76 # halt
# EVEN:
0F # Rotate accumulator right
32 # Store accumulator in 47
47
00
76 # halt
===
47:0F