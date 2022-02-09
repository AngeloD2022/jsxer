loop1: for (var a = 0;a < 10; a += 1) {
if (a == 4) {
break loop1;
}
alert("a = " + a);
loop2: for (var b = 0;b < 10; b += 1) {
if (b == 3) {
continue loop2;
}
if (b == 6) {
continue loop1;
}
alert("b = " + b);
}
alert("finished");
}
block1: alert("Hello");
alert("World");
for (var a = 0;a < 10; a += 1) {
alert("a = " + a);
}