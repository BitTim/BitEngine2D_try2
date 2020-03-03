linux_ccfiles = $(shell ls src/Linux/ -I main.cc)

bin/Linux/test: src/Linux/main.cc $(linux_ccfiles)
	g++ -o $@ -lSDL2 src/Linux/main.cc $(linux_ccfiles)

runl: bin/Linux/test
	./bin/Linux/test

bin/Linux/debug: src/Linux/main.cc $(linux_ccfiles)
	g++ -g -o $@ -lSDL2 src/Linux/main.cc $(linux_ccfiles)

rundl: bin/Linux/debug
	./bin/Linux/debug

clean:
	rm bin/Linux/*
	rm bin/Windows/*
	rm log/*