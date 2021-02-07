edit fibonplot
x1 = [997 0 2002 7005 62059];
x2 = [0 999 2000 3000 7008];
x3 = [0 3005 1001 10011 13013];
x4 = [0 3006 3003 3001 9005];
hold on;
set(gca, 'Yscale', 'log');
plot(x1);
plot(x2);
plot(x3);
plot(x4);
lgd = legend('Naive Recursion', 'Bottom up', 'Closed form', 'Matrix representation form');
hold off