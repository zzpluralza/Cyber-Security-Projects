#Script to identify hex values within a file. Prints out hex strings.
#Version 1.00 - Basic search and printout.
#Created Date: 11/29/2023 
#Author: Garrett Burt
#Future versions will: Translate to ASCII, output to file, Command line arguments for input and output files

import re
# import binascii
# Enable Binascii when ready to unhexlify the output data

startfile = "E:\\VS Projects\\partialhex.txt" #input file to read hex data from.
textlist = []

print (f"Reading hex file, {startfile}.\n")

with open(startfile, "r") as hexfile:
    textlist = hexfile.read().split('\n') #Splits by newline
hexstrings = [] #Stores hex values for each line

for line in textlist: #Searches each line for hex values
    hexstrings.append(re.findall(r'[0-9A-FA-F][0-9A-FA-F]', line, re.IGNORECASE)) #ignore case, since some instances the letters are capitalized, others they are not.
    
for n in hexstrings:
    print (f'{n}\n')
#Some incorrect hex values are identified. Example, ec, da, etc. Need to use re to filter those out. Do this in the next version.


