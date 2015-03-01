build:
	g++ *.cpp -o pong \
		-lSDL2 -lstdc++ \
		-std=c++11 \
		-D_GNU_SOURCE=1 -D_REENTRANT

run: build
	./pong
