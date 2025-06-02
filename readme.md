# Make file compile including headers
g++ main.cpp -o main -Iinclude -Llib -lraylib -lGL -lX11 -lpthread -ldl
# copy headers to usr location
sudo cp raygui.h /usr/local/include/

# Not usefull xD
mv lib/raygui.h lib/raygui.c
gcc -o raygui.so lib/raygui.c -shared -fpic -DRAYGUI_IMPLEMENTATION -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
mv lib/raygui.c lib/raygui.h
