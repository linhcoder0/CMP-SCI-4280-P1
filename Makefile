all:
	g++ -g -std=c++11 -o P0 P0.cpp tree.cpp 

clean:
	rm -f P0 *.o *.preorder *.postorder
