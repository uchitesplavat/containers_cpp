OUT_DIR = build
TEST = test

all: $(TEST)

$(TEST):
	$(MAKE) -C $(OUT_DIR) tests
	cd $(OUT_DIR) && ./tests

gcov_report:
	g++ --coverage test_vector.cc test_runner.cc -o tests -lgtest -pthread -lrt -lm -lsubunit -s
	./tests
	gcov tests-test_vector.gcda
	lcov -t "tests" -o tests.info -c -d ./ --no-external
	genhtml -o report tests.info
	xdg-open ./report/index.html

clean:
	rm -rf $(OUT_DIR)
	-rm -rf *.o && rm -rf *.gcno && rm -rf *.exec
	-rm -rf *.a && rm -rf *.gcda
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
