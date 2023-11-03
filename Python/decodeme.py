#Pytthon script that takes in arguments if the a file needs to be b64 decoded, and if the file needs the text reversed
# Input and output files are needed.

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
	joinlines = joinlines[::-1]

if args.d:
	
	joinlines = base64.b64decode(joinlines)

try:
	outf = open(args.out_file, "w")
	outf.write(joinlines)
except:
	outf = open(args.out_file, "wb")
	outf.write(joinlines)

outf.close()


