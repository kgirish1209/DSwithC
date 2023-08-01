CC=gcc
CFLAGS=-I
DEPS=comdef.h linkedList.h linkedListInt.h
TARGET=test_ll

%.o: %.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

$(TARGET): linkedListInt.o test_linkedListInt.o
	@echo Linking OBJ Files[$^]
	$(CC) -o $@ $^
	@echo Build Successful. Executable Created - $(TARGET) 

clean:
	@echo Cleaning targets
	rm ./*.o ./$(TARGET)
