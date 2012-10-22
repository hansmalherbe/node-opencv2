var port = 1337
	, http = require('http')

http.createServer(function handleRequest(req, res) {
	res.writeHead(200, {'Content-Type': 'text/plain'})
	res.write('Hallo daar')
	res.end()
}).listen(port)

console.log('Listen on ' + port)