const express = require('express');
const bodyParser = require('body-parser');

const app = express();

app.use(bodyParser.urlencoded({extended: false}))
app.use(bodyParser.json());


app.get('/:id', (req,res) => {
	// console.log(req.query);
	//req.body
	// console.log(req.header);	
	console.log(req.params)
	res.send('getting root');
});

app.listen(3000);