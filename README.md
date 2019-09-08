# Simple C++ Server/Client using Thrift
The project is compiled on an Ubuntu 18.04.<br>
The Thrift service has only one method hello..<br>
The Thrift generated code is in source/pkg/gen-cpp.<br>
The server and client code is in source/cmd/{helloserver, helloclient}.<br>
The needed libararies are in lib, so you can quick start using Thrift (compiled on Ubuntu 18.04 and I dont know if the compilation will work on another distro).<br>
The needed headers file are in include.<br>
The project use Googletest for testing.
## Project build
On Ubuntu, install C++ development packages. I use cmake and ninja to build my C++  projects<br>
The client and server are statically compiled.
Clone the repository and go inside the clone folder.
```bash
$ mkdir build
$ cd build
$ # if you want use make, run cmake ..
$ cmake -G Ninja ..
# run make instead of ninja
$ ninja
$ # run tests
$ ctest
```
## Build Docker images
You can make a Docker image for the server:
```bash
$ docker build -t helloserver:cxx -f Dockerfile.server .
$ docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
helloserver         cxx                 e5d84a5c11f1        4 seconds ago       2.45MB
```
You can make a Docker image for the client:
```bash
$ docker build -t helloclient:cxx -f Dockerfile.client .
$ docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED             SIZE
helloclient         cxx                 9d88c6f61ff5        11 seconds ago      2.31MB
helloserver         cxx                 e5d84a5c11f1        4 minutes ago       2.45MB
```
## Run the server and client
In a terminal, run the server from build/bin:
```bash
./helloserver
Starting the server...
```
In another terminal, run the client from build/bin:
```bash
./helloclient
Hello World!
```
in the server terminal:
```bash
Incoming connection
	SocketInfo: <Host: ::ffff:127.0.0.1 Port: 38892>
	PeerHost: localhost
	PeerAddress: ::ffff:127.0.0.1
	PeerPort: 38892
```
To use Docker images, the client and server code must be modified to use envorinment variables or any other method to find the server/client host and port instead pf localhost.<br>
If you deploy the server and client Docker images in a Kubernetes Pod, they can communicate using localhost.

