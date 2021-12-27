%question 2
x1n = ones(1,6);
x2n = ones(1,8);
x1npad = [x1n zeros(1,length(x2n)-1)];
x2npad = [x2n zeros(1,length(x1n)-1)];
yn = ifft(fft(x1npad).*fft(x2npad));
figure(2);
stem(yn)