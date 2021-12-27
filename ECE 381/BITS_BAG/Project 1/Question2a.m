%Question 2a
a=-20:40;
x1=[a>=0]-[(a-30)>=0];
stem(a,x1)
xlabel('n')
ylabel('x1_n')