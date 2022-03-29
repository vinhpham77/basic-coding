// // 1
// function sum(array) {
// 	var sum = 0;

// 	for (var i = 0; i < array.length; i++) {
// 		sum += array[i];
// 	}

// 	return sum;
// }

// function multiple(array) {
// 	var multiple = 1;

// 	for (var i = 0; i < array.length; i++) {
// 		multiple *= array[i];
// 	}

// 	return multiple;
// }

// var array = [3, 4, 1, 5];
// console.log(sum(array));
// console.log(multiple(array));

// 2
// function max(array) {
// 	var max = array.length > 0 ? array[0] : NaN;

// 	for (var i = 1; i < array.length; i++) {
// 		if (array[i] > max) {
// 			max = array[i];
// 		}
// 	}

// 	return max;
// }

// function min(array) {
// 	var min = array.length > 0 ? array[0] : NaN;

// 	for (var i = 1; i < array.length; i++) {
// 		if (array[i] < min) {
// 			min = array[i];
// 		}
// 	}

// 	return min;
// }

// var array = [4, 7, 2, -2];
// console.log(max(array));
// console.log(min(array));

// 3
function reverse(array) {
	var i = 0;
	var j = array.length - 1;
	var newArray = [];

	while (i < j) {
		newArray[j] = array[i];
		newArray[i] = array[j];
		i++;
		j++;
	}

	return newArray;
}

var array = [3, 5, 0, 7, 1];
console.log(reverse(array));