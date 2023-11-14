#11-13-2023 - Updated with some text feedback. Help indicate what it's doing and when it is complete. 
#Version 1.1
#Author: Garrett Burt
#Purpose of tool: while analyzing malware I encounter lots of b64 strings that are reversed. Want a tool to easily reverse,
#decode, and write to a file. This app will try to write the output in text, if not, it writes it in bytes

# Example: python3 decodeme.py --d --r inputfile.file outputfile.file

import argparse
import base64
import binascii

parser = argparse.ArgumentParser(description="Takes strings within a file and decodes from base64 and revserses them.")
parser.add_argument("input_file", type=str, help="Input file needed to read the strings from.")
parser.add_argument("--d", action="store_true", help="Decode from base64.")
parser.add_argument("--r", action="store_true", help="Reverse string order.")
parser.add_argument("out_file", type=str, help="Output filename to write results to.")


args = parser.parse_args()

with open(args.input_file, "r") as infile:
	lines = infile.readlines()

joinlines = ("".join(lines))

if args.r:
	print ("Reversing strings")
	joinlines = joinlines[::-1]

if args.d:
	print ("Base64 decoding")
	joinlines = base64.b64decode(joinlines)

try:
	print ("Writing file as text")
	outf = open(args.out_file, "w")
	outf.write(joinlines)
except:
	print ("writing file as bytes")
	outf = open(args.out_file, "wb")
	outf.write(joinlines)

print ("String manipulation is complete.")
outf.close()


