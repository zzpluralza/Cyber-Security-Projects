
#bytevalues = [0x70 0x69 0x63 0x6f 0x43 0x54 0x46 0x7b 0x34 0x35 0x63 0x31 0x31 0x5f 0x6e 0x30 0x5f 0x71 0x75 0x33 0x35 0x37 0x31 0x30 0x6e 0x35 0x5f 0x31 0x6c 0x6c 0x5f 0x74 0x33 0x31 0x31 0x5f 0x79 0x33 0x5f 0x6e 0x30 0x5f 0x6c 0x31 0x33 0x35 0x5f 0x34 0x34 0x35 0x64 0x34 0x31 0x38 0x30 0x7d]

bytestring = b"\x70\x69\x63\x6f\x43\x54\x46\x7b\x34\x35\x63\x31\x31\x5f\x6e\x30\x5f\x71\x75\x33\x35\x37\x31\x30\x6e\x35\x5f\x31\x6c\x6c\x5f\x74\x33\x31\x31\x5f\x79\x33\x5f\x6e\x30\x5f\x6c\x31\x33\x35\x5f\x34\x34\x35\x64\x34\x31\x38\x30\x7d"

"""
for i in bytestring:
	decodethis = i.decode('utf-8')
	flag = ''.join(str(decodethis))
"""

flag = bytestring.decode('UTF-8')
print (flag)