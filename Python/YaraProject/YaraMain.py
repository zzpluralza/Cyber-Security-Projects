#Yara python test program
#2024/12/12 - practice with Python and Yara Rules

import yara
import os

rulep = "rules"
location = "testfiles"
matches = []

def load_rules(rulepath):

	yrules = {}
	for file in os.listdir(rulepath):
		rule_path = os.path.join(rulepath, file)
		yrules[file] = yara.compile(filepath=rule_path)
		print (f"Loading rule: {file}")
	return yrules	

def find_match(rules, targetdir):
	matches = []

	for root, _, files in os.walk(targetdir):
		for file in files:
			filepath = os.path.join(root, file)
			with open(filepath, 'rb') as x:
				data = x.read()
				for rulename, rule in rules.items():
					match = rule.match(data=data)
					if match:
						matches.append((filepath, rulename, match))
						print (f"Match found at {filepath} for rule {rulename}")


	return matches

yrules = load_rules(rulep)
find_match(yrules, location) 



