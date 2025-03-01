
build:
	@clang -std=c99 -o bin/vector main.c

run:build
	@./bin/vector

format:
	@find ./**.c ./**.h > .file-names
	@clang-format --style=file -i --files=.file-names

clean:
	@rm bin/**
