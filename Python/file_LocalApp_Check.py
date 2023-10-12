#Script to scan local appdata folder for any script files. Include path and add hashes
import os
import hashlib


appdata_folder = os.getenv('LOCALAPPDATA') #Local appdata
file_ext_full = ['js', 'exe', 'msi', 'hta', 'bat', 'ps1', 'vba', 'xlsx', 'docx', 'docm', 'xlsm']
file_scripts = ['hta', 'bat', 'ps1', 'vba']
f = open('file_list.txt', 'w')

for rootpath, dirs, files in os.walk(appdata_folder):
    for file in files:
        if file.split('.')[-1] in file_scripts:
            file_path = os.path.join(rootpath, file)
            with open (file_path, 'rb') as h:
                hash_sha1 = hashlib.sha1()
                hash_sha1.update(h.read())
                file_hash = hash_sha1.hexdigest()
            f.write(f"{file_path}  :  {file_hash}\n")            
            print (file_path, "  |  ", file_hash)
            
            

    