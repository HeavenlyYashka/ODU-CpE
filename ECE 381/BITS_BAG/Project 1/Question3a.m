%Question 3a
n=[0:25];
b=[1];
a=[1 -0.8 0.12];
x=inline('n==0','n');
f1a=filter(b,a,x(n));
subplot(1,3,1)
stem(n,f1a,'r')
title('Q3(a)')
xlabel('n')
ylabel('h(n)')

