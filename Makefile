
all:
	g++ -std=c++11 -fPIC -Wall -fstack-protector-all -rdynamic -g -c *.cpp
	g++ -g -fstack-protector-all -rdynamic -o lift_manager *.o
	
clean:
	rm -rf *.o

superclean: clean
	rm -rf lift_manager

supermake: superclean all
	
