CFLAGS = -std=c99 -Wall -pedantic -Iinclude
SOURCES = $(wildcard src/*.c)
TARGET  = lib/libeuler.a

build: $(TARGET)

update:
	@ruby generate-symlinks.rb

$(TARGET): $(SOURCES:%.c=%.o)
	ar cr $@ $^
	ranlib $@

clean:
	$(RM) -rf src/*.o
	$(RM) $(TARGET)

.PHONY: build update clean
