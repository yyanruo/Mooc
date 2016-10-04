import re
a=0
f = open('regex_sum_258679.txt')
txt = f.read()
x = re.findall('[0-9]+',txt)
for i in range(len(x)):
	a = a + int(x[i])
print a