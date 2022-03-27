var x = function () {
	console.log('abala');
}
x();

function y() {
	console.log('apolo');
}
y();

x = undefined;
if (x) {
	console.log('defined');
} else {
	console.log('undefined');
}

y = null; // same as y = 0 or y = NaN or y = ''
if (y) { 
	console.log('meaningful');
} else {
	console.log('meaningless');
}
