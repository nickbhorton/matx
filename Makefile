test: tests
	./tests

tests: include/matrix.h include/matx.h include/test/matrix.h
	g++ entry.cpp -DMATX_TEST -o tests

clean:
	rm -f tests

.PHONY: test clean
