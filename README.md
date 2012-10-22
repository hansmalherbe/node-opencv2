cv
==

Node.js bindings for OpenCV

Project has dependencies on OpenCV and boost. Modify to binding.gyp file to point to the relevant paths.

To build first do 

> node-gyp configure

then 

> node-gyp build

Currently only builds on Windows. Please help building out binding.gyp for other platforms.