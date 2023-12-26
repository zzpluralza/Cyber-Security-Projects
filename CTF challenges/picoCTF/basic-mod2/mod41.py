import string
#Had to modify the mod37 py script. Change the modval to be based on modular inverse (pow)
# Adjust the modulation to 41, and adjust the ranges below.
flag =[]
with open("message41.txt") as f:
    datum = f.read()
    numval = [int(val) for val in datum.split()]
    for num in numval:
        modval = (pow (num, -1,41)) 
        #print (modval)
        if modval in range (1, 27):
            flag.append(string.ascii_uppercase[modval-1])
        elif modval in range (27, 37):
            flag.append(string.digits[modval-27])
        elif modval == 37:
            flag.append('_')


    
joined = "".join(flag)
joined = "picoCTF{" + joined + "}"
print (joined)