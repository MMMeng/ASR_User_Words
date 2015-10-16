#!/usr/bin/env python
# -*- coding: utf-8 -*-



def func(a,b,c=0,*args,**kw):
    print 'a=',a,'b=',b,'c=',c,'args=',args,'kw=',kw

func(1,2)
func(1,2,c=3)
func(1,2,3,'a','b','c')
func(1,2,3,'a','b','c',x=99)
args=(4,5,6,7)
kx={'x':99,'y':100}
func(*args,**kx)
func(*args)

def person(name,age,**kw):
    print 'name:',name,'age:',age,'other:',kw
person('mm',24)
person('mm',24,city='beijing')
person('mm',24,gender='Female',city='beijing')

num=[1,2,3]
def calc(*numbers):
    sum=0
    for n in numbers:
        sum=sum+n*n
    return sum
print calc(*num)
print calc(1,2,3,4)
print calc(1,2,3,4,5)
print calc()


def add_end(L=None):
    if L is None:
        L=[];
    L.append('end')
    return L
print add_end([1,2,3])
print add_end()
print add_end()

def enroll(name,gender,age=6,city='Beijing'):
    print 'name',name
    print 'gender',gender
    print 'age',age
    print 'city',city

enroll('mm','female')

def power(x,n=2):
    s=1
    while n>0:
        n=n-1
        s=s*x
    return s

print power(2,3)
print power(2)
import math

def move(x,y,step,angle=0):
    nx=x + step*math.cos(angle)
    ny=y - step*math.sin(angle)
    return nx,ny
r=move(100,100,60,math.pi/6)
print r



age=180
if age>=18:
    pass


def my_abs(x):
    if not isinstance(x,(int,float)):
        raise TypeError('bad operand type')
    if x>=0:
        return x
    else:
        return -x

x=int(raw_input('请输入一个数字:\n'))
x=my_abs(x)
print x
birth =int(raw_input('你的出生年'))
if birth >2000:
    print '00后'
else:
    print '00前'
sum=0
n=99
while n>0:
    sum=sum+n
    n=n-2
print sum

sum=0
for x in range(101):
    sum=sum+x
print sum

names=['one','second','third']
for name in names:
    print name

age=3
if age>=18:
    print 'adult'
elif age>=6:
    print 'teenager'
else:
    print 'kid'

print '中文测试正常'
name = raw_input('please input your name: ')
print 'hello,',name
a=-100
if a>=0:
    print a
else:
    print -a
print(abs(a))
print '''line1
line2
line3'''

def fact(n):
    if n==1:
       return 1
    return n*fact(n-1)

def fact(n):
    return fact_iter(n,1)
#尾递归调用，在函数返回的时候，调用自身本身，并且return语句不能包含表达式
def fact_iter(num,product):
    if num==1:
        return product
    return fact_iter(num-1,num*product)

L=[]
n=1
while n<=99:
    L.append(n)
    n=n+2
print L
L=[1,2,3,4]
print L
r=[]
n=3
for i in range(n):
    r.append(L[i])
#print r
#print L[:5]
#print L[1:3]
print L[-2:]

L=range(100)
print L
print L[:10]
print L[-10:]
print L[10:20]#前11到20个数
print L[:10:2]
print L[::5]
print L[:]
print 'abcdefg'[:3]
print 'abcdefg'[::2]

d={'a':1,'b':2,'c':3}
for key in d:
    print key
for value in d.itervalues():
    print value
for k,v in d.iteritems():
    print k,v

for ch in 'abc':
    print ch

from collections import Iterable
print isinstance('abc',Iterable)
print isinstance([1,2,3],Iterable)
print isinstance(123,Iterable)


for i,value in enumerate(['a','b','c']):
    print i, value


for x,y in [(1,1),(2,4),(3,9)]:
    print x,y


print range(1,11)
#列表生成式
print [x*x for x in range(1,11)]
print [x*x for x in range(1,11) if x % 2 ==0]
print [m+n for m in range(1,4) for n in range(5,8)]

#列出当前目录下的所有文件和目录名
import os
print [d for d in os.listdir('.')]

L = ['Hello','World','IBM','Apple']
print [s.lower() for s in L]

L =[x*x for x in range(10)]
print L
#g是一个generator（生成器）
g = (x*x for x in range(10))
print g.next()
for n in g:
    print n


def fib(max):
    n,a,b=0,0,1
    while n < max:
        print b
        a,b=b,a+b
        n=n+1
fib(5)
#如果一个函数中包含yield关键字，那么这个函数就是一个generator
def fib(max):
    n,a,b=0,0,1
    while n < max:
        yield b
        a,b=b,a+b
        n=n+1
print fib(6)
for n in fib(8):
    print n

def odd():
    print 's1'
    yield 1
    print 's2'
    yield 2
o=odd()
print o.next()
print o.next()


#函数本身可以赋值给变量，即：变量可以指向函数
f=abs
print f
print f(-10)
#高阶函数：一个函数可以接收另一个函数作为参数
def add(x,y,f):
    return f(x)+f(y)
print add(-5,6,f)
#map/reduce
#map作用：把f(x)作用在list的每一个元素并把结果生成一个新的list
def f(x):
    return x*x
print map(f,range(1,10))
print map(str,range(1,10))
#reduce把一个函数作用在一个序列上，这个函数必须接受两个参数，reduce把结果继续和序列的下一个元素做累积计算。
def add(x,y):
    return x+y
print reduce(add,[1,3,5,7,9])

def fn(x,y):
    return x*10+y
print reduce(fn,[1,3,5,7,9])
































