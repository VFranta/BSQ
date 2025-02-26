map gen
-to run map_gen
	- perl map_gen 10 10 4
	-perl map_gen "num of rows" "num of lines" "density of obstacles"

the characters may changed but possition for each char will be same
- "." free space
- "o" obstacle
- "x" full
- on EOL is "\n"

map10_10_1
10.ox$
.....o....$
......o...$
..........$
..........$
........o.$
..........$
.....o....$
..........$
..........$
..........$

x = number of colloms
y = number of line

This is the BSQ (Biggest Square) project, a well-known algorithmic challenge in C. You'll need to parse a map, analyze it to find the largest possible square, and then output the modified map. Here’s how you can break it down:

Project Breakdown:
1. Parsing the Input Map
The first line contains the number of rows, the empty character, the obstacle character, and the full character.
The map must be validated according to the given rules.
If a map is invalid, print map error to stderr and move to the next file.
2. Finding the Biggest Square
You’ll likely use dynamic programming to efficiently find the largest square.
A 2D auxiliary array (or in-place modification of the map) will be used to track the possible square sizes.
3. Printing the Result
Modify the original map by replacing the found area with the full character.
Handle multiple file inputs, printing a newline between outputs.
Implementation Plan:
Read and validate the input (from file or stdin).
Store the map in a 2D array while checking its validity.
**Use dynamic
