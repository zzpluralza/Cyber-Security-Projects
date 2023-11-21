"""
lolbins registry check
Updated on 11/21/2023
Author: Garrett Burt
Version version 1.4
"""

import winreg
import argparse
wordlist=[] 

def regsubscan(lpath, lstore): # function to read sub-key values
    for i in range(0, winreg.QueryInfoKey(lpath)[1]):
        lstore.append(str(winreg.EnumValue(lpath, i)))
        print (lstore[i] + "\n")
        writeme.write(lstore[i] + "\n")
    return lstore #returns the list so it can be added upon on the next call
    
#Three arguments, txt file with strings to look out for, output file, where the results are written to and the max length before it raises concerns
args = argparse.ArgumentParser(description="Need wordlist text file and output file to write results to.")
args.add_argument("wordf", type=str, help="Enter name of wordlist file, .txt")
args.add_argument("ofile", type=str, help="Enter name of output file. Output will be text.")
argval = args.parse_args()
writeme = open(argval.ofile, "w")

#Add more locations as I see them based on Lolbins / Lolbas - Just using HKLM for testing. 
localmachinkey = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE) 
localpath = winreg.OpenKeyEx(localmachinkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\",0, winreg.KEY_READ)

localpathonce = winreg.OpenKeyEx(localmachinkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\",0,winreg.KEY_READ)

currentkey = winreg.ConnectRegistry(None, winreg.HKEY_CURRENT_USER)
userpath = winreg.OpenKeyEx(currentkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\", 0, winreg.KEY_READ)
useronce = winreg.OpenKeyEx(currentkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\", 0, winreg.KEY_READ)

lmkeystore = []
writeme.write("Key values scanned: \n")

writeme.write("Gathering key values in HKLM:SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\ \n")
regsubscan(localpath, lmkeystore)
writeme.write("Gathering key values in HKLM:SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\ \n")
regsubscan(localpathonce, lmkeystore)
writeme.write("Gathering key values in HKCU:SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\ \n")
regsubscan(userpath, lmkeystore)
writeme.write("Gathering key values in HKLM:SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\ \n")
regsubscan(useronce, lmkeystore)

suscount = 0 #keep track of how many subkeys found

with open(argval.wordf, "r") as wlist: #Pulling the words from the list and assigning them to the list wordlist
    wordlist = wlist.read().split()
print ("-----------------------------------------------------------------")
writeme.write("----------------------------------------------------------------------\n")
writeme.write("Now looking for keywords in the sub-key values.\n")
for val in lmkeystore:
    for word in wordlist:
        #Force lowercase, to avoid potential obfuscation by using random capital letters
        if word.lower() in val.lower():
            print (f"Found: \'{word}\' in the sub-key")
            writeme.write(f"Found: \'{word}\' in the sub-key")
            print (val + "\n")
            writeme.write(val + "\n")

            suscount += 1
writeme.write(f"Suspicious key count: {str(suscount)}\n")

if suscount == 0:
    print ("didn't find anything in the scanned reg key values.")

writeme.close()
print ("Script completed")





