import os
import yara
import hashlib
import csv

YRules = "rules"
ScanLocation = "testfiles"
output_file = "results.csv"

#-------------------------------------------------------------------------------------------------
def load_rules(ruleloc):
	rule_path = {}
	for root, _, files in os.walk(ruleloc):
		for file in files:
			fullpath = os.path.join (ruleloc, file)
			rule_path[file] = fullpath
			UseRules = yara.compile(filepaths=rule_path)
		print (f"Comiled rule {file}")
	
	return UseRules

#-------------------------------------------------------------------------------------------------
def scan_location (yrules, Scanlocation):
	matches = []
	match_list = []
	for root, _, files in os.walk(Scanlocation):
		for file in files:
			fullpath = os.path.join(root, file)
			print (f"Scanning file {fullpath}")
			try: # try to read file bytes
				with open(fullpath, 'rb') as f:
					file_data = f.read()
					matches = yrules.match(data=file_data)

			except:
				print (f"Failed to scan file {file}")
				continue

			if matches:
				for match in matches:
					print (f"!! Match found for file {file} using rule {match.rule}")
					match_list.append(fullpath)
				
			else:
				print (f"NO match found for file {fullpath}")			
	return match_list

#-------------------------------------------------------------------------------------------------
compiledrules = load_rules(YRules)

scan_location(compiledrules, ScanLocation)
print (f"Scan Completed")


