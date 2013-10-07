t = input()
for i in range(1,t+1):
	a,b,c = raw_input().split(' ') 
	if int(a)+int(b) > int(c):
		print "Case #%d: true" %i
	else:
		print "Case #%d: false" %i
