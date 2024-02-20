#reverse and invert bytes in file 


with open('decoded', 'rb') as reverseme, open('stage2.exe', 'wb') as outfile:
	bytes_read = reverseme.read()
	bytes_reversed = bytes_read[::-1]

	for b in bytes_reversed:
		b = b.to_bytes(1, 'big')
		outfile.write(b)
outfile.close()
