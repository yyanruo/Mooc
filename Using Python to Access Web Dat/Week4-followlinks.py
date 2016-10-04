import urllib
from BeautifulSoup import *


url = 'http://python-data.dr-chuck.net/known_by_Heidi.html'

count = input('Count:')
position = input('Position:')


for i in range(0,count):
	html = urllib.urlopen(url).read()
	soup = BeautifulSoup(html)
	tags = soup('a')
	print tags[position-1].get('href',None)
	url = tags[position-1].get('href',None)
	

    