import urllib
import xml.etree.ElementTree as ET
import json

serviceurl = 'http://python-data.dr-chuck.net/comments_258685.json'

url = serviceurl 
uh = urllib.urlopen(url)
input = uh.read()

info = json.loads(input)
print 'User count:', len(info)


x = 0
for item in info['comments']:
    print 'Name', item['name']
    print 'count', item['count']
    x += item['count']
    
print x
  
