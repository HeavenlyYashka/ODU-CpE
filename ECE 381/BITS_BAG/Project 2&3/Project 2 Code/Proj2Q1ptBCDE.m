%part b
n = 0:19;
b = 1;
a = [1 -0.75];
h1 = impz(b,a,n);
h1 = h1';
subplot(221);
xlabel('time');
ylabel('h[n] using impz');
stem(n,h1);

%part c
xn = [1 zeros(1,19)];
h2 = filter(b,a,xn);
subplot(222);
stem(n,h2);
xlabel('time');
ylabel('h[n] using filter');

diffh = h1-h2;
subplot(223);
stem(n,diffh);
ylabel('difference b/w h[n] in part b and part c');

%part d
xn = (n>=0)-((n-10)>=0);
yn = conv(xn,h1,'same');
subplot(224);
stem(n,yn);

%part e
figure(2);
zplane(b,a);