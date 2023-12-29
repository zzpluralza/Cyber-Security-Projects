#PicoCTF - MiniRSA
#sort by number

encdict={0:'d', 29:'3', 4:'r', 2:'5',23:'r',3:'c',17:'4',1:'3',7:'b',10:'_',5:'4',9:'3',11:'t',15:'c',8:'l',12:'H',20:'c',14:'_',6:'m',24:'5',18:'r',13:'3',19:'4',21:'T',16:'H',27:'f',30:'b',25:'_',22:'3',28:'6',26:'f',31:'0'}

#Starting with lists, but then realized it was easier to make the code into a dictionary
#scrambled =['d','3','r','5','r','c','4','3','b','_','4','3','t','c','l','H','c','_','m','5','r','3','4','T','H','f','b','_','3','6','f','0']
#ordernum = [0,29,4,2,23,3,17,1,7,10,5,9,11,15,8,12,20,14,6,24,18,13,19,21,16,27,30,25,22,28,26,31]
#rightorder = [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31]

flaginner = []
n = 0
i = 0
for n in range(32):    
    flaginner.append(encdict[n])
    n =+n

#print (scrambled[15])

#flag = 'picoCTF{'.join(flaginner)

flaginner = ''.join(flaginner)
flag = 'picoCTF{'
end = '}'

print (f'{flag}{flaginner}{end}')
#Joined up the strings to make the flag
