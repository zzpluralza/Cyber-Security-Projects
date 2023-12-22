import base64

stringthing = "bDNhcm5fdGgzX3IwcDM1"
decodedthing = str(base64.b64decode(stringthing))
flag = "picoCTF{" + decodedthing + "}"

#Need to remove the b and the two ' for the correct flag
print (flag)
