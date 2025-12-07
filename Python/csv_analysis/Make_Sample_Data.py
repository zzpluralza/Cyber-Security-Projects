import csv
import random

program_array = ["Notepad++", "Word Perfect 14", "Adobe Photoshop CS6", "WebNavigator Browser", "Direct Games UNI Installer", "SearchTools", "Microsoft 365 Standard", "Norton AV", "McAfee Security", "Gimp 1.0", "Paint.NET", "Blender", "gifsearchresults", "SearchSynergy", "WaveBrowser", "Google Chrome", "Mozilla Firefox", "Brave Browser", "Adobe Acrobat Pro", "QuickBooks 2024", "QuickBooks 2022", "AVG AntiVirus", "Corel Draw X6", "searchconapp", "Download Updater (AOL LLC)", "VMWare Workstation", "VirtualBox", "Windows Subsystem for Linux", "Logitech Commander", "Intel Graphics Commander", "DOS-Box", "searchitfalc", "Yahoo Search Bar", "Ask Toolbar", "MalwareBytes", "Searchcompare", "AOL Instant Messenger", "Shift 1.2.4", "Shift Browser", "Waterfox", "Microsoft Edge", "Update by Sweekpacks", "Steam", "Epic Game Launcher", "Halo 3", "Oni", "Microsoft VS Code", "Sublime-Text", "Python 3.16", "Libre Office", "Snes9x", "Mame", "PDFSuperHero", "Adobe CC 2018", "Maya 8.0", "Autodesk AutoCAD", "PDFPower", "Ultima VII", "Crusader No Remorse", "Microsoft .Net Framework 4.0", "MS Office 97", "Matlab", "Maple 7", "Sega Emulator", "Mass Effect", "Wing Commander 3", "3d Pinball", "3D StudioMax", "ScummVM", "Adobe Updater", "Datto Backup Agent", "NBA Jam", "screenserarchutils", "1ClickPDF","Browser Extension", "Clear Network", "StickyPads", "Halo 2", "Call of Duty", "Crysis", "GOG Galaxy", "bnes", "AMD Catalyst", "Nvidia Control Center", "Stellarium", "Windows Defender", "Kaspersky AV", "Microsoft Outlook", "Thunderbird", "SketchUp", "Inkscape", "Search the Web (Yahoo)","Word Perfect Suite X3", "Google Sheets", "Microsoft OneDrive", "QuickBooks 2024", "QuickBooks 18", "PeachTree 2022", "WordPerfect 6", "Microsoft 365 Apps", "Microsoft 365 Standard", "Corel Draw X4", "Microsoft Office 2010", "Notepad++", "Autodesk Maya 2022", "Sophos Endpoint Protection", "SentinelOne", "Adobe Updater", "Datto Backup Agent", "Microsoft .Net Framework 4.0", "MS Office 97", "Matlab", "Maple 7"] 

Desktop_names = ["DESKTOP-FJ8K7F", "DESKTOP-Main", "FrontDesk", "DC01", "FileServer01", "QuickbooksSystem", "DESKTOP-JJ5480", "HP-LAPTOP", "DESKTOP-24JKF37", "BackOffice", "QB-Server", "Lab-System", "Bill-Computer", "CEO", "FinanceComputer", "HP-ZBook"] #16

columnnames = ["NAME", "FRIENDLY_NAME", "DEVICE_TYPE", "SITE_NAME", "SITE_UNIQUE_ID", "OS", "IP_ADDRESS", "APPLICATION_NAME", "VERSION", "PUBLISHER", "INSTALL_DATE", "LAST_LOGGED_ON_USER", "DATE_CHECKED"]

out_file = "big_sample.csv"

with open(out_file, 'w') as resultfile:
	writer = csv.writer(resultfile, delimiter=',')
	writer.writerows([columnnames])

	for i in range(650000):
		r_app = random.randint(0,94)
		app = program_array[r_app]
		r_name = random.randint(0,15)
		dname = Desktop_names[r_name]

		rows = [dname, dname, "Desktop", "Magrathea Inc.","0","Windows","0",app,"1.002","Unknown","0","0","0"]
		writer.writerows([rows])

#print (len(program_array))
