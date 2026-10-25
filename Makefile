all:
	g++ -g -std=c++11 -o P1 main.cpp scanner.cpp 

clean:
	rm -f P1 *.o *.preorder *.postorder
