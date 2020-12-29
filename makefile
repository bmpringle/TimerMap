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