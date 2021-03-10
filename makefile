test:
	g++ -std=c++2a test.cpp lib/timerMapLib.a -o test
library:
	mkdir -p obj
	mkdir -p lib
	g++ -std=c++2a -c TimerMap.cpp -o  ./obj/TimerMap.o
	ar rvs ./lib/timerMapLib.a ./obj/TimerMap.o
clean: 
	rm -rf obj
	rm -rf lib
	rm test
library-cross:
	mkdir -p obj
	mkdir -p lib
	/usr/local/bin/x86_64-w64-mingw32-g++ -std=c++2a -c TimerMap.cpp -o  ./obj/TimerMap.o
	/usr/local/bin/x86_64-w64-mingw32-ar rvs ./lib/timerMapLib.lib ./obj/TimerMap.o
