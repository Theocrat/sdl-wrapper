main:
	g++ main.cc -o main `sdl2-config --cflags --libs`

remake:
	rm main
	g++ main.cc -o main `sdl2-config --cflags --libs`