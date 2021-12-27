%Question 2b
n=-20:40;
x2=[(n+10)>=0]-[(n-20)>=0];
stem(n,x2)
xlabel('n')
ylabel('x1_n')