var assert = require('assert')
	, cv 

try {
	cv = require('./build/Release/opencv2')
} catch (e) {
	try {
		cv = require('./build/Debug/opencv2')
	} catch (e1) {
		throw e
	}
}

var mat = cv.createMat({ rows:50, cols:100 })

// // assert.equal('world', cv.hello())
// // console.log('hello() = ' + cv.hello())

cv.namedWindow('Hallo')
cv.imshow('Hallo', mat)

console.log(cv.testObjectProperties({ 
	int: -4,
	booltrue: true,
	boolfalse: false,
	boolobjtrue: new Boolean(false),
	boolobjfalse: new Boolean(),
	string: "abc",
	uint: 3141,
	number: 3.141,
	point: { x: -2, y: 1 },
	point2f: { x: -2.1, y: 1.1 },
	size: { width: 3, height: 7 },
	size2f: { width: 3.1, height: 7.2 },
	rect: { x: 1, y: 2, width: 3, height: 4 },
	range: { start: 1, end: 2 },
	rr: { angle: 1.23, center: { x: 2.23, y: 3.34 }, size: { width: 4.45, height: 5.65 }},
	vec: [ 1, 2, 3 ]
}))

mat = cv.imread('./test/Tulips.jpg')
cv.cvtColor(mat, mat)
// CV_RGB2YCrCb, CV_BGR2YCrCb, CV_BGR2HSV, CV_RGB2Lab, CV_BGR2Luv, CV_RGB2HLS, CV_BGR2HSV_FULL, cv.CV_RGB2YUV
cv.imshow('Hallo', mat)

cv.waitKey()