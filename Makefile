OFILES= camera.o gl_utils.o model.o

all: main

main: main.cpp $(OFILES)
	g++ main.cpp $(OFILES) -o main -lGL -lGLU -lglut

camera.o: camera.cpp
	g++ -c camera.cpp -o camera.o -lGL -lGLU -lglut

gl_utils.o: gl_utils.cpp
	g++ -c gl_utils.cpp -o gl_utils.o -lGL -lGLU -lglut

model.o: model.cpp
	g++ -c model.cpp -o model.o -lGL -lGLU -lglut

clean:
	rm -rf *o *gch main