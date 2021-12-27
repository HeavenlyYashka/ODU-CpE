%question 1
xn = ones(1,16);%u[n] – u[n-16]
fft_xn = fft(xn,8);%finding fft
ifft_fft_xn = ifft(fft_xn);%finding ifft
subplot(311);
stem(abs(ifft_fft_xn));%plotting it


fft_xn = fft(xn,16);
ifft_fft_xn = ifft(fft_xn);
subplot(312);
stem(abs(ifft_fft_xn));


fft_xn = fft(xn,32);
ifft_fft_xn = ifft(fft_xn);
subplot(313);
stem(abs(ifft_fft_xn));