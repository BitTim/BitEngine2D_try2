linux_ccfiles = $(shell find . -name \*.cc ! -path ./src/Linux/main.cc)

bin/Linux/test: src/Linux/main.cc $(linux_ccfiles)
	g++ -o $@ -lSDL2 -lSDL2_ttf -lSDL2_image src/Linux/main.cc $(linux_ccfiles)

runl: bin/Linux/test
	./bin/Linux/test

bin/Linux/debug: src/Linux/main.cc $(linux_ccfiles)
	g++ -g -o $@ -lSDL2 -lSDL2_ttf -lSDL2_image src/Linux/main.cc $(linux_ccfiles)

rundl: bin/Linux/debug
	./bin/Linux/debug

clean:
	rm -R bin/*
	rm log/*

	mkdir bin/Linux
	mkdir bin/Windows