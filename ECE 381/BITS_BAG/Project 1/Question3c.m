%Zero input response
z_i=filtic(b,a,[2 2]);
y_zi=filter(b,a,zeros(size(n)),z_i);
subplot(1,3,1)
stem(n,y_zi,'r')
title('Zero-Input Response')
xlabel('n')
ylabel('y_zi')

%Total response 
x=inline('heaviside(n)-heaviside(n-15)','n');
Y_T=filter(b,a,x(n),z_i);

%Zero-State Response
y_zs=Y_T-y_zi;
subplot(1,3,2)
stem(n,y_zs,'k')
title('Zero-State Response')
xlabel('n')
ylabel('y_zs')
subplot(1,3,3)
stem(n,Y_T)
title('Total Response')
xlabel('n')
ylabel('Y_T')
