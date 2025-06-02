default:
				g++ main.cpp -o main -Iinclude -Llib -lraylib -lGL -lX11 -lpthread -ldl
#				g++ $(wildcard *.cpp) -o main -Iinclude -Llib -lraylib -lopengl32 -lgdi32 -lwinmm
