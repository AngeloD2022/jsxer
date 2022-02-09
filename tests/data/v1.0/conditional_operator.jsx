function () {
var a = true;
var b = a === "b" ? 2 : 5;
var c = BRIL.appVersion < 11 ? (eventObject = {}, eventObject.target = this) : 0;
}