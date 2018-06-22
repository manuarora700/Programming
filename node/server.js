const express = require('express');


const app = express();

app.get('/', (req,res) => {
	const user = {
		name: 'Sally',
		hobby: 'in my alley'
	}
	res.send(user);
})
app.listen(3000);