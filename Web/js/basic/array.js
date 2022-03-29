name = ['Vinh', 'Nam', 'Quốc', 'An'];

name.sort();
// name.sort(function(item1, item2){
// 	return item1.localeCompare(item2); 
// });

console.log(name);
var vinh = name.filter(function(item){
	return item === 'Vinh';
})

console.log(vinh);
