# acc = load(50)
3A
50
00
# c = 50
0E
50
# store(b&c, sum)
02
# sum++
3C
# c++
0C
# store acc at 40
32
40
00
# acc = 5A
3E
5A
# check c = acc
B9
# load acc from 40
3A
40
00
# jump to store if not zero
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