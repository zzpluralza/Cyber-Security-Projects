import winreg

def enumreg(hive, path, regdict):
	try:
		with winreg.OpenKey(hive, path) as key:
			regdict = {}
			#print (f"Key: {path}")
			i = 0
			while True:
				try:
					val_name, val_data, _ = winreg.EnumValue(key,i)
					
					print (f"{path} -- Name: {val_name}, Value: {val_data}")
					#outfile.write(f"\n{path} -- Name: {val_name}, Value: {val_data}")
					i += 1
				except OSError:
					break
			i = 0
			while True:
				try:
					subkey_name = winreg.EnumKey(key, i)
					subkey_path = f"{path}\\{subkey_name}"
					enumreg(hive, subkey_path, regdict)
					i += 1
				except OSError:
					break
	except PermissionError as e:
		print(f"Unable to access reg key: {path}. Error {e}")
	except FileNotFoundError as e:
		pring(f"Reg key not found: {path}. Error: {e}")

def main():
	hive = winreg.HKEY_LOCAL_MACHINE
	path = "System\\CurrentControlSet\\Services"
	with open("Registryresults.txt", "w") as outfile:

		enumreg(hive, path, outfile)

if __name__ == "__main__":
	main()





