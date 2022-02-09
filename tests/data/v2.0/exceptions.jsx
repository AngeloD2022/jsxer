throw new Error("test error throw")
throw new CustomErr("custom err throw")
try {
var x = "trytrytrytry";
} catch (e if e == "InvalidNameException") {
var x = "special catch";
} catch (e) {
var x = "all catch";
} finally {
var x = "finallyblock";
}