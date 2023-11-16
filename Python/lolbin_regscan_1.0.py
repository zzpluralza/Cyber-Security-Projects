#lolbins registry check
#Begin work on 11-14-2023
#Author: Garrett Burt
#Version version 1.0

import winreg
import argparse
wordlist=[] 

args = argparse.ArgumentParser(description="Need wordlist text file and output file to write results to.")
args.add_argument("wordf", type=str, help="Enter name of wordlist file, .txt")
args.add_argument("ofile", type=str, help="Enter name of output file. Output will be text.")
argval = args.parse_args()


#Add more locations as I see them based on Lolbins / Lolbas - Just using HKLM for testing. 
localmachinkey = winreg.ConnectRegistry(None, winreg.HKEY_LOCAL_MACHINE) 
localpath = winreg.OpenKeyEx(localmachinkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\\",0, winreg.KEY_READ)
localpathonce = winreg.OpenKeyEx(localmachinkey, r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\RunOnce\\",0,winreg.KEY_READ)

writeme = open(argval.ofile, "w")

lmkeystore = []
writeme.write("Key values scanned: \n")

for i in range(0, winreg.QueryInfoKey(localpath)[1]): #store each subkey value in lmkeystore[].
    lmkeystore.append(str(winreg.EnumValue(localpath, i)))
    print (lmkeystore[i])
    writeme.write(lmkeystore[i])
for i in range (0, winreg.QueryInfoKey(localpathonce)[1]):
    lmkeystore.append(str(winreg.EnumValue(localpathonce, i)))
    print (lmkeystore[i])
    writeme.write(lmkeystore[i])


suscount = 0 #keep track of how many subkeys found

with open(argval.wordf, "r") as wlist: #Pulling the words from the list and assigning them to the list wordlist
    wordlist = wlist.read().split()
writeme.write("Now looking for keywords in the sub-key values.\n")

for val in lmkeystore:
    for word in wordlist:
        #Force lowercase, to avoid potential obfuscation by using random capital letters
        if word.lower() in val.lower():
            print ("Found: \'" + word + "\' in the sub-key")
            writeme.write("Found: \'" + word + "\' in the sub-key")
            print (val + "\n")
            writeme.write(val + "\n")

            suscount += 1
writeme.write("Suspicious key count: " + str(suscount) + "\n")

if suscount == 0:
    print ("didn't find anything in the scanned reg key values.")

print ("Script completed")




