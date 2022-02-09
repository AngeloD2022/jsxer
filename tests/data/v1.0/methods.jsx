function px() {
return this.prefix + "X";
}
function Foo(yz) {
this.prefix = "a-";
if (yz > 0) {
this.pyz = function () {
return this.prefix + "Y";
};
} else {
this.pyz = function () {
return this.prefix + "Z";
};
}
this.m1 = px;
}
var foo1 = new Foo(1);
var foo2 = new Foo(0);
foo2.prefix = "b-";
alert("foo1/2 " + foo1.pyz() + foo2.pyz());
foo1.m3 = px;
var baz = {
prefix: "c-"
};
baz.m4 = px;
alert("m1/m3/m4 " + foo1.m1() + foo1.m3() + baz.m4());
foo1.m2();