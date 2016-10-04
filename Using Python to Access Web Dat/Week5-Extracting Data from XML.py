import urllib
import xml.etree.ElementTree as ET

serviceurl = 'http://python-data.dr-chuck.net/comments_258681.xml'

url = serviceurl 
uh = urllib.urlopen(url)
data = uh.read()
    
commentinfo = ET.fromstring(data)

counts = commentinfo.findall('comments/comment')

a = 0 
for item in counts:
	count  =  item.find('count').text
	print count
	a += int(count)
	print '---------------',a
  