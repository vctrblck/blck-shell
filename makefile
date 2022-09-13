witsshell: 
	mkdir -p bin
	gcc src/*.c -o bin/witsshell

clean:
	rm -rf bin