#pyhton PUA report parser
#2024/11/28
import csv
columnnames = ["NAME", "FRIENDLY_NAME", "DEVICE_TYPE", "SITE_NAME", "SITE_UNIQUE_ID", "OS", "IP_ADDRESS", "APPLICATION_NAME", "VERSION", "PUBLISHER", "INSTALL_DATE", "LAST_LOGGED_ON_USER", "DATE_CHECKED"]
puaarray =["????? 12.4.0????", "1ClickPDF", "Browser Assistant", "Browser Extension", "Clear", "Coupon Printer for Windows", "Direct Game UNI Installer", "Download Updater (AOL LLC)", "gifsearchresults", "GoodSearch", "MamboSearch", "OneLaunch", "OneStart", "PC App Store", "PDFSuperHero", "PDFPower", "screensearchresults", "Search App by Ask", "Search the Web (Yahoo)", "SearchAppDB", "searcharchiver", "Searchcompare", "searchconapp", "Searchadol", "searchit", "Searchontop", "searchpoweronline", "searchshar", "SearchSynergy", "SearchTools", "searchtoolhub", "Shift", "SweetPacks", "WaveBrowser Browser", "WebNavigator Browser"]

retainedfieldnames = ["NAME","DEVICE_TYPE", "SITE_NAME", "OS","APPLICATION_NAME", "VERSION", "PUBLISHER"]

source_file = "big_sample.csv"
out_file = "Results.csv"

fields = []
columns =[]
rows = []

#Pulling 
with open(source_file, 'r') as csvfile:
	csvreader = csv.reader(csvfile)
	fields = next(csvreader)
	for row in csvreader:
		rows.append(row)

#print ("Field names: " + ", ".join(field for field in fields))


with open (out_file, 'w') as writefile:
	writer = csv.writer(writefile, delimiter=',')
	writer.writerows([retainedfieldnames])

	for row in rows:
		for pua in puaarray:
			row_new = [row[0], row[2], row[3], row[5], row[7],row[8],row[9]]
			#Find match in row APPLICATION_NAME - Need to write to output csv file
			if (row[7].startswith(pua)):
				writer.writerows([row_new])



			# print ("Found PUA " + row[7] + " on system: " + row[0] + " Site: " + row[3])




