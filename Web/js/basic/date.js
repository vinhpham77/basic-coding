var birthday = new Date('2002-12-10');
var current = new Date();
console.log(birthday);

birthday.setDate(birthday.getDate() + 1);

console.log(birthday);

console.log(birthday < current);