# Registry check for long registry key values (indicator of hidden code) 11-10-2023
# Updated 11-13-2023 - Added additional text and an argument requiring an output file name to write the data to
# Adding another argument for max length to look for. If there are a lot fo reg subkeys, need an easy way to see
# the longer lines

# Version 1.3

import winreg
import argparse

argfile = argparse.ArgumentParser(description="Requires a filename to write key values to.")
argfile.add_argument("ofile", type=str,help="Name of output file needed.")
argfile.add_argument("maxint", type=int, help="Enter -n and a positive integer value" )
args = argfile.parse_args()

lmkey = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE)
lmpathkey = winreg.OpenKeyEx(lmkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\", 0, winreg.KEY_READ)
lmpathkeyonce = winreg.OpenKeyEx(lmkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\", 0, winreg.KEY_READ)

lukey = winreg.ConnectRegistry(None, winreg.HKEY_CURRENT_USER)
cupath = winreg.OpenKeyEx(lukey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\", 0, winreg.KEY_READ)
cupathonce = winreg.OpenKeyEx(lukey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\", 0, winreg.KEY_READ)

outfile = open(args.ofile, "w")
maxlen = args.maxint
# Need to do a check if the loop doesn't get anything that it is written in the log that nothing is there

outfile.write("\nLocation at - HKLM:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run \n")
for i in range(0, winreg.QueryInfoKey(lmpathkey)[1]):

    #outfile.write(winreg.EnumValue(lmpathkey, i))
    print(winreg.EnumValue(lmpathkey, i))
    strval = str(winreg.EnumValue(lmpathkey, i))
    outfile.write(strval + "\n")

outfile.write("\nLocation at - HKLM:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce \n")
for i in range(0, winreg.QueryInfoKey(lmpathkeyonce)[1]):
    print (winreg.EnumValue(lmpathkeyonce, i))
    strval = str(winreg.EnumValue(lmpathkeyonce, i))
    outfile.write(strval + "\n")

outfile.write("\nLocation at - HKCU:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run \n")
for i in range (0, winreg.QueryInfoKey(cupath)[1]):
    print (winreg.EnumValue(cupath, i))
    strval = str(winreg.EnumValue(cupath, i))
    outfile.write(strval + "\n")
    
outfile.write("\nLocation at - HKCU:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce \n")

for i in range (0, winreg.QueryInfoKey(cupathonce)[1]):
    print (winreg.EnumValue(cupathonce, i))
    strval - str(winreg.EnumValue(cupath, i))
    outfile.write(strval + "\n")
print ("\nGathered keys. Moving to analyze key length.")

outfile.close()
#------------------Analyzing output--------------------------------------
#Make an estimation how long in characters each line should be before it gets flagged
outfile = open(args.ofile, "r+") #Close and reopen file with the r+. Since we'll be reading and writing to the file

lines = outfile.readlines()

count = 0

for line in lines:
#   line = outfile.readline()
    #line = line.rstrip('\n')
    linesplit = line.split(',')
    linecut = linesplit[1].strip() if len(linesplit) > 1 else ""
    if len(linecut) > maxlen:
        print (f"{linecut}")

print ("Completed.")





