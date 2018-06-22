const http = require('http');


const server = http.createServer(() => {
	console.log('I hear you, Thankyou for the request');

})

server.listen(3000);