CC=gcc
CFLAGS=-I
DEPS=comdef.h linkedList.h linkedListInt.h stackInt.h
TARGET_LL=test_ll
TARGET_STACK=test_stack
TARGET=$(TARGET_LL) $(TARGET_STACK)


stackInt.o: stackInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

test_stackInt.o: test_stackInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

linkedListInt.o: linkedListInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

test_linkedListInt.o: test_linkedListInt.c $(DEPS)
	@echo Compiling $< 
	$(CC) -c -o $@ $< $(CFLAGS).

$(TARGET_LL): linkedListInt.o test_linkedListInt.o
	@echo Linking OBJ Files[$^]
	$(CC) -o $@ $^
	@echo Build Successful. Executable Created - $(TARGET_LL) 

$(TARGET_STACK): stackInt.o test_stackInt.o
	@echo Linking OBJ Files[$^]
	$(CC) -o $@ $^
	@echo Build Successful. Executable Created - $(TARGET_STACK) 

clean:
	@echo Cleaning targets
	rm ./*.o ./$(TARGET)
