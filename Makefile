lab1:
	@g++ src/Lab\ work\ 1/main.cc -o test
	@./test

lab2-1:
	@g++ src/Lab\ work\ 2/test_for_BinaryTree.cc -o test
	@./test

lab2-2:
	@g++ src/Lab\ work\ 2/test_for_HashTable.cc src/Lab\ work\ 2/HashTable.cc -o test
	@./test

lab3:
	@g++ src/Lab\ work\ 3/KMP.cc -o test
	@./test

lab4:
	@g++ src/Lab\ work\ 4/SortFileWithTwoDeque.cc -o test
	@cp src/Lab\ work\ 4/input.txt .
	@./test
	@rm input.txt

lab5:
	@g++ src/Lab\ work\ 5/hilbertCurve.cc -o test -lsfml-graphics -lsfml-window -lsfml-system
	@./test