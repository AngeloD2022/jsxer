var a = true;
switch(a) {
case "test1":
a = 5;
break ;
case "test2":
a = 10;
break ;
default:
a = 15;
break ;
}
switch(a) {
case "test3":
a = 33;
break ;
case "test4":
a = 55;
break ;
}
switch(a) {
case "test3":
case "test4":
a = 55;
break ;
case "test6":
case "test7":
a = 66;
break ;
}
switch(a) {
case "test3":
case "test4":
a = 55;
break ;
default:

}