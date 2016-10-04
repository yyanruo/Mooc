import urllib
from BeautifulSoup import *

#url = raw_input('Enter - ')
url = 'http://python-data.dr-chuck.net/comments_258684.html '
html = urllib.urlopen(url).read()
soup = BeautifulSoup(html)

spans = soup('span')
a = 0
for span in spans:
    # Look at the parts of a tag
    a = a + int(span.contents[0])
    
print a