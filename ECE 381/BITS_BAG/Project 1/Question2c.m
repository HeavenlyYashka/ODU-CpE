%Question 2c
n=-20:40;
x3=((1/2).^n).*([(n+2)>=0]-[(n-15)>=0]);
stem(n,x3)
xlabel('n')
ylabel('x1_n')