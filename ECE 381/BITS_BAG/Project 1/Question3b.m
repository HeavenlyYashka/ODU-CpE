%Question 3b

%Part (a)
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

%Part (b)
subplot(1,3,2)
impz(b,a)
title('Q3(b)')
xlabel('n')
ylabel('h(n)-')
subplot(1,3,3)
f2b=impz(b,a);
f2b=f2b';
m=max(size(f2b));
l=max(size(n));
o=l-m;
A=zeros(1,o);
f2=[f2b A];

%Difference between h[n]'s
diff=f1a-f2;
stem(n,diff,'k')
title('Difference between h[n]')
xlabel('n')
ylabel('diff(n)')
figure
