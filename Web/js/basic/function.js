function sum(a, b) {
    return a + b;
}

function inform() {
    console.log('Yeah');
}

var a = 2;
var b = 4;

function abala() {
	a++;
}

[a, b] = [b, a];


console.log(sum(2, 3));
abala();
console.log(a, b);