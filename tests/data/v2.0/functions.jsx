var addCtor = new Function("firstFuncX", "firstFuncY", "return firstFuncX + firstFuncY");
var tCtor = addCtor(5656, 123124);
var addFuncExpr = function (sndFuncX, sndFuncY) {
return sndFuncX + sndFuncY;
};
var tFuncExpr = addFuncExpr(23123, 5345);
function addShorthand(thirdFuncX, thirdFuncY) {
return thirdFuncX + thirdFuncY;
}
var tShorthand = addShorthand(1, 2);
function subtract(fourthFuncX, fourthFuncY) {
return fourthFuncX - fourthFuncY;
}
var testo = subtract.length;
var test2 = subtract.getName(5);