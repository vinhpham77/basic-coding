var array = [3, 5, 8, 10];
var student = {
	name: 'Vinh',
	age: 20,
	gender: 'male'
};

// break, continue

// while(conditions) {
// 	do something
// }

// do {
// 	do something
// } while (conditions);

for (var i = 0; i < array.length; i++) {
	console.log(array[i]);
}

for (var key in array) {
	console.log(array[key]);
}

for (var key in student) {
	console.log(student[key]);
}

for (var item of array) {
	console.log(item);
}

// DO NOT
// for (var item of student) {
// 	console.log(item);
// }
