#Script to identify hex values within a file. Prints out hex strings.
#Version 1.05 - Basic search and printout.
#Created Date: 11/29/2023 
#Author: Garrett Burt
#Future versions will: Translate to ASCII, output to file, Command line arguments for input and output files
#--Update Notes--
#11/30 - Started to decode from hex. Combined lists to strings and decoded from there. Had to deal with output being in bytes so I 
#added a decode to utf-8 option. Some would not work so I added a try catch in order to get passed the errors. This worked and I have gotten back some
#of the original text that I converted to hex. Need to refine the search process with the startfile.

import re
import binascii

startfile = "E:\\VS Projects\\partialhex.txt" #input file to read hex data from.
textlist = []

print (f"Reading hex file, {startfile}.\n")

with open(startfile, "r") as hexfile:
    textlist = hexfile.read().split('\n') #Splits by newline
hexstrings = [] #Stores hex values for each line

for line in textlist: #Searches each line for hex values
    hexstrings.append(re.findall(r'[0-9A-FA-F][0-9A-FA-F]', line, re.IGNORECASE)) #ignore case, since some instances the letters are capitalized, others they are not.
    
for n in hexstrings:
    if n:
       #print (f'{n}')
       combined = ''.join(n)
       #Leaving most code that worked, but not needed as commments, in case I want to review or go back to them.
       #combined = combined.strip(",")
       #print (combined) 
       #unhex = bytearray.fromhex(combined).decode()
       unhex = binascii.unhexlify(combined)
       try:
           str(unhex.decode('ascii'))
       except:
           pass       
       print (unhex)

#Some incorrect hex values are identified. Example, ec, da, etc. Need to use re to filter those out. Do this in the next version.
print (combined)
print (f'Script completed')


