import base64
import re

stringpattern = '^..picoCTF'

base64_start = """VjFSQ2EyTXlSblJUV0dSVllrWmFWRmx0TlZOalJtUlhZVVU1YVZKVVZuaFdWekZoWVZkR2NrNVVX
bUZTVmtwUVdWUkdibVZXVm5WUgpiSEJzWVRCd2VWVXhXbXBOUlRWSFdqTnNWZ3BYUjFKeVZGZHdW
MlZzVWxaVmJFNW9UVVJDTlZaWE1XRlVkM0JUVW14V05GWkhjRXRXCk1rWnlUVWhzVjJGdGVFVlhi
bTkzVDFWT2JsQlVNRXNLCg=="""

flagbytes = base64.b64decode(base64_start)

decodeneed = True

while decodeneed:
    check = re.search(stringpattern, str(flagbytes))
    print (str(flagbytes))
    if check:
        decodeneed = False
        break
    else:
        flagbytes = (base64.b64decode(flagbytes))

print (str(flagbytes))
