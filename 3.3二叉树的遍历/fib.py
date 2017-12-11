# 助于理解先序
def fib(n):
	a,b=0,0
	print("start at %d" % n,end=' ')
	if n<3:
		print("return 1")
		return 1
	else:
		print("going to %d,%d" % (n-1,n-2))
		a += fib(n-1)
		b += fib(n-2)
		return a+b

fib(6)