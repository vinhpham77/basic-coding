var SV = {
	name: 'Vinh',
	age: 20,
	scream: function() {
		console.log('Yeah boiii');
	},
	introduce: function() {
		console.log(this.name);
		console.log(this.age);
	}
}

SV.scream();
SV.introduce();